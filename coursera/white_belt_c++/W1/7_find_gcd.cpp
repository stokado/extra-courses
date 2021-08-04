#include <iostream>

using namespace std;



int main()
{
    int a, b;
    cin >> a >> b;
    if (b > a)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    while(true)
    {
        if (a % b == 0)
        {
            cout << b;
            return 0;
        }
        else
        {
            a %= b;
            int temp = b;
            b = a;
            a = temp;
        }
    }
    return 0;
}