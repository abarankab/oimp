#include <bits/stdc++.h>
#include <cmath>

using namespace std;

class Complex {
    private:
    double a, b;
    
    public:
    Complex() {
        a = b = 0;
    }

    Complex(double _a) {
        a = _a;
    }

    Complex(double _a, double _b) {
        a = _a;
        b = _b;
    }

    bool operator==(const Complex &other) const {
        return a == other.a && b == other.b;
    }

    bool operator!=(const Complex &other) const {
        return a != other.a || b != other.b;
    }

    Complex operator+(const Complex &other) const {
        return Complex(a + other.a, b + other.b);
    }

    Complex operator-(const Complex &other) const {
        return Complex(a - other.a, b - other.b);
    }

    Complex operator*(const Complex &other) const {
        return Complex(a * other.a - b * other.b, b * other.a + a * other.b);
    }

    Complex operator/(const Complex &other) const {
        double new_a = (a * other.a + b * other.b) /
                       (other.a * other.a + other.b * other.b);
        double new_b = (b * other.a - a * other.b) /
                       (other.a * other.a + other.b * other.b);
        return Complex(new_a, new_b);
    }

    Complex operator+() const {
        return Complex(a, b);
    }

    Complex operator-() const {
        return Complex(-a, -b);
    }

    double Re() const {
        return a;
    }

    double Im() const {
        return b;
    }
};

Complex operator==(Complex a, double b) {
    return a == Complex(b);
}

Complex operator!=(Complex a, double b) {
    return a != Complex(b);
}

Complex operator+(Complex a, double b) {
        return a + Complex(b);
}

Complex operator-(Complex a, double b) {
        return a - Complex(b);
}

Complex operator*(Complex a, double b) {
        return a * Complex(b);
}

Complex operator/(Complex a, double b) {
        return a / Complex(b);
}

Complex operator==(double b, Complex a) {
        return a == b;
}

Complex operator!=(double b, Complex a) {
        return a != b;
}

Complex operator+(double b, Complex a) {
        return a + b;
}

Complex operator-(double b, Complex a) {
        return a - b;
}

Complex operator*(double b, Complex a) {
        return a * b;
}

Complex operator/(double b, Complex a) {
        return a / b;
}

double abs(Complex z) {
    return sqrt(z.Im() * z.Im() + z.Re() * z.Re());
}

ostream & operator<<(ostream &out, Complex z) {
    out << z.Re() << " " << z.Im();
    return out;
}

int main() {
    Complex x(1, -1), y(5, 3), z(1, 0);
    cout << abs(x) << endl;
    cout << -x << endl;
    cout << x * 3 << " " << 3 * x << endl;
    return 0;
}
