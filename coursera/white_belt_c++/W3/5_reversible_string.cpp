#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class ReversibleString
{
public:
    ReversibleString()
    {
        mod = "";
    };
    ReversibleString(const string& init)
    {
        mod = init; 
    };

    void Reverse()
    {
        reverse(begin(mod), end(mod));
    };

    string ToString() const
    {
        return mod;
    };

private:
    string mod;
};

int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}
