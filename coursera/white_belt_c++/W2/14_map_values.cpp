#include <set>
#include <map>
#include <iostream>

using namespace std;

set <string> BuildMapValuesSet(const map <int, string>& m)
{
    set<string> answer;
    for (const auto& now : m)
    {
        answer.insert(now.second);
    }
    return answer;
}

// int main()
// {
//     map <int, string> m;
//     m = {
//         {1, "odd"},
//         {2, "even"},
//         {3, "odd"},
//         {4, "even"},
//         {5, "odd"}
//     };
//     BuildMapValueSet(m);
//     return 0;
// }