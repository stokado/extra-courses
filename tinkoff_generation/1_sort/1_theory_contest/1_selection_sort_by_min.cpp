#include <vector>
#include <iostream>

using namespace std;

// O(n^2)

void SelectionSort(vector<int>& v){
    for (int i = 0; i < v.size() - 1; ++i){
        int min_ind = i;  
        for (int j = i + 1; j < v.size(); ++j){
            if (v[j] < v[min_ind]){
                min_ind = j;
            }
        }
        if (v[i] > v[min_ind]){
            int temp = v[i];
            v[i] = v[min_ind];
            v[min_ind] = temp;           
        }
    }
}

int main(){
    vector<int> v = {1, 5, 20, 1, -3, 88, 7, 7, 0};
    SelectionSort(v);
    for (const int& i : v){
        cout << i << " ";
    }
    return 0;
}