template<typename T>
class IntegrationMethod {
public:
    virtual double Integrate(T func, double x, double y, int n) const {}
};

template<typename T>
class RectangleRule: public IntegrationMethod<T> {
public:
    double Integrate(T f, double x, double y, int n) const override {
        double step = (y - x) / n, result = 0;
        for (int i = 0; i < n; ++i) {
            result += f(x + step / 2) * step;
            x += step;
        }
        return result;
    }
};

template<typename T>
class TrapezoidalRule: public IntegrationMethod<T> {
public:
    double Integrate(T f, double x, double y, int n) const override {
        double step = (y - x) / n, result = 0;
        for (int i = 0; i < n; ++i) {
            result += (f(x) + f(x + step)) / 2 * step;
            x += step;
        }
        return result;
    }
};
