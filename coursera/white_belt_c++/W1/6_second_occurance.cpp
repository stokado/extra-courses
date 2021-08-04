#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    cin >> word;
    int ffound = -2;
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == 'f')
            ffound++;
        if (ffound == 0)
        {
            ffound = i;
            break;
        }   
    }
    cout << ffound;
    return 0;
}
