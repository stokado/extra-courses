#include <vector>
#include <iostream>

using namespace std;

void SumHourglass(const vector <vector <int>>& v){
    int tempSum;
    int maxSum = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            tempSum = 0;
            tempSum += v[i][j];
            tempSum += v[i][j + 1];
            tempSum += v[i][j + 2];
            tempSum += v[i + 1][j + 1];
            tempSum += v[i + 2][j];
            tempSum += v[i + 2][j + 1];
            tempSum += v[i + 2][j + 2];
            if (tempSum > maxSum || i == 0 && j == 0){
                maxSum = tempSum;
            }
        }
    }
    cout << maxSum;
}