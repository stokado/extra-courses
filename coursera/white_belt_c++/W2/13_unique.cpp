#include <set>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set <string> words;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        words.insert(line);
    }
    cout << words.size();
    return 0;
}