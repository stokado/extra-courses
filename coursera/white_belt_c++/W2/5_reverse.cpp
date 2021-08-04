#include <vector>
#include <iostream>

using namespace std;

void Reverse(vector<int>& v)
{
    for (int i = 0; i < v.size() / 2; i++)
    {
        int temp = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = temp;
    }
}

int main()
{
    vector <int> v = {1, 5, 3, 4, 2, 80};
    Reverse(v);
    for (auto now : v)
        cout << now;
    return 0;
}