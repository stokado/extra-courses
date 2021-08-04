#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> b;
    while(n >= 1)
    {
        b.push_back(n % 2);
        n /= 2;
    }
    for (int i = b.size(); i > 0; i--)
        cout << b[i - 1];
    return 0;
}
