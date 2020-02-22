#include "key_value_storage.h"

#include <string>
#include <iostream>

using namespace std;


int main() {
    KeyValueStorage<std::string, int> kv;
    kv.insert("hello", 42);
    kv.insert("bye", -13);
    int value = 123;
    auto res = kv.find("wrong", &value);  // должно вернуться false, а value не должен меняться
    res = kv.find("bye", &value);  // должно вернуться true, в value должно быть -13
    cout << res << " " << value << endl;
    res = kv.find("hello", nullptr);  // должно вернуться true
    cout << res << endl;
}
