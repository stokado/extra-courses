#include <set>
#include <map>
#include <iostream>
#include <string>

using namespace std;
 
int main()
{
    int q;
    cin >> q;

    map <string, set <string>> synonyms;

    for (int i = 0; i < q; i++)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD")
        {
            string word1, word2;
            cin >> word1 >> word2;
            synonyms[word1].insert(word2);
            synonyms[word2].insert(word1);
        }
        else if (cmd == "COUNT")
        {
            string word;
            cin >> word;
            if (synonyms.count(word))
                cout << synonyms[word].size() << endl;
            else
                cout << 0 << endl;
        }
        else if (cmd == "CHECK")
        {
            string word1, word2;
            cin >> word1 >> word2;
            if (synonyms[word1].find(word2) != synonyms[word1].end() || synonyms[word2].find(word1) != synonyms[word2].end())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }    
    return 0;
}