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
            throw (invalid_argument ("denominator is 0"));
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
        throw (domain_error ("division by 0"));
    }
    Rational inverted_rhs {rhs.Denominator(), rhs.Numerator()};
    return lhs * inverted_rhs;
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
