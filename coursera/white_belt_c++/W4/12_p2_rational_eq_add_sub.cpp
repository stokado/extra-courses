#include <iostream>
#include <numeric>
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
    if (lhs.Denominator() == rhs.Denominator())
    {   // если числитель одинаковый
        return {lhs.Numerator() + rhs.Numerator(), lhs.Denominator()};
    }
    else
    {   
        int nom = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
        int den = lhs.Denominator() * rhs.Denominator();
        return {nom,den};
    }
}

Rational operator - (const Rational& lhs, const Rational& rhs)
{   
    if (lhs.Denominator() == rhs.Denominator())
    {   // если числитель одинаковый
        return {lhs.Numerator() - rhs.Numerator(), lhs.Denominator()};
    }
    else
    {   // реализовать, если числитель разный
        int nom = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
        int den = lhs.Denominator() * rhs.Denominator();
        return {nom,den};
    }
}

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
