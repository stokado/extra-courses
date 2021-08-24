#include <vector>
#include <iostream>

using namespace std;

// O(n^2)

void SelectionSort(vector<int>& v){
    for (int i = v.size() - 1; i > 0; --i){
        int max_ind = i;  
        for (int j = 0; j < i; ++j){
            if (v[j] > v[max_ind]){
                max_ind = j;
            }
        }
        if (v[i] < v[max_ind]){
            int temp = v[i];
            v[i] = v[max_ind];
            v[max_ind] = temp;           
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector <int> v;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    SelectionSort(v);
    for (const int& i : v){
        cout << i << " ";
    }
    return 0;
}