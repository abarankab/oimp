#include <iostream>

using namespace std;

int total = 0;

template <typename T>
class Matrix {
private:
    T ** data;
    int cnt;
    size_t rows, columns;

public:
    Matrix(size_t m, size_t n): rows(m), columns(n) {
        cnt = total++;
        cout << "Maxtrix() " << cnt << '\n';
        data = new T * [rows];
        size_t i = 0;
        try {
            for (; i != rows; ++i)
                data[i] = new T[columns];
        } catch (...) {
            for (size_t k = 0; k != i; ++k)
                delete [] data[k];
            delete [] data;
            throw;
        }
    }

    T* operator[](size_t i) {
        return data[i];
    }
    const T* operator[](size_t i) const {
        return data[i];
    }

    size_t GetRows() const {
        return rows;
    }

    size_t GetColumns() const {
        return columns;
    }

    ~Matrix() {
        cout << "~Matrix " << cnt << "\n";
        for (size_t i = 0; i != rows; ++i)
            delete [] data[i];
        delete [] data;
    }

    // Сюда можно будет вставить ваш код
    #include "your_code.h"
};


template <typename T>
Matrix<T> FillMatrix(size_t m, size_t n) {
    cout << "FillMatrix\n";
    Matrix<T> A(m, n);
    for (size_t i = 0; i != m; ++i)
        for (size_t j = 0; j != n; ++j)
            A[i][j] = i + j;
    return A;
}

template <typename T>
std::ostream& operator << (std::ostream& out, const Matrix<T>& A) {
    cout << "<<\n";
    for (size_t i = 0; i != A.GetRows(); ++i) {
        for (size_t j = 0; j != A.GetColumns(); ++j)
            out << A[i][j] << " ";
        out << "\n";
    }
    return out;
}
