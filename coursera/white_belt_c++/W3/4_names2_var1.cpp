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

string GetPrevName(const map<int, string>& names, int year)
{
    string cur_name = FindName(names, year);
    if (cur_name == "")
        return "";
    vector <string> prev_names;
    for (const auto& item : names)
    {
        if (year > item.first)
            prev_names.push_back(item.second);
    }
    reverse(begin(prev_names), end(prev_names));
    for (auto& item : prev_names)
    {
        if (item == cur_name)
            item.erase();
        else{
            cur_name = item;
        }
    }
    if (prev_names.size())
    {
        if (prev_names.size() > 1)
        {
            string answer;
            answer += '(';
            for (int i = 0; i < prev_names.size(); i++)
            {
                if (i == prev_names.size() - 1)
                {
                    answer += prev_names[i] + ')';
                }
                else if (prev_names[i] != "")
                {
                    answer += prev_names[i] + ", ";
                }
            }
            if (answer == "()")
                return "";
            else
                return answer;
        }
        else if (prev_names[0] != "")
            return "(" + prev_names[0] + ")";
    }
    return "";
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
            if (prev_first_names != "")
                return first_name + ' ' + prev_first_names + " with unknown last name";
            else
                return first_name + " with unknown last name";
        }
        else if (first_name.empty())
        {
            if (prev_last_names != "")
                return last_name + ' ' + prev_last_names + " with unknown first name";
            else
                return last_name + " with unknown first name";
        }
        else if (prev_first_names == "" && prev_last_names == "")
        {
            return first_name + " " + last_name;
        }
        else if (prev_first_names == "")
        {
            return first_name + " " + last_name + " " + prev_last_names;
        }
        else if (prev_last_names == "")
        {
            return first_name + " " + prev_first_names + " " + last_name;
        }
        else
        {
            return first_name + " " + prev_first_names + " " + last_name + " " + prev_last_names;
        }
    }

private:
    map <int, string> first_names;
    map <int, string> last_names;
};

int main() {
    Person person;
    
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
      cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
      cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
      cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;
    
    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;
    
    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
      cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;
    
    return 0;
}
