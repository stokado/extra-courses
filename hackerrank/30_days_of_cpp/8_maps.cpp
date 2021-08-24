#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    map <string, int> phonebook;
    for (int i = 0; i < n; i++){
        string name;
        int number;
        cin >> name >> number;
        phonebook[name] = number;
    }
    string query;
    while(cin >> query){
        if (phonebook.find(query) != phonebook.end()){
            cout << query << '=' << phonebook[query] << endl;;
        } else{
            cout << "Not found\n";
        }
    }
    return 0;
}