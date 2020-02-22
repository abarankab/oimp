#include <cstddef>

template<typename T>
class Vector {
private:
    T * data;
    size_t sz, cp;

public:
    Vector(size_t n = 0) {
        data = static_cast<T*>(::operator new(n * sizeof(T)));
        sz = cp = n;
        for (size_t i = 0; i != n; ++i) {
            new (data + i) T();
        }
    }

    Vector(const Vector& other) {
        data = static_cast<T*>(::operator new(other.sz * sizeof(T)));
        sz = other.sz;
        cp = other.cp;
        for (size_t i = 0; i != sz; ++i)
            new (data + i) T(other.data[i]);
    }

    void pop_back() {
        data[sz - 1].~T();
        --sz;
    }

    ~Vector() {
        for (size_t i = 0; i != sz; ++i)
            data[i].~T();
        ::operator delete(data);
    }
};
