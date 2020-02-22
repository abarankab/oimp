class B: public A {
    A tmp;
public:
    B(int x = 42): A(x), tmp(17) {
    }
};
