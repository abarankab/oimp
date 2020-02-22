#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

template<typename T>
class Polynomial {
    private:
    map<int, T> a;

    void clean() {
        vector<int> to_delete;
        for (const auto& p : a) {
            if (p.second == T(0)) {
                to_delete.push_back(p.first);
            }
        }

        for (int key : to_delete) {
            a.erase(key);
        }
    }

    public:
    Polynomial(const vector<T>& other) {
        for (size_t i = 0; i < other.size(); ++i) a[i] = other[i];
        clean();
    }

    Polynomial(T c = T()) {
        a[0] = c;
        clean();
    }

    template<typename It>
    Polynomial(It first, It last) {
        int power = 0;
        for (auto it = first; it != last; ++power, ++it)
            a[power] = *it;
        clean();
    }

    const auto begin() const {
        return a.begin();
    }

    auto begin() {
        return a.begin();
    }

    const auto end() const {
        return a.end();
    }

    auto end() {
        return a.end();
    }

    int Degree() const {
        if (a.empty()) return -1;
        return a.rbegin()->first;
    }

    bool operator==(const Polynomial& other) const {
        return
            Degree() != other.Degree()
            ? false
            : equal(begin(), end(), other.begin(), other.end());
    }

    bool operator!=(const Polynomial& other) const {
        return !(*this == other);
    }

    const T operator[](int i) const {
        if (a.find(i) == a.end()) return T(0);
        return a.at(i);
    }

    Polynomial& operator+=(const Polynomial& other) {
        for (auto it = other.begin(); it != other.end(); ++it) {
            if (a.find(it->first) == a.end()) a[it->first] = T(0);
            a[it->first] += it->second;
        }
        clean();
        return *this;
    }

    Polynomial operator+(const Polynomial& other) const {
        Polynomial tmp(*this);
        tmp += other;
        return tmp;
    }

    Polynomial& operator-=(const Polynomial& other) {
        for (auto it = other.begin(); it != other.end(); ++it) {
            if (a.find(it->first) == a.end()) a[it->first] = T(0);
            a[it->first] -= it->second;
        }
        clean();
        return *this;
    }

    Polynomial operator-(const Polynomial& other) const {
        Polynomial tmp(*this);
        tmp -= other;
        return tmp;
    }

    Polynomial& operator*=(const Polynomial& other) {
        if (Degree() == -1 || other.Degree() == -1) {
            a.clear();
            return *this;
        }
        map<int, T> result;
        for (auto it1 = begin(); it1 != end(); ++it1) {
            for (auto it2 = other.begin(); it2 != other.end(); ++it2) {
                if (result.find(it1->first + it2->first) == result.end()) {
                    result[it1->first + it2->first] = T(0);
                }
                result[(it1->first) + (it2->first)] +=
                       (it1->second) * (it2->second);
            }
        }
        a = move(result);
        clean();
        return *this;
    }

    Polynomial operator*(const Polynomial& other) const {
        Polynomial tmp(*this);
        tmp *= other;
        return tmp;
    }

    T operator()(const T& x) const {
        T result = T(0), power = T(1);
        int power_count = 0;
        for (auto it = begin(); it != end(); ++it) {
            while (power_count != (it->first)) power *= x, ++power_count;
            result += power * (it->second);
        }
        return result;
    }

    Polynomial operator&(const Polynomial& other) const {
        Polynomial result(T(0)), power(T(1));
        int power_count = 0;
        for (auto it = begin(); it != end(); ++it) {
            while (power_count != (it->first)) power *= other, ++power_count;
            result += power * (it->second);
        }
        return result;
    }

    Polynomial operator/(const Polynomial& other) const {
        Polynomial q(T(0)), r(*this);
        while (r.Degree() != -1 && r.Degree() >= other.Degree()) {
            vector<T> tmp(r.Degree() - other.Degree() + 1, T(0));
            tmp.back() = r[r.Degree()] / other[other.Degree()];
            Polynomial t(tmp);
            q += t;
            r -= t * other;
        }
        return q;
    }

    Polynomial operator%(const Polynomial& other) const {
        Polynomial q(T(0)), r(*this);
        while (r.Degree() != -1 && r.Degree() >= other.Degree()) {
            vector<T> tmp(r.Degree() - other.Degree() + 1, T(0));
            tmp.back() = r[r.Degree()] / other[other.Degree()];
            Polynomial t(tmp);
            q += t;
            r -= t * other;
        }
        return r;
    }

    Polynomial operator,(const Polynomial& other) const {
        if (other == Polynomial(T(0))) {
            Polynomial result(*this);
            result = result / Polynomial(result[result.Degree()]);
            return result;
        } else {
            Polynomial r = (*this) % other;
            return (other, r);
        }
    }
};

template<typename T>
ostream& operator<<(ostream& out, const Polynomial<T>& p) {
    if (p.Degree() == -1) {
        out << T(0);
    } else {
        for (auto it = p.end(); it != p.begin(); ) {
            --it;
            int power = it->first;
            T c = it->second;
            if (power != p.Degree() && c > T(0)) {
                out << '+';
            }
            if (power == 0) {
                out << c;
            } else {
                if (c != T(1) && c != T(-1)) out << c << '*';
                if (c == T(-1)) out << '-';
                out << 'x';
                if (power != 1) out << '^' << power;
            }
        }
    }
    return out;
}

