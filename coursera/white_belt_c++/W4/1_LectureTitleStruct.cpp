#include <string>

using namespace std;

struct Specialization
{
    string value;
    explicit Specialization(const string& new_value)
    {
        value = new_value;
    }
};

struct Course
{
    string value;
    explicit Course(const string& new_value)
    {
        value = new_value;
    }
};

struct Week
{
    string value;
    explicit Week(const string& new_value)
    {
        value = new_value;
    }
};

struct LectureTitle 
{
    string specialization;
    string course;
    string week;

    LectureTitle(const Specialization& new_spec, const Course& new_cource, const Week& new_week)
    {
        specialization = new_spec.value;
        course = new_cource.value;
        week = new_week.value;
    }
};

int main()
{
    LectureTitle title(
        Specialization("C++"),
        Course("White belt"),
        Week("4th")
    );

    return 0;
}