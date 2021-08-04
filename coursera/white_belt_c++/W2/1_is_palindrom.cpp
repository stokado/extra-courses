#include <string>
#include <iostream>
using namespace std;

bool IsPalindrom(string word)
{
    for (int i = 0; i < word.size() / 2; i++)
    {
        if (word[i] != word[word.size()- 1 - i])
            return false;
    }
    return true;
}

int main()
{
    string w;
    cin >> w;
    cout << IsPalindrom(w);
    return 0;
}