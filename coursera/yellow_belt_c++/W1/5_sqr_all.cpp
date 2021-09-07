#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

template <typename First, typename Second> pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2);
template <typename Key, typename Value> map<Key, Value> operator* (const map<Key, Value>& m1, const map<Key, Value>& m2);
template <typename T> vector <T> operator* (const vector<T>& v1, const vector<T>& v2);
template <typename T> T Sqr(T x);

template <typename First, typename Second>
pair<First, Second> operator*(const pair<First, Second>& p1, const pair<First, Second>& p2) {
    return {p1.first * p2.first, p1.second * p2.second};
}

template <typename T>
vector <T> operator* (const vector<T>& v1, const vector<T>& v2) {
    vector<T> answer;
    for (const auto& i : v1) {
        answer.push_back(i * i);
    }
    return answer;
}

template <typename Key, typename Value>
map<Key, Value> operator* (const map<Key, Value>& m1, const map<Key, Value>& m2) {
    map<Key, Value> answer;
    for (const auto& i : m1) {
        answer[i.first] = i.second * i.second;
    }
    return answer;
}

template <typename T>   
T Sqr(T x) {
    return x * x;
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