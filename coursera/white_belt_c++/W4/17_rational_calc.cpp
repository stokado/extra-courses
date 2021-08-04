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
        if (denominator == 0)
        {
            throw (invalid_argument ("Invalid argument"));
        }
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

Rational operator * (const Rational& lhs, const Rational& rhs)
{
    return {
        lhs.Numerator() * rhs.Numerator(),
        lhs.Denominator() * rhs.Denominator()
    };
}

Rational operator / (const Rational& lhs, const Rational& rhs)
{
    if (rhs.Numerator() == 0)
    {
        throw (domain_error ("Division by zero"));
    }
    Rational inverted_rhs {rhs.Denominator(), rhs.Numerator()};
    return lhs * inverted_rhs;
}

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
            rat = Rational(num, denom);
            rat = Rational(rat.Numerator(), rat.Denominator());
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
    Rational num1, num2;
    char operation;
    try
    {
        cin >> num1
            >> operation
            >> num2;
    }
    catch (invalid_argument &ia)
    {
        cout << ia.what();
        return 1;
    }

    try
    {
        if (operation == '+')
        {
            cout << num1 + num2;
        }
        else if (operation == '-')
        {
            cout << num1 - num2;
        }
        else if (operation == '/')
        {
            cout << num1 / num2;
        }
        else 
            cout << num1 * num2;
    }
    catch (domain_error &de)
    {
        cout << de.what();
        return 2;
    }
    return 0;
}