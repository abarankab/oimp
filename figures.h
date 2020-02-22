class Figure {
public:
    virtual double Perimeter() const {}
    virtual ~Figure() = default;
};

class Triangle: public Figure {
private:
    double a, b, c;
public:
    Triangle(double a, double b, double c): a(a), b(b), c(c) {}
    double Perimeter() const override {
        return a + b + c;
    }
    ~Triangle() = default;
};

class Rectangle: public Figure {
private:
    double a, b;
public:
    Rectangle(double a, double b): a(a), b(b) {}
    double Perimeter() const override {
        return (a + b) * 2;
    }
    ~Rectangle() = default;
};

