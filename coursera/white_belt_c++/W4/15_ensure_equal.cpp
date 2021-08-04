#include <exception>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void EnsureEqual(const string& left, const string& right)
{
    if (left != right)
    {
        throw runtime_error(left + " != " + right);
    }
}

int main()
{
    try
    {
        EnsureEqual("C++ White", "C++ White");
        EnsureEqual("C++ White", "C++ Yellow");
    }
    catch(exception& ex)
    {
        cout << ex.what() << endl;
    }
    
    return 0;
}