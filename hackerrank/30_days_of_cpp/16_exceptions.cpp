#include <string>
#include <iostream>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    try
    {
        int i = stoi(s);
        cout << i;
    }
    catch(exception& ex)
    {
        cout << "Bad String";
    }
    return 0;
}