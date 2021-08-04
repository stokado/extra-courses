#include <vector>
#include <iostream>

using namespace std;

vector<int> Reversed(const vector<int>& v)
{
    vector<int> rev;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        rev.push_back(v[i]);
    }
    return rev;
}

int main()
{
    vector <int> v = {1, 5, 3, 4, 2, 80};
    vector <int> rev = Reversed(v);
    for (auto now : rev)
        cout << now;
    return 0;
}