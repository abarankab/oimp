#include <algorithm>
#include <cstddef>
#include <functional>

template<typename T>
class SharedPtr {
    private:
    T* p = nullptr;
    size_t* cnt = nullptr;

    void check_empty() {
        if (*cnt == 0) {
            delete p;
            delete cnt;
        }
    }

    public:
    SharedPtr(): p(nullptr), cnt(nullptr) {}
    SharedPtr(T* to): p(to) {
        if (p) cnt = new size_t(1);
    }
    SharedPtr(const SharedPtr& to) {
        p = to.p;
        cnt = to.cnt;
        ++(*cnt);
    }
    SharedPtr(SharedPtr&& to) {
        p = to.p;
        cnt = to.cnt;
        to.p = nullptr;
        to.cnt = nullptr;
    }

    SharedPtr& operator=(T* to) {
        if (p) {
            --(*cnt);
            check_empty();
        }
        p = to;
        if (p) cnt = new size_t(1);
        return *this;
    }
    SharedPtr& operator=(const SharedPtr& to) {
        if (p != to.p) {
            if (p) {
                --(*cnt);
                check_empty();
            }
            p = to.p;
            cnt = to.cnt;
            ++(*cnt);
        }
        return *this;
    }
    SharedPtr& operator=(SharedPtr&& to) {
        if (p != to.p) {
            if (p) {
                --(*cnt);
                check_empty();
            }
            p = to.p;
            cnt = to.cnt;
            to.p = nullptr;
            to.cnt = nullptr;
        }
        return *this;
    }

    ~SharedPtr() {
        if (p) {
            --(*cnt);
            check_empty();
        }
    }

    T& operator*() {
        return *p;
    }

    const T& operator*() const {
        return *p;
    }

    T* operator->() const {
        return p;
    }

    void swap(SharedPtr& other) {
        std::swap(p, other.p);
        std::swap(cnt, other.cnt);
    }

    void reset(T* to) {
        if (p) {
            --(*cnt);
            check_empty();
        }
        p = to;
        if (p) cnt = new size_t(1);
    }

    T* get() const {
        return p;
    }

    explicit operator bool() const {
        return p != nullptr;
    }
};


