
#include <iostream>
#include <string>

using namespace std;


/*
*   alpha beta gamma
*   beta alpha gamma
*   beta gamma alpha
*
*   alpha beta alpha
*   beta  alpha alpha
*   alpha alpha beta
*
*   gamma gamma gamma
*/

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    if (a <= b && a <= c)
        cout << a;
    else if (b <= a && b <= c)
        cout << b;
    else
        cout << c;
    return 0;
}