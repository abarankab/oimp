#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

class C {
    private:
    int x;

    public:
    C(int x = 0): x(x) {
        cout << "C()\n";
    }

    C(C& other) {
        x = other.x;
        cout << "C(C&)\n";
    }

    C(C&& other) {
        x = other.x;
        cout << "C(C&&)\n";
    }

    C operator=(C& other) {
        x = other.x;
        cout << "operator=\n";
        return *this;
    }

    bool operator<(C& other) {
        return x < other.x;
    }

    void swap(C& other) {
        cout << "swappigf";
        std::swap(x, other.x);
    }
};

int main() {
    list<C> l;
    for (int i = 0; i < 100; ++i) {
        l.push_back(C((i * 100 + i * i - 345 * i * i * i * 54) % 200));
    }
    cout << "list<C> l\n";
    l.sort();
    cout << "sorted\n";
    return 0;
}
