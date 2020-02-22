#include <algorithm>
#include <cassert>
#include <iterator>
#include <functional>
#include <vector>

using namespace std;

template<typename T>
class Matrix {
    private:
    vector<T> data;
    size_t N, M;

    public:
    Matrix(const vector<vector<T>>& from) {
        if (from.size()) {
            N = from.size();
            M = from[0].size();
            for (const vector<T>& row : from) {
                data.insert(data.end(), row.begin(), row.end());
            }
        }
    }

    const auto begin() const {
        return data.begin();
    }

    auto begin() {
        return data.begin();
    }

    const auto end() const {
        return data.end();
    }

    auto end() {
        return data.end();
    }

    pair<size_t, size_t> size() const {
        return {N, M};
    }

    size_t height() const {
        return N;
    }

    size_t width() const {
        return M;
    }

    const T& operator[](size_t i) const {
        return data[i];
    }

    Matrix& operator+=(const Matrix& other) {
        transform(begin(), end(),
                  other.begin(),
                  begin(),
                  plus<T>());
        return *this;
    }

    Matrix operator+(const Matrix& other) const {
        auto tmp(*this);
        tmp += other;
        return tmp;
    }
    
    template<typename U>
    Matrix& operator*=(const U& other) {
        transform(begin(), end(),
                  begin(),
                  bind1st(multiplies<T>(), other));
        return *this;
    }

    template<typename U>
    Matrix operator*(const U& other) const {
        auto tmp(*this);
        tmp *= other;
        return tmp;
    }

    Matrix& transpose() {
        vector<T> result(data.size());
        for (size_t i = 0; i < width(); ++i) {
            for (size_t j = 0; j < height(); ++j) {
                result[i * height() + j] = data[j * width() + i];
            }
        }
        data.swap(result);
        swap(N, M);
        return *this;
    }

    Matrix transposed() const {
        auto tmp(*this);
        tmp.transpose();
        return tmp;
    }

    Matrix& operator*=(const Matrix& other) {
        assert(width() == other.height());
        vector<T> result(height() * other.width());
        for (size_t i = 0; i < height(); ++i) {
            for (size_t j = 0; j < other.width(); ++j) {
                for (size_t k = 0; k < width(); ++k) {
                    result[i * other.width() + j] +=
                      data[i * width() + k] *
                     other[k * other.width() + j];
                }
            }
        }
        data.swap(result);
        M = other.width();
        return *this;
    }

    Matrix operator*(const Matrix& other) const {
        auto tmp(*this);
        tmp *= other;
        return tmp;
    }
};

template<typename T>
ostream& operator<<(ostream& out, const Matrix<T>& m) {
    bool printed_row = false;
    for (size_t i = 0; i < m.height(); ++i) {
        if (printed_row) out << '\n';
        bool printed_elem = false;
        for (size_t j = 0; j < m.width(); ++j) {
            if (printed_elem) out << '\t';
            out << m[i * m.width() + j];
            printed_elem = true;
        }
        printed_row = true;
    }
    return out;
}

#include <iostream>
#include <random>

vector<vector<int>> gen_vec(int n, int m) {
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            v[i][j] = rand() % 10;
        }
    }
    return v;
}


int main() {
    auto v1 = gen_vec(4, 3), v2 = gen_vec(4, 2);
    Matrix m1(v1), m2(v2);
    cout << m1 << "\n---\n" << m2 << "\n---\n" << m1.transposed() * m2 << "\n---\n";
    return 0;
}
