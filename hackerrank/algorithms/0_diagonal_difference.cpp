#include <vector>
#include <iostream>

using namespace std;

int diagonalDifference(const vector<vector<int>>& arr) {
    int fd = 0, sd = 0;
    for (int i = 0; i < arr.size(); i++){
        for (int j  = 0; j < arr[i].size(); j++){
            if (i == j){
                fd += arr[i][j];
            }
            if (i + j == arr.size() - 1){
                sd += arr[i][j];
            }
        }
    }
    return abs(fd - sd);
}

int main(){
    vector<vector<int>> ar {{11, 2, 4}, {4, 5, 6}, {10, 8, -12}};
    cout << diagonalDifference(ar);
    return 0;
}