#include <string>
#include <iostream>
#include <map>


using namespace std;

struct Person_name
{
    string FirstName = "";
    string LastName = ""; 
};

class Person {
public:


    void ChangeFirstName(int year, const string& first_name) 
    {
        if (full_name.count(year) == 0)
            full_name[year].LastName = "";
        full_name[year].FirstName = first_name;
    }

    void ChangeLastName(int year, const string& last_name) 
    {
        if (full_name.count(year) == 0)
            full_name[year].FirstName = "";
        full_name[year].LastName = last_name;
    }

    string GetFullName(int year) 
    {
        Person_name answer;
        if (full_name.size())
        {
            for (const auto& item : full_name)
            {
                if (year < item.first)
                    return "Incognito";
                break;
            }
            string fn = "";
            string ln = "";
            for (const auto& item : full_name)
            {
                if (item.first <= year && item.second.FirstName != "")
                    fn = item.second.FirstName;
                if (item.first <= year && item.second.LastName != "")
                    ln = item.second.LastName;
            }
            if (fn == "")
            {
                return ln + " with unknown first name";
            }
            else if (ln == "")
            {
                return fn + " with unknown last name";
            }
            else{
                return fn + " " + ln;
            }
        }
        else
            return "Incognito";
    }

private:
    map <int, Person_name> full_name;
};

int main()
{
    Person person;
  
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    // Person person; 

    // int year = 1;
    // person.ChangeFirstName(year, std::to_string(year)+"_first");
    // person.ChangeLastName(year, std::to_string(year)+"_last");
    // std::cout << "year: " << year << '\n';
    // std::cout << person.GetFullName(year) << '\n';

    // year = 2;
    // person.ChangeFirstName(year, std::to_string(year)+"_first");
    // person.ChangeLastName(year, std::to_string(year)+"_last");
    // std::cout << "year: " << year << '\n';
    // std::cout << person.GetFullName(year) << '\n';

    // year = 3;
    // person.ChangeFirstName(year, std::to_string(2)+"_first");
    // person.ChangeLastName(year, std::to_string(2)+"_last");
    // std::cout << "year: " << year << '\n';
    // std::cout << person.GetFullName(year) << '\n';

    return 0;
}