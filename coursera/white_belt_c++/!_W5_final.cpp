#include <iostream>
#include <exception>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Date
{
public:
    Date(int new_year = 0, int new_month = 0, int new_day = 0)
    {
        year = new_year;
        month = new_month;
        day = new_day;
    };
    void SetMonth(stringstream& stream)
    {
        if (stream.peek() > '0' && stream.peek() <= '9')
        {
            int new_month;
            stream >> new_month;
            if (new_month < 1 || new_month > 12)
            {
                stringstream ss;
                ss << "Month value is invalid: " << new_month;
                throw runtime_error(ss.str());
            }
            else
            {
                month = new_month;
            }
        }
        else
        {
            string MONTH;
            stream >> MONTH;
            throw invalid_argument("Wrong month format: " + MONTH);
        }
    };
    void SetDay(stringstream& stream)
    {
        if (stream.peek() > '0' && stream.peek() <= '9')
        {
            int new_day;
            stream >> new_day;
            if (new_day < 1 || new_day > 31)
            {
                stringstream ss;
                ss << "Day value is invalid: " << new_day;
                throw runtime_error(ss.str());
            }
            else
            {
                day = new_day;
            }
        }
        else
        {
            string DAY;
            stream >> DAY;
            throw invalid_argument("Wrong day format: " + DAY);
        }
    };
    int year;
    int month;
    int day;

};



class DataBase
{
public:
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

    void Find(const string& date)
    {
        vector<string> events_in_day = date_event[date];
        sort(begin(events_in_day), end(events_in_day));
        for (const auto& i : events_in_day)
        {
            cout << i << endl;
        }
    }

private:
    map <string, vector<string>> date_event;
};


string EnsureCommand(stringstream& stream)
{
    string cmd;
    stream >> cmd;
    if (cmd == "Add" || cmd == "Del" || cmd == "Find" || cmd == "Print")
        return cmd;
    else
        throw invalid_argument("Unknown command: " + cmd);
}

string EnsureDate(stringstream& stream)
{
    stream.ignore(1);
    if (stream.peek() >= '0' && stream.peek() <= '9' || stream.peek() == '-')
    {
        Date date;
        stream >> date.year;
        if (stream.peek() != '-')
        {
            throw()

        }
        stream.ignore(1);

        date.SetMonth(stream);
        stream.ignore(1);
        date.SetDay(stream);

        return to_string(date.year) + '-' + to_string(date.month) + '-' + to_string(date.day);
    }
    else
    {
        string DATE;
        stream >> DATE;
        throw invalid_argument("Wrong date format: " + DATE);
    } 
}

Date ParseDate(const string& s)
{
    Date date;
    return date;
}

int main()
{
    DataBase data_base;
    string next_line;
    while (getline(cin, next_line))
    {
        if (next_line == "")                // Если на входе пустая строка - игнорируем
        {
        }
        else
        {
            stringstream ss(next_line);     // Создаём строковый поток, чтобы считывать слова по одному
            try                             // Проверяем правильная ли команда                      
            {
                string cmd = EnsureCommand(ss);
                if (cmd == "Add" || cmd == "Del" || cmd == "Find")  // Если команда правильная, то попадаем сюда
                {
                    try                     // Проверяем правильная ли дата для тех команд, где дата необходима
                    {
                        string date = EnsureDate(ss);
                        if (cmd == "Add")
                        {
                            string event;
                            ss >> event;
                            data_base.AddEvent(date, event);
                        }
                        else if (cmd == "Del")
                        {
                            string event;
                            ss >> event;
                            if (event != "")
                            {
                                data_base.DeleteEvent(date, event);
                            }
                            else
                            {
                                data_base.DeleteAllEvents(date);
                            }
                        }
                        else
                            data_base.Find(date);
                    }
                    catch(exception& ex)    // была введена неверная дата
                    {
                        cout << ex.what();
                        return 2;
                    }
                    
                }
                else
                {
                    data_base.Print();
                }
            }
            catch(exception& ex)            // была введена неверная команда
            {
                cout << ex.what();
                return 1;
            }
            
        }
    }
    return 0;
}