#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct A {
    void f() const {
        std::cout << "A::f()\n"; 
    } 
}; 

struct B: public A {
    void f() const {
        std::cout << "B::f()\n"; 
    } 
}; 

class c {
private:
    char* ptr;
    size_t sz;
};

int main() {
    vector<int> v;
    cout << sizeof(c) << endl;
    return 0;
}
