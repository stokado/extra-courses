#include <string>
#include <map>
#include <iostream>

using namespace std;

map <char, int> BuildMap(const string& w){
    map <char, int> answer;
    for (const char& i : w){
        answer[i]++;
    }
    return answer;
}
int main(){
    string w1, w2;
    cin >> w1 >> w2;
    if (BuildMap(w1) == BuildMap(w2)){
        cout << "YES";
    } 
    else
    {
        cout << "NO";
    }
    return 0;
}