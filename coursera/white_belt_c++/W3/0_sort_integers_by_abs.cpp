#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> v;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        v.push_back(val);
    }
    sort(begin(v), end(v), [] (const int& x, const int& y) {return abs(x) < abs(y);});
    for (const auto& i : v)
    {
        cout << i << " ";
    }
    return 0;
}