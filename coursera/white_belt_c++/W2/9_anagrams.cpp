#include <map>
#include <iostream>
#include <string>

using namespace std;

//string isAnagram(const map<char, int>& map1, const map<char, int>& map2)
//{
//    string answer = "YES";
//    for (const auto& item : map1)
//    {
//        if (item.second == map2.count(item.first))
//            continue;
//        else
//        {
//            answer = "NO";
//            break;
//        }
//    }
//    return answer;
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        map <char, int> chars1;
//        map <char, int> chars2;
//        string word1, word2;
//        cin >> word1 >> word2;
//        for (const char& now : word1)
//            chars1[now]++;
//        for (const char& now : word2)
//            chars2[now]++;
//        cout << isAnagram(chars1, chars2) << endl;
//    }
//    return 0;
//}

map <char, int> BuildCharCounters(const string& word)
{
    map <char, int> counters;
    for (char c : word)
        counters[c]++;
    return counters;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        string word1, word2;
        cin >> word1 >> word2;
        if (BuildCharCounters(word1) == BuildCharCounters(word2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}