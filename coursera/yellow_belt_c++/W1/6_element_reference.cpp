#include <map>
#include <string>
#include <iostream>

using namespace std;

template<typename K, typename V>
V& GetRefStrict(map<K, V>& m, const K& key) {
    if (m.count(key)) {
        return m.at(key);
    } else {
        throw runtime_error("Error");
    }
    
}

int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
    string& item2 = GetRefStrict(m, 2);

    return 0;
}