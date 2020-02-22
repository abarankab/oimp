#include <bits/stdc++.h>
#include <numeric>

using namespace std;

class Rational {
    private:
    int a, b;

    public:
    Rational() {
        a = 0;
        b = 1;
    }

    Rational(int _a) {
        a = _a;
        b = 1;
    }

    Rational(int _a, int _b) {
        if (_b == 0) throw(0);
        if (_b < 0) _a = -_a, _b = -_b;
        if (_a == 0) {
            a = 0;
            b = 1;
        } else {
            int g = gcd(_a, _b);
            _a /= g, _b /= g;

            a = _a;
            b = _b;
        }
    }

    bool operator==(const Rational& other) const {
		return a == other.a && b == other.b;
    }

    bool operator!=(const Rational& other) const {
        return a != other.a || b != other.b;
    }

    Rational operator+(const Rational& other) const {
        return Rational(a * other.b + other.a * b, b * other.b);
    }

    Rational& operator+=(const Rational& other) {
        Rational result = *this + other;
        a = result.a;
        b = result.b;
        return *this;
    }

    Rational operator-(const Rational& other) const {
        return Rational(a * other.b - other.a * b, b * other.b);
    }

    Rational& operator-=(const Rational& other) {
        Rational result = *this - other;
        a = result.a;
        b = result.b;
        return *this;
    }

    Rational operator*(const Rational& other) const {
        return Rational(a * other.a, b * other.b);
    }

    Rational& operator*=(const Rational& other) {
        Rational result = *this * other;
        a = result.a;
        b = result.b;
        return *this;
    }

    Rational operator/(const Rational& other) const {
        return Rational(a * other.b, b * other.a);
    }

    Rational& operator/=(const Rational& other) {
        Rational result = *this / other;
        a = result.a;
        b = result.b;
        return *this;
    }

    Rational operator+() const {
        return Rational(a, b);
    }

    Rational operator-() const {
        return Rational(-a, b);
    }

    Rational& operator++() {
        Rational result(a + b, b);
        a = result.a;
        b = result.b;
        return *this;
    }

    Rational operator++(int) {
        Rational old = *this;
        ++*this;
        return old;
    }

    Rational& operator--() {
        Rational result(a - b, b);
        a = result.a;
        b = result.b;
        return *this;
    }

    Rational operator--(int) {
        Rational old = *this;
        --*this;
        return old;
    }

    int numerator() const {
        return a;
    }

    int denominator() const {
        return b;
    }
};

Rational operator+(Rational a, int b) {
    return a + Rational(b);
}

Rational operator+(int b, Rational a) {
    return Rational(b) + a;
}

Rational operator-(Rational a, int b) {
    return a - Rational(b);
}

Rational operator-(int b, Rational a) {
    return Rational(b) - a;
}

Rational operator*(Rational a, int b) {
    return a * Rational(b);
}

Rational operator*(int b, Rational a) {
    return Rational(b) * a;
}

Rational operator/(Rational a, int b) {
    return a / Rational(b);
}

Rational operator/(int b, Rational a) {
    return Rational(b) / a;
}

ostream& operator<<(ostream &out, Rational a) {
    out << a.numerator() << " " << a.denominator() << endl;
    return out;
}

int main() {
    Rational p(1, 2), q(3, 4);
    cout << p + q << p - q << p * q << p / q;
    p += Rational(1, 2);
    cout << p << ++p << p--;
    cout << p;
    p += 2;
    cout << p;
}

