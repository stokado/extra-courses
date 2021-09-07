#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

// Main template
template <typename T> T Sqr(T x);
// Vector template
template <typename T> vector <T> Sqr (const vector<T>& v);
// Pair template
template <typename F, typename S> pair<F, S> Sqr (const pair<F, S>& p);
// Map template
template <typename K, typename V> map<K, V> Sqr (const map<K, V>& m);

template <typename T>   
T Sqr(T x) {
    return x * x;
}

template <typename F, typename S>
pair<F, S> Sqr(const pair<F, S>& p) {
    return {Sqr(p.first), Sqr(p.second)};
}

template <typename K, typename V>
map<K, V> Sqr (const map<K, V>& m) {
    map<K, V> answer;
    for (const auto& i : m) {
        answer[i.first] = Sqr(i.second);
    }
    return answer;
}

template <typename T>
vector <T> Sqr (const vector<T>& v) {
    vector<T> answer;
    for (const auto& i : v) {
        answer.push_back(Sqr(i));
    }
    return answer;
}

int main() {
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    map<int, pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }


    cout << endl;
    return 0;
}