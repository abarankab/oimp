#include "unique_ptr1.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    string* sp0 = new string("asd");
    UniquePtr<string> p0(sp0);
    UniquePtr<string> p(move(p0));
    cout << (*p) << endl;
    cout << p->back() << endl;
    string* sp = new string("qwe");
    UniquePtr<string> p2(sp);
    p2.reset(p.release());
    cout << *p2.get() << endl;
    UniquePtr<string> p3;
    p2.swap(p3);
    cout << bool(p3) << endl;
    p3 = nullptr;
    cout << bool(p3) << endl;
    UniquePtr<string> p4(new string("str"));
    cout << *p4 << endl;
    p3 = move(p4);
    cout << *p3 << endl;
}
