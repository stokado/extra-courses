#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <string> words;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        words.push_back(line);
    }

    sort(begin(words), end(words), [] (string l, string r) {
        for (auto& ch : l)
            ch = tolower(ch);
        for (auto& ch : r)
            ch = tolower(ch);
        return l < r;
    });

    for (const auto& i : words)
    {
        cout << i << " ";
    }
    return 0;
}