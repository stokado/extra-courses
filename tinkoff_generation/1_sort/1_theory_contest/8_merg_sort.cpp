#include <iostream>
#include <vector>

using namespace std;

vector<int> Merge(vector<int> a, vector<int> b){
    vector<int> answer;
    for (int i = 0, j = 0; i < a.size() || j < b.size();){
        if (a[i] < b[j] && i != a.size()){
            answer.push_back(a[i]);
            i++;
        }
        else if (j != b.size()){
            answer.push_back(b[j]);
            j++;
        }
    }
    
    return answer;
}

// void MergeSort(vector<int> v, int l, int r){
//     if (l < r){
//         int m = 
//     }

// }

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    vector<int> d = v;
    d.push_back(25);
    Merge(v, d);
    return 0;
}