#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main(){
    cout << sizeof(int) << endl;
    cout << numeric_limits<int>::min() << ' ' << numeric_limits<int>::max() << endl;
    return 0;
}