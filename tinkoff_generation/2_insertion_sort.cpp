#include <vector>
#include <iostream>

using namespace std;

void InsertionSort(vector<int>& v){
    for (int i = 0; i < v.size() - 1; ++i){
        for (int j = i + 1; j > 0; --j){
            if (v[j] < v[j - 1]){
                int temp = v[j - 1];
                v[j - 1] = v[j];
                v[j] = temp;
            }
            else{
                break;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    InsertionSort(v);
    for (const int& i : v){
        cout << i << " ";
    }
    return 0;
}