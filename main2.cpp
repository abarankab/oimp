#include <string>
#include <iostream>

using namespace std;

int main() {
    string s;
    size_t len = 0;
    getline(cin, s);
    for (size_t i = 0; i < s.size();) {
        if (((s[i] >> 7) & 1) == 0) {
            ++i, ++len;
        } else {
            int cnt = 0;
            while (cnt < 4 && ((s[i] >> (7 - cnt)) & 1 == 1)) ++cnt;
            i += cnt;
            ++len;
        }
    }
    cout << len << endl;
    return 0;
}
