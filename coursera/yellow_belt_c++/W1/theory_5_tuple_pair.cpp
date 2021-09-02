#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <map>

using namespace std;

int main(){
    tuple<int, string, bool> t(7, "C++", true);
    // tuple t(7, "C++", true);             // SINCE C++17 Structure binding
    // auto x = tie(7, "C++", true);        // ERROR we can only tie created objects
    // auto x = make_tuple(7, "C++", true);
    cout << get<1>(t) << endl;
    // pair<int, string> p(7, "C++");
    pair p(7, "C++");                    // SINCE C++17 Structure binding
    // auto tp = make_pair(7, "C++");
    map <int, string> digits {{1, "one"}};
    for (const auto& item : digits){
        cout << item.first << " " << item.second << endl;
    }
    for (const auto& [key, value] : digits){
        cout << key << " " << value << endl;
    }
    return 0;
}