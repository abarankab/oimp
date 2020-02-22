#include "vector2.h"
#include <iostream>

using namespace std;

struct C {
    C() { cout << "C()\n"; }
    ~C() { cout << "~C()\n"; }
};

int main() {
    Vector<C> v(5);
}
