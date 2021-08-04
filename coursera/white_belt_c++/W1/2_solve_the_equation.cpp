#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    if (!a)
    {
        if (!b)
            return 0;
        double root;
        root = -c / b;
        cout << root;
    }
    else
    {
        double D = b * b - 4 * a * c;
        if (D >= 0)
        {
            double root1;
            root1 = ((-b + sqrt(D)) / (2 * a));
            if (D > 0)
            {
                double root2;
                root2 = ((-b - sqrt(D)) / (2 * a));
                if (root1 < root2)
                {
                    double temp = root1;
                    root1 = root2;
                    root2 = temp;
                }
                cout << root1 << " " << root2;
                return 0;
            }
            cout << root1;
        }
        else
            return 0;
    }
    return 0;
}