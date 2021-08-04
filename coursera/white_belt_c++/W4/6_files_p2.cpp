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
        ofstream output("output.txt");
        string line;
        while(getline(input, line))
        {
            output << line << endl;
        }
    }
    return 0;
}