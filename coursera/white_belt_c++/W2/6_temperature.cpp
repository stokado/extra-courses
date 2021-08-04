#include <iostream>
#include <vector>

using namespace std;

vector <int> ReadVector(const int& size)
{
    vector <int> vect;
    for (int i = 0; i < size; ++i)
    {
        int temp;
        cin >> temp;
        vect.push_back(temp);
    }
    return vect;
}

int countAM (const vector <int>& v)
{
    int am = 0;
    for (auto now : v)
        am += now;
    return am / v.size();
}

int main()
{
    int n;
    cin >> n;
    vector <int> t = ReadVector(n);
    int temp_am = countAM(t);
    int counter = 0;
    vector<int> numbers;
    for (int i = 0; i < n; i++)
    {
        if (t[i] > temp_am)
        {
            counter++;
            numbers.push_back(i);
        }
    }
    cout << counter << endl;
    for (int i = 0; i < counter; i++)
    {
        if (i != counter - 1)
            cout << numbers[i] << " ";
        else
            cout << numbers[i];
    }
    return 0;
}