#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map <string, string> countries;

    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "CHANGE_CAPITAL")
        {
            string country, capital;
            cin >> country >> capital;
            if (countries.find(country) == countries.end())
            {
                countries[country] = capital;
                cout << "Introduce new country " << country << " with capital " << capital << endl;
            }
            else if (countries[country] == capital)
            {
                cout << "Country " << country << " hasn't changed its capital" << endl;
            }
            else
            {
                cout << "Country " << country << " has changed its capital from " << countries[country] << " to " << capital << endl;
                countries[country] = capital;
            }
        }
        else if (cmd == "RENAME")
        {
            string oldName, newName;
            cin >> oldName >> newName;
            if (oldName == newName || countries.find(oldName) == countries.end() || countries.find(newName) != countries.end())
            {
                cout << "Incorrect rename, skip" << endl;
            }
            else
            {
                cout << "Country " << oldName << " with capital " << countries[oldName] << " has been renamed to " << newName << endl;
                countries[newName] = countries[oldName];
                countries.erase(oldName);
            }
        }
        else if (cmd == "ABOUT")
        {
            string country;
            cin >> country;
            if (countries.find(country) == countries.end())
            {
                cout << "Country " << country << " doesn't exist" << endl;
            }
            else
                cout << "Country " << country << " has capital " << countries[country] << endl;
        }
        else
        {
            if (countries.size() == 0)
            {
                cout << "There are no countries in the world" << endl;
            }
            else
            {
                for (const auto& item : countries)
                {
                    cout << item.first << "/" << item.second << " ";
                }
                cout << endl;
            }
        }        
    }
    return 0;
}