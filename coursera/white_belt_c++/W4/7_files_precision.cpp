#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream input("input.txt");
    if (input)
    {
        double x = 0;
        cout << fixed << setprecision(3);
        while (input >> x)
        {
            cout << x << endl;
        }
    }
    return 0;
}