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
    vector<int> v = {2, 3, 1, 3, 49, 6, 6};
    InsertionSort(v);
    for (const int& i : v){
        cout << i << " ";
    }
    return 0;
}