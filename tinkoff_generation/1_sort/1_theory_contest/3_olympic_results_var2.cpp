#include <iostream>
#include <vector>

// Need more testing doesn't work in all cases;

using namespace std;

void SortArray(vector<pair<int,int>>& v){
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v.size() - 1 - i; j++){
            if (v[j] > v[j + 1]){
                pair<int, int> temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

}

int main(){
    int n;
    cin >> n;
    vector <pair<int,int>> results;
    for (int i = 0; i < n; i++){
        int id, score;
        cin >> id >> score;
        results.push_back({score, id});
    }
    SortArray(results);
    for (const auto& i : results){
        cout << i.second << " " << i.first << endl;
    }
    return 0;
}