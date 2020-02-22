#include <memory>
#include <string>
#include <vector>

using namespace std;

class ConstClass: public Expression() {
private:
    int value;
public:
    ConstClass(int value): value(value) {}
    int Evaluate() {
        return value;
    }
    string ToString() {
        return to_string(value);
    }
};

class SumClass: public Expression() {
private:
    shared_ptr<Expression> lhs;
    shared_ptr<Expression> rhs;
public:
    SumClass(shared_ptr<Expression> lhs, shared_ptr<Expression> rhs): lhs(lhs), rhs(rhs) {}
    int Evaluate() {
        return lhs->Evaluate() + rhs->Evaluate();
    }
    string ToString() {
        return lhs->ToString() + " + " + rhs->ToString();
    }
};

class ProductClass: public Expression() {
private:
    shared_ptr<Expression> lhs;
    shared_ptr<Expression> rhs;
public:
    ProductClass(shared_ptr<Expression> lhs, shared_ptr<Expression> rhs): lhs(lhs), rhs(rhs) {}
    int Evaluate() {
        return lhs->Evaluate() * rhs->Evaluate();
    }
    string ToString() {

    }
};

shared_ptr<Expression> Const(int x) {
    return shared_ptr(new ConstClass(x));
}

sared_p
