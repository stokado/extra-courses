#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student
{
    string first_name;
    string last_name;
    int day_of_birth;
    int month_of_birth;
    int year_of_birth;
};

struct Command
{
    string cmd;
    int num;
};

void Execute(const Command& command, const vector<Student>& students)
{
    if (students.size() < command.num || command.num <= 0)
    {
        cout << "bad request\n";
    }
    else
    {
        if (command.cmd == "name")
        {
            cout << students[command.num - 1].first_name << " " << students[command.num - 1].last_name << endl;
        }
        else if (command.cmd == "date")
        {
            cout << students[command.num - 1].day_of_birth << "." << students[command.num - 1].month_of_birth << "." <<
            students[command.num - 1].year_of_birth << endl;
        }
        else
        {
            cout << "bad request\n";
        }
    }
}

int main()
{
    int num;
    cin >> num;

    vector<Student> students;

    for (int i = 0; i < num; i++)
    {
        Student student;
        cin >> student.first_name;
        cin >> student.last_name;
        cin >> student.day_of_birth;
        cin >> student.month_of_birth;
        cin >> student.year_of_birth;
        students.push_back(student);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string line;
        cin >> line;
        int value;
        cin >> value;
        Command command = {line, value};
        Execute(command, students);
    }
    return 0;
}