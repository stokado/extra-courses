#include <iostream>
#include <utility>

using namespace std;

// Overload
// int Sqr(int x) {
//     return x * x;
// }

// double Sqr(double x) {
//     return x * x;
// }


// Template of function with 2 types First and Second
template <typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2){
    First f = p1.first * p2.first;
    Second s = p1.second * p2.second;
    return {f, s};
}

// If T has operator of * this function will work for these types
// Template of fuction
// Keyword typename tells compiler to find out type of T
template <typename T>   
T Sqr(T x) {
    return x * x;
}

int main() {
    auto p = make_pair(2.5, 3);
    cout << Sqr(2) << endl;
    cout << Sqr(2.5) << endl;
    auto res = Sqr(p);
    cout << res.first << endl;
    cout << res.second << endl;
    return 0;
}