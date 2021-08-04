#include <iostream>

using namespace std;

void UpdateIfGreater(const int a, int& b)
{
    if (b < a)
        b = a;
}

int main() 
{
    int a, b;
    cin >> a >> b;
    UpdateIfGreater(a, b);
    cout << b << endl;
    UpdateIfGreater(15, b);
    cout << b << endl;
    return 0;
}
