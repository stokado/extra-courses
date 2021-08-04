#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
0    1   january     31
1    2   february    28
2    3   march       31
3    4   april       30
4    5   may         31
5    6   june        30
6    7   july        31
7    8   august      31
8    9   september   30
9    10  octobet     31
10   11  november    30
11   12  december    31    
*/

int getDays(const int& a)
{
    if (a == 1)
        return 28;
    else if(a == 3 || a == 5 || a == 8 || a == 10)
        return 30;
    else
        return 31;
}

void addPlan(vector <vector <string>>& month)
{
    int day;
    cin >> day;
    string plan;
    cin >> plan;
    month[day - 1].push_back(plan);
}

void dumpPlans(const vector<vector<string>>& month)
{
    int day;
    cin >> day;
    if (month[day - 1].size())
    {
        cout << month[day - 1].size();
        for (auto plan : month[day - 1])
            cout << " " << plan;
    }
    else
    {
        cout << 0;
    }
    cout << endl;
}

void nextMonth(int& curMonth, vector<vector <string>>& concerns)
{
    int prevDays = getDays(curMonth);
    if (curMonth == 11)
    { 
        curMonth = 0;
    }
    else
    {
        curMonth++;
    }
    int curDays = getDays(curMonth);
    vector <vector < string>> prevMonth = concerns;
    if (prevDays < curDays)
    {
        concerns.resize(curDays);
    }
    else
    {
        concerns.resize(curDays);
        for (int i = curDays; i < prevDays; i++)
        {
            concerns[concerns.size() - 1].insert(concerns[concerns.size() - 1].end(), prevMonth[i].begin(), prevMonth[i].end());
        }
    }
}

int main()
{
    int n;
    cin >> n;    
    int curMonth = 0;
    vector <vector<string>> concerns(getDays(curMonth));
    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD")
            addPlan(concerns);
        else if (cmd == "DUMP")
            dumpPlans(concerns);
        else
            nextMonth(curMonth, concerns);
    }
    return 0;
}