#include <iostream>
#include <memory>

using namespace std;

struct A { void f() const { std::cout << "A::f()\n"; } }; struct B: public A { virtual void f() const { std::cout << "B::f()\n"; } }; int main() { A a = B(); a.f(); }
