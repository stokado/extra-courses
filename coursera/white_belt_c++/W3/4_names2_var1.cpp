#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

string FindName(const map <int, string>& names, int year)
{
    string name;

    for (const auto& i : names)
    {
        if (i.first <= year)
        {
            name = i.second;
        }
        else
            break;
    }
    return name;
}

vector <string> Form_Names_History(const map<int, string>& names, int year)
{

}

string GetPrevName(const map<int, string>& names, int year)
{
    vector <string> prev_names;
    string name = "";
    for (const auto& i : names)
    {
        if (i.first < year && i.second != name)
        {
            prev_names.push_back(i.second);
        }
        name = i.second;
    }
    string prev_name = "";
    if (prev_names.size())
    {
        prev_name += " (";
        reverse(begin(prev_names), end(prev_names));
        if ( prev_names.size() > 1)
        {
            for (const auto& item : prev_names)
            {
                prev_name += item + ", ";
            }
        }
        prev_name += ")";
    }
    
    return prev_name;
}

// пройти по всему словарю и проверить если год текуший меньше заданного то выдёргивать

class Person{    
public:

    // добавить факт изменения имени на first_name в год year
    void ChangeFirstName(int year, const string& first_name) 
    {
        first_names[year] = first_name;
    }

    // добавить факт изменения фамилии на last_name в год year
    void ChangeLastName(int year, const string& last_name) 
    {
        last_names[year] = last_name;
    }

    // получить имя и фамилию по состоянию на конец года year
    string GetFullName(int year)
    {
        string first_name = FindName(first_names, year);
        string last_name = FindName(last_names, year);

        if (first_name.empty() && last_name.empty())
        {
            return "Incognito";
        }
        else if (last_name.empty())
        {
            return first_name + " with unknown last name";
        }
        else if (first_name.empty())
        {
            return last_name + " with unknown first name";
        }
        else
            return first_name + " " + last_name;

    }

    // получить все имена и фамилии по состоянию на конец года year
    string GetFullNameWithHistory(int year)
    {
        string first_name = FindName(first_names, year);
        string last_name = FindName(last_names, year);

        string prev_first_names = GetPrevName(first_names, year);
        string prev_last_names = GetPrevName(last_names, year);

        if (first_name.empty() && last_name.empty())
        {
            return "Incognito";
        }
        else if (last_name.empty())
        {
            return first_name + prev_first_names + " with unknown last name";
        }
        else if (first_name.empty())
        {
            return last_name + prev_last_names + " with unknown first name";
        }
        else
            return first_name + " " + prev_first_names + " " + last_name + " " + prev_last_names;    
    }

private:
    map <int, string> first_names;
    map <int, string> last_names;
};

int main()
{    
    Person person;  
    person.ChangeFirstName(1900, "Eugene");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeLastName(1930, "Sokolov");
    cout << person.GetFullNameWithHistory(1940) << endl;
    return 0;
}