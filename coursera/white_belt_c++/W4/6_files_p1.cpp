#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string path = "input.txt";
    ifstream input(path);
    if (input)
    {
        string line;
        while(getline(input, line))
        {
            cout << line << endl;
        }
    }
    return 0;
}