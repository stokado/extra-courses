// Problem
// This is a staircase of size n = 4:

//    #
//   ##
//  ###
// ####
// Its base and height are both equal to n. It is drawn using # symbols and spaces. The last line is not preceded by any spaces.
// Write a program that prints a staircase of size n.

// Input Format
// A single integer, , denoting the size of the staircase.

// Constrants
// 0 < n <= 100

// Output Format

// Print a staircase of size n using # symbols and spaces.
// Note: The last line must have 0 spaces in it.

#include <iomanip>
#include <iostream>

using namespace std;

void staircase(const int& val){
    int n = 0;
    for (int i = 0; i < val; i++){
        for (int j = 0; j < val; j++){            
            if (j >= val - n - 1){
                cout << '#';
            } else {
                cout << ' ';
            }
        }
        n++;
        cout << endl;    
    }
}

int main(){
    int n = 6;
    staircase(n);
    return 0;
}
