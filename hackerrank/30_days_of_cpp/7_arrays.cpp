// Given and array of integers print integers in reverse order

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = n - 1; i >= 0; i--){
        cout << v[i] << ' ';
    }
    return 0;
}