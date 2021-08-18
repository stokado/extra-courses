#include <iostream>
#include <vector>

using namespace std;

void SortArray(vector<pair<int,int>>& v){
    for (int i = 0; i < v.size(); i++){
        for (int j = 0; j < v.size() - 1 - i; j++){
            if (v[j].second < v[j + 1].second){
                pair<int, int> temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
            else if (v[j].first > v[j + 1].first && v[j].second == v[j + 1].second){
                pair <int, int> temp = v[j];
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