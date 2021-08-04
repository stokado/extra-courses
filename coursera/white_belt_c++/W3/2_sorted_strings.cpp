#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        lines.push_back(s);
    }
    vector<string> GetSortedStrings() {
        sort(begin(lines), end(lines));
        return lines;
    }
private:
    vector<string> lines;
};

void PrintSortedStrings(SortedStrings& strings)
{
    vector<string> v;
    v = strings.GetSortedStrings();
    for (const auto& line : v)
    {
        cout << line << " ";
    }
    cout << endl;
}

int main()
{
    SortedStrings strings;
  
    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);
  
    strings.AddString("second");
    PrintSortedStrings(strings);
  
  return 0;
}