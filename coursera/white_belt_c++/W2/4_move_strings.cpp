#include <vector>
#include <string>
#include <iostream>

using namespace std;

void MoveStrings(vector <string>& source, vector <string>& destination)
{
    for (auto now : source)
        destination.push_back(now);
    source.clear();
}

int main()
{
    vector<string> source = {"a", "b", "c"};
    for (auto now : source)
        cout << now << " ";
    vector<string> destination = {"z"};
    for (auto now : destination)
        cout << now << " ";
    MoveStrings(source, destination);
    for (auto now : source)
        cout << now << " ";
    for (auto now : destination)
        cout << now << " ";
    return 0;
}