// Problem
// Given an array of integers, calculate the ratios of its elements that are positive, negative, and zero.
// Print the decimal value of each fraction on a new line with 6 places after the decimal.

// Input Format
// The first line contains an integer, n, the size of the array.
// The second line contains n space-separated integers that describe arr[n].

// Output Format

// Print the following 3 lines, each to 6 decimals:
// 1. proportion of positive values
// 2. proportion of negative values
// 3. proportion of zeros

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void plusMinus(const vector<int>& arr) {
    int pc = 0, nc = 0, zc = 0;
    for (const int& val : arr){
        if (val > 0){
            pc++;
        } else if (val < 0){
            nc++;
        } else {
            zc++;
        }
    }
    cout << fixed << setprecision(6) << (double) pc / arr.size() << endl;
    cout << fixed << setprecision(6) << (double) nc / arr.size() << endl;
    cout << fixed << setprecision(6) << (double) zc / arr.size() << endl;
}

int main(){
    vector<int> ar {1, -1, 1, -1, -1, -1, -1, 0, 0, 0, 0, 1};
    plusMinus(ar);
    return 0;
}