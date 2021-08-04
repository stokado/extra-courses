#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector <bool> is_worried;
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "WORRY_COUNT")
        {
            int counter = 0;
            for (auto now : is_worried)
                if (now)
                    counter++;
            cout << counter << endl;
        }
        else
        {
            int k;
            cin >> k;
            if (cmd == "COME")
            {
                if (k > 0)
                    for (int i = 0; i < k; i++)
                        is_worried.push_back(0);
                else
                    for (int i = 0; i < abs(k); i++)
                        is_worried.erase(is_worried.end());
            }
            else if (cmd == "QUIET")
                is_worried[k] = false;
            else
                is_worried[k] = true;
        }
    }
    return 0;
}