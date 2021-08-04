#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsPalindrom(string);
vector <string> PalindromFilter(vector <string>, int );

bool IsPalindrom(string word)
{
    for (int i = 0; i < word.size() / 2; i++)
    {
        if (word[i] != word[word.size()- 1 - i])
            return false;
    }
    return true;
}

vector <string> PalindromFilter(vector <string> words, int minLength)
{
    vector <string> out;
    for (auto cur : words)
    {
        if (cur.size() >= minLength && IsPalindrom(cur))
            out.push_back(cur);
    }
    return out;
}


int main()
{
    vector <string> words;
    int minLength;
    int n;
    cin >> n >> minLength;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }
    words = PalindromFilter(words, minLength);
    if (words.size() == 1)
        cout << words.front();
    else{
        for (int i = 0; i < words.size(); i++)
        {
            if (i == words.size() - 1)
            {
                cout << words[i];
                break;
            }
            cout << words[i] << ", "; 
        }
    }
    return 0;
}