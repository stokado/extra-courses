#include <iostream>
#include <vector>
#include <string>
#include <tuple> // cortege / tuple

using namespace std;

struct Date{
    int year;
    string month;  // it can be string or int
    int day;
};

// Overloaded operator< like this in white belt final
// Chance to make misstake is high

// bool operator<(const Date& lhs, const Date& rhs){
//     if (lhs.year != rhs.year){
//         return lhs.year < rhs.year;
//     }
//     if (lhs.month != rhs.month){
//         return lhs.month < rhs.month;
//     }
//     return lhs.day < rhs.day;
// }

// Author's solution
// Less misstake chance
// But vector is too powerfull for this operation and a lot of erros occure when Date has different types

// bool operator<(const Date& lhs, const Date& rhs){
//     return vector<int>{lhs.year, lhs.month, lhs.day} < vector<int>{rhs.year, rhs.month, rhs.day};
// }

// We should use tuple library and "tie" our data

bool operator<(const Date& lhs, const Date& rhs){
    tuple<const int&, const string&, const int&> lhs_key = tie(lhs.year, lhs.month, lhs.day);
    auto rhs_key = tie(rhs.year, rhs.month, rhs.day);
    return lhs_key < rhs_key;
}

int main(){
    cout << (Date{2017, "June", 8} < Date{2017, "January", 26}) << endl;
    return 0;
}