#include <iostream>

struct Day{
    int value;
    explicit Day(int new_value)
    {
        value = new_value;
    }
};

struct Month{
    int value;
    explicit Month(int new_value)
    {
        value = new_value;
    }
};

struct Year{
    int value;
    explicit Year(int new_value)
    {
        value = new_value;
    }
};

using namespace std;

struct Date{
    int day;
    int month;
    int year;

    Date(Day new_day, Month new_month, Year new_year)
    {
        day = new_day.value;
        month = new_month.value;
        year = new_year.value;
    };
};

void PrintDate (const Date& date)
{
    cout << date.day << "." << date.month << "." << date.year << endl;
}

int main() 
{
    Date date = {Day(10), Month(11), Year(12)};
    PrintDate(date);
    return 0;
}