#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

template <typename Collection>
string Join(const Collection& c, char d) {
    stringstream ss;
    bool first = true;
    for (const auto& i : c) {
        if (!first) {
            ss << d;
        }
        first = false;
        ss << i;
    }
    return ss.str();
}

template <typename First, typename Second>
ostream& operator<< (ostream& out, const pair<First, Second>& p){
    return out << '(' << p.first << ',' << p.second << ')';
}

template <typename T>
ostream& operator<< (ostream& out, const vector<T>& vi){
    return out << '[' << Join(vi, ',') << ']';
}

template <typename Key, typename Value>
ostream& operator<< (ostream& out, const map <Key, Value> m){
    return out << '{' << Join(m, ',') << '}';

}

int main(){
    vector<int> vi = {1, 2, 3};
    vector<double> vd = {1.4, 2, 3};
    cout << vi << endl;
    cout << vd << endl;
    map <int, double> m = { {1, 2.5}, {3, 4} };
    cout << m << endl;
    vector<vector<int>> vv = {{1, 2}, {3, 4}, {1, 2, 3, 4}};
    cout << vv << endl;
    return 0;
}