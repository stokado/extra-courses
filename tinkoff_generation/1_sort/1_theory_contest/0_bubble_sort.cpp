#include <vector>
#include <iostream>

using namespace std;

// O(n^2)

void BubbleSort(vector<int>& v){
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v.size() - 1 - i; j++){
            if (v[j] > v[j + 1]){
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
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
    BubbleSort(v);
    for (const int& i : v){
        cout << i << " ";
    }
    return 0;
}