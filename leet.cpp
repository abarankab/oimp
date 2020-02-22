#include <iostream>
#include <string>
#include <regex>

bool isNumber(string s) {
    std::regex number_regex("(+|-)?\\d*\\.?\\d*e?\\d*");
    return std::regex_match(s, number_regex);
}

int main() {
    std::string s;
    std::cin >> string s;
    std::cout << isNumber(s);
    return 0;
}

