#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void ReadAll(const string& path)
{
    ifstream input(path);
    if (input)
    {
        string line;
        while (getline(input, line))
        {
            cout << line << endl;
        }
    }

}

// int main()
// {
//     // ifstream input("4_date.txt");
//     // int year = 0;
//     // int month = 0;
//     // int day = 0;
//     // if (input)
//     // {
//     //    input >> year;
//     //    input.ignore(1);
//     //    input >> month;
//     //    input.ignore(1);
//     //    input >> day;
//     //    input.ignore(1);
//     // }
//     // cout << year << ' ' << month << ' ' << day << endl;
//     return 0;
// }


int main(){
    const string path = "4_output.txt";
    ofstream output(path, ios::app);
    output << " , world!" << endl;
    ReadAll(path);
    return 0;
}

