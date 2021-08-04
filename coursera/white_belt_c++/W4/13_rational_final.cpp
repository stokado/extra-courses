#include <iostream>
#include <numeric>
#include <sstream>

using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        denom = 1;
    }

    Rational(int numerator, int denominator) {
        int val = gcd(numerator, denominator);
        num = numerator / val;
        denom = denominator / val;
        if (denom < 0)
        {
            denom *= -1;
            num *= -1;
        }
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return denom;
    }

private:
    int num;
    int denom;
};

bool operator == (const Rational& lhs, const Rational& rhs)
{
    return (lhs.Denominator() == rhs.Denominator() && lhs.Numerator() == rhs.Numerator());
}

Rational operator + (const Rational& lhs, const Rational& rhs)
{
    return {
        lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator - (const Rational& lhs, const Rational& rhs)
{   
    return {
        lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator * (const Rational& lhs, const Rational& rhs)
{
    return {
        lhs.Numerator() * rhs.Numerator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator / (const Rational& lhs, const Rational& rhs)
{
    Rational inverted_rhs {rhs.Denominator(), rhs.Numerator()};
    return lhs * inverted_rhs;
}

ostream& operator <<(ostream& stream, const Rational& rat)
{
    stream << rat.Numerator() << '/' << rat.Denominator();
    return stream;
}

istream& operator >> (istream& stream, Rational& rat)
{
    int num = 0;
    char space = 0;
    int denom = 0;
    stream >> num;
    if (num != '\b')
    {
        stream >> space;
        if (space == '/')
        {
            stream >> denom;
            if (denom == 0)
            {
                rat = Rational();
            }
            else
            {
                rat = Rational(num, denom);
                rat = Rational(rat.Numerator(), rat.Denominator());
            }
        }
    }
    return stream;
}

bool operator <(const Rational& lhs, const Rational& rhs)
{
    return (lhs - rhs).Numerator() < 0;
}

int main() 
{
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }
    cout << "OK" << endl;
    return 0;
}
