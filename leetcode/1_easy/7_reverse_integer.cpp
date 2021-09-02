// Problem

// Given a signed 32-bit integer x, return x with its digits reversed.
// If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

class Solution{
    public:
    int reverse(int x) {
        if (x == 0){
            return x;
        }
        bool negative = false;
        if (x < 0){
            negative = true;
            x *= -1;
        }
        
        queue<int> prepare;
        
        while(x){
            prepare.push(x % 10);
            x /= 10;
        }
        
        if (prepare.front() == 0){
            prepare.pop();
        }
        
        for (int k = pow(10, prepare.size() - 1); !prepare.empty(); k /= 10){
            x += prepare.front() * k;
            prepare.pop();
        }
        if (negative){
            x *= -1;
        }
        return x;        
    }
};

int main(){
    int x = 0;
    cin >> x;
    Solution sol;
    cout << sol.reverse(x);
    return 0;
}