#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
T Max (T a, T b) {
    if (b < a) {
        return a;
    }
    return b;
}

int main() {
    cout << Max(2, 3) << endl;
    // compiler doesn't know which types to use (double, int) ?
    // cout << Max(2.5, 3) << endl;
    cout << Max<double>(2, 3.5) << endl;
    cout << Max<int>(2, 3.5) << endl;
    // works with std functions
    cout << max<double>(2, 3.5) << endl;
    // same error as for our function
    // cout << max(2, 3.5) << endl;
    return 0;
}