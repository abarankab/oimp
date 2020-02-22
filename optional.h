#include <cstring>
#include <utility>
#include <iostream>

// Это исключение нужно генерировать в функции value
// при обращении к пустому объекту Optional
struct BadOptionalAccess {
};

template <typename T>
class Optional {
private:
    // alignas нужен для правильного выравнивания блока памяти
    alignas(T) unsigned char data[sizeof(T)];
    bool defined = false;

public:
    Optional() = default;
    Optional(const T& elem) {
        new (data) T(elem);
        defined = true;
    }
    Optional(T&& elem) {
        new (data) T(std::move(elem));
        defined = true;
    }
    Optional(const Optional& other): defined(other.defined) {
        if (defined) value() = other.value();
    }
    Optional& operator=(const Optional& other) {
        if (defined && other.defined) {
            value() = other.value();
            return *this;
        } else if (!other.defined) {
            reset();
            defined = false;
        } else {
            defined = true;
            new (data) T(other.value());
        }
        return *this;
    }
    Optional& operator=(const T& elem) {
        if (defined) {
            value() = elem;
        } else {
            defined = true;
            new (data) T(elem);
        }
        return *this;
    }
    Optional& operator=(T&& elem) {
        if (defined) {
            value() = std::move(elem);
        } else {
            defined = true;
            new (data) T(std::move(elem));
        }
        return *this;
    }

    bool has_value() const {
        return defined;
    }

    T& operator*() {
        return *reinterpret_cast<T*>(data);
    }
    const T& operator*() const {
        return *reinterpret_cast<const T*>(data);
    }

    T* operator->() {
        return reinterpret_cast<T*>(data);
    }
    const T* operator->() const {
        return reinterpret_cast<const T*>(data);
    }


    T& value() {
        if (!defined) throw BadOptionalAccess();
        return *reinterpret_cast<T*>(data);
    }
    const T& value() const {
        if (!defined) throw BadOptionalAccess();
        return *reinterpret_cast<const T*>(data);
    }

    void reset() {
        if (has_value()) {
            value().~T();
            defined = false;
        }
    }

    ~Optional() {
        if (defined) value().~T();
    }
};
