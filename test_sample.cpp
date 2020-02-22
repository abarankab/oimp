#include "model.h"

#include <iostream>
#include <sstream>

using namespace std;

int main() {
    // заклинание для ускорения потокового ввода-вывода
    std::ios::sync_with_stdio(false);

    Model m1;
    m1.data.resize(5);
    m1.data = {1, 2, 3, 4, 5};

    // как-то заполняем m1.data случайными числами

    std::stringstream ss;  // записываем данные не в файл, а просто в память (в строку)
    m1.save(ss);

    Model m2;
    m2.load(ss);

    if (m1.data != m2.data) {
        for (int x : m1.data) cout << x << " ";
        cout << endl;
        for (int x : m2.data) cout << x << " ";
        cout << endl;
        std::cout << "Models differ\n";
    }
}
