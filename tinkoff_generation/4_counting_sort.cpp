#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    map <int, int> v;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v[temp]++;
    }
    for (const auto& i : v){
        for (int j = 0; j < i.second; j++){
            cout << i.first << ' ';
        }
    }
    return 0;
}