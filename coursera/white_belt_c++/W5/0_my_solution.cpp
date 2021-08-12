#include <iostream>
#include <exception>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <set>

using namespace std;

struct Date{
    public:
    Date(int new_year, int new_month, int new_day){
        if (new_month < 1 || new_month > 12)
        {
            throw out_of_range("Month value is invalid: " + to_string(new_month));
        } else if (new_day < 1 || new_day > 31){
            throw out_of_range("Day value is invalid: " + to_string(new_day));
        }
        year = new_year;
        month = new_month;
        day = new_day;
    };

    int GetYear() const{
        return year;
    }

    int GetMonth() const{
        return month;
    }

    int GetDay() const{
        return day;
    }

    private:
    int year;
    int month;
    int day;
};

ostream& operator << (ostream& stream, const Date& date){
    stream << setfill('0') << setw(4) << to_string(date.GetYear()) << '-';
    stream << setfill('0') << setw(2) << to_string(date.GetMonth()) << '-';
    stream << setfill('0') << setw(2) << to_string(date.GetDay());
    return stream;
}

bool operator < (const Date& lhs, const Date& rhs){
    if (lhs.GetYear() != rhs.GetYear()){
        return lhs.GetYear() < rhs.GetYear();
    } else if (lhs.GetMonth() != rhs.GetMonth()){
        return lhs.GetMonth() < rhs.GetMonth();
    } else{
        return lhs.GetDay() < rhs.GetDay();
    }
}


class DataBase
{
public:

    void AddEvent(const Date& date, const string& event)
    {
       date_event[date].insert(event);
    };

    void DeleteEvent(const Date& date, const string& event)
    {
       if (date_event.count(date) > 0 && date_event.at(date).count(event) > 0){
           date_event[date].erase(event);
           cout << "Deleted successfully\n";
       }
       else{
           cout << "Event not found\n";
       }
    };

    void DeleteAllEvents(const Date& date)
    {
        int size = 0;
        if (date_event.count(date) != 0){
            size = date_event.at(date).size();
            date_event.erase(date);
        }
        cout << "Deleted " << size << " events\n";
    };

    void Find(const Date& date)
    {
        if (date_event.count(date)){
            for (const auto& item : date_event.at(date))
            {
                cout << item << endl;
            }
        }
    };

    void Print()
    {
        for(const auto& item : date_event){
            for (const auto& event : item.second){
                cout << item.first << ' ' << event << endl;
            }
        }
    };

private:
    map <Date, set<string>> date_event;
};


Date ParseDate(const string& date)
{
    stringstream date_stream(date);
    int y, m, d;
    bool ok = true;
    ok = ok && date_stream >> y;
    ok = ok && date_stream.peek() == '-';
    date_stream.ignore(1);

    ok = ok && date_stream >> m;
    ok = ok && date_stream.peek() == '-';
    date_stream.ignore(1);

    ok = ok && date_stream >> d;
    ok = ok && date_stream.eof();

    if (!ok){
        throw logic_error("Wrong date format: " + date);
    }
    return Date(y, m, d);
}



int main()
{
    try{
        DataBase calendar;
        string new_line;
        while(getline(cin, new_line)){
            if (new_line != ""){
                stringstream ss(new_line);
                string cmd;
                ss >> cmd;
                if (cmd == "Add" || cmd == "Del" || cmd == "Find"){
                    string date_str;
                    ss >> date_str;
                    Date date = ParseDate(date_str);
                    if (cmd == "Add"){
                        string event;
                        ss >> event;
                        calendar.AddEvent(date, event);
                    }
                    else if (cmd == "Del"){
                        string event;
                        ss >> event;
                        if (event == ""){
                            calendar.DeleteAllEvents(date);
                        }
                        else{
                            calendar.DeleteEvent(date, event);
                        }
                    }
                    else{
                        calendar.Find(date);
                    }
                }
                else if (cmd == "Print"){
                    calendar.Print();
                }
                else{
                    throw invalid_argument("Unknown command: " + cmd);
                }
            }
        }
    }
    catch (exception& ex){
        cout << ex.what();
        return 1;
    }
    return 0;
}