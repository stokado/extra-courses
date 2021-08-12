// Problem

// Given a signed 32-bit integer x, return x with its digits reversed.
// If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int x = 0;
    cin >> x;
    bool negative = false;
    if (x < 0){
        negative = true;
        x *= -1;
    }
    vector <int> answer;
    for (; x > 0;){
        answer.push_back(x % 10);
        x /= 10;
    }

    int final = 0;
    for (const int& item : answer){
        cout << item;
    }
    return 0;
}