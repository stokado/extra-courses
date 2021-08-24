#include <iostream>
#include <set>

using namespace std;

int main(){
    int footSize;
    cin >> footSize;
    int n;
    cin >> n;
    set<int> shoes;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        shoes.insert(temp);
    }
    int counter = 0;
    if (shoes.lower_bound(footSize) != shoes.end()){
        footSize = *shoes.lower_bound(footSize);
        counter++;
    }
    for (const int& i : shoes){
        if(i >= footSize + 3){
            counter++;
            footSize = i;
        }
    }
    cout << counter;
    return 0;
}