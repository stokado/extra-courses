// Task
// Given a base-10 integer, n, convert it to binary (base-2).
// Then find and print the base-10 integer denoting the maximum number of consecutive 1's in n's binary representation.
// When working with different bases, it is common to show the base as a subscript.

#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    stack <int> st;
    while (n){
        st.push(n % 2);
        n /= 2;
    }
    int max = 0;
    int counter = 0;
    while (!st.empty()){
        if (st.top() == 1){
            counter++;
        } else{
            counter = 0;
        }
        if (max < counter){
            max = counter;
        }
        st.pop();
    }
    cout << max;
    return 0;
}