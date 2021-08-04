#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    int n = 0, m = 0;
    ifstream input("input.txt");
    input >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int value = 0;
        for (int j = 0; j < m; j++)
        {
            if (j != 0)
            {
                cout << ' ';
            }
            input >> value;
            input.ignore(1);
            cout << setw(10) << value;
        }
        if (i != n - 1)
            cout << endl;
    }
    return 0;
}