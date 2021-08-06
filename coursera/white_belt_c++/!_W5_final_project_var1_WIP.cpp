#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iomanip>

using namespace std;

struct Date
{
public:
    void SetMonth(int value)
    {
        if (value < 1 || value > 12)
        {
            stringstream ss;
            ss << "Month value is invalid: " << value;
            throw runtime_error(ss.str());
        }
        else
        {
            month = value;
        }
    };
    void SetDay(int value)
    {
        if (value < 1 || value > 31)
        {
            stringstream ss;
            ss << "Day value is invalid: " << value;
            throw runtime_error(ss.str());
        }
        else
        {
            day = value;
        }
    };

    int year = 0;
    int month = 0;
    int day = 0;

};

class Calendar
{
public:
    void AddEvent(const string& date, const string& event)
    {
        bool found = false;
        for(auto& item : date_event[date])
        {
            if (item == event)
            {
                found = true;
                break;
            }
        }
        if (!found)
            date_event[date].push_back(event);
    };
    void DeleteEvent(const string& date, const string& event)
    {
        if (date_event.find(date) != date_event.end())
        {
            bool deleted = false;
            for (int i = 0; i < date_event[date][i].size() - 1; i++)
            {
                if (date_event[date][i] == event)
                {
                    date_event[date][i].erase();
                    deleted = true;
                    break;
                }
            }
            if (deleted)
            {
                cout << "Deleted successfully\n";
            }
            else
                cout << "Event not found\n";
        }
        else
            cout << "Event not found\n";
    };
    void DeleteAllEvents(const string& date)
    {
        int num_of_events = date_event[date].size();
        date_event[date].clear();
        cout << "Deleted " << num_of_events << " events\n";
    };
    void Print()
    {
        for (const auto& item : date_event)
        {
            for (const auto& event : item.second)
            {
                stringstream ss(item.first);
                Date date;
                ss >> date.year;
                ss.ignore(1);
                ss >> date.month;
                ss.ignore(1);
                ss >> date.day;
                cout << setw(4) << setfill('0') << date.year << '-'
                    << setw(2) << setfill('0') << date.month << '-'
                    << setw(2) << setfill('0') << date.day << " " << event << endl;
            }
        }
    };
    void Find(const string& date)
    {
        vector<string> events_in_day = date_event[date];
        sort(begin(events_in_day), end(events_in_day));
        for (const auto& i : events_in_day)
        {
            cout << i << endl;
        }
    };
private:
    map<string, vector<string>> date_event;
};

// Добавление события                           -   Add     Дата Событие    ok
// Удаление события                             -   Del     Дата Событие    ok
// Удаления всех событий за конкретную дату     -   Del     Дата            ok
// Поиск событий за конкретную дату             -   Find    Дата            ok
// Печать всех событый за все даты              -   Print                   fix format


// Fix try catch for data input format

string EnsureCommand(stringstream& stream)
{
    string cmd;
    stream >> cmd;
    if (cmd == "Add" || cmd == "Del" || cmd == "Find" || cmd == "Print")
    {
        return cmd;
    }
    else
        throw runtime_error("Unknown command: " + cmd);
}

void EnsureNextSymbolAndSkip(stringstream& stream)
{
    if (stream.peek() != '-')
    {
        stringstream ss;
        string error;
        stream >> error;
        ss << "Wrong date format: " << error;
        throw runtime_error(ss.str());
    }
    stream.ignore(1);
}

string ParseDate(stringstream& stream)
{
    string date_str;
    Date date;
    stream >> date.year;
    EnsureNextSymbolAndSkip(stream);
    int value = 0;
    stream >> value;
    date.SetMonth(value);
    EnsureNextSymbolAndSkip(stream);
    stream >> value;
    date.SetDay(value);
    date_str = to_string(date.year) + '-' + to_string(date.month) + '-' + to_string(date.day);
    return date_str;
}

int main()
{
    Calendar calendar;
    string line;
    while (getline(cin, line))
    {
        if (line == "")
        {
        }
        else
        {
            stringstream test(line);
            try
            {
                string cmd = EnsureCommand(test);
                if (cmd == "Add" || cmd == "Del" || cmd == "Find")
                {
                    try
                    {
                        string date = ParseDate(test);
                        if (cmd == "Add")
                        {
                            string event;
                            test >> event;
                            calendar.AddEvent(date, event);
                        }
                        else if (cmd == "Del")
                        {
                            string event;
                            test >> event;
                            if (event != "")
                                calendar.DeleteEvent(date, event);
                            else
                                calendar.DeleteAllEvents(date);
                        }
                        else if (cmd == "Find")
                        {
                            calendar.Find(date);
                        }
                    }
                    catch(exception& ex)
                    {
                        cout << ex.what() << '\n';
                        return 1;
                    }

                }
                else
                {
                    calendar.Print();
                }
            }
            catch(exception& ex)
            {
                cout << ex.what() << endl;
                return 2;
            }       
        }
    }
    return 0;
}