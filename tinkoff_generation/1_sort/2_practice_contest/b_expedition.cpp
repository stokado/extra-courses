#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<bool, int>>> raft;
    for (int i = 0; i < n; i++){
        vector<pair<bool,int>> tv;
        for (int j = 0; j < m; j++){
            int temp;
            cin >> temp;
            tv.push_back({0, temp});
        }
        sort(begin(tv), end(tv));
        raft.push_back(tv);
    }
    int k;
    cin >> k;
    vector<int> people;
    for (int i = 0; i < k; i++){
        int temp;
        cin >> temp;
        people.push_back(temp);
    }
    sort(begin(people), end(people));
    int counter = 0;
    for (const int& cur : people){
        bool found = false;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!raft[i][j].first && raft[i][j].second >= cur){
                    raft[i][j].first = true;
                    counter++;
                    found = true;
                    break;
                }
            }
            if (found){
                break;
            }
        }
    }
    cout << counter;
    return 0;
}