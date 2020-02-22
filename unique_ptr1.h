#include <algorithm>
#include <cstddef>
#include <functional>
#include <memory>
#include <tuple>

using namespace std;

template<typename T, typename Deleter = default_delete<T>>
class UniquePtr {
    private:
    tuple<T*, Deleter> p;

    public:
    UniquePtr(T* to = nullptr): p(make_tuple(to, Deleter())) {};
    UniquePtr(T* to, const Deleter& deleter): p(make_tuple(to, deleter)) {}
    UniquePtr(UniquePtr&& to) {
        p = to.p;
        to.p = make_tuple(nullptr, Deleter());
    }

    UniquePtr& operator=(nullptr_t null) {
        if (std::get<0>(p)) std::get<1>(p)(std::get<0>(p));
        std::get<0>(p) = null;
        return *this;
    }
    UniquePtr& operator=(UniquePtr&& to) {
        if (std::get<0>(p)) std::get<1>(p)(std::get<0>(p));
        p = to.p;
        to.p = make_tuple(nullptr, Deleter());
        return *this;
    }

    ~UniquePtr() {
        if (std::get<0>(p)) std::get<1>(p)(std::get<0>(p));
    }

    T& operator*() const {
        return *std::get<0>(p);
    }

    T* operator->() const {
        return std::get<0>(p);
    }

    T* release() {
        auto tmp = std::get<0>(p);
        std::get<0>(p) = nullptr;
        return tmp;
    }

    void reset(T* to) {
        T* tmp = std::get<0>(p);
        std::get<0>(p) = to;
        if (tmp) std::get<1>(p)(tmp);
    }

    void swap(UniquePtr& to) {
        std::swap(p, to.p);
    }

    T* get() const {
        return std::get<0>(p);
    }

    explicit operator bool() const {
        return std::get<0>(p) != nullptr;
    }

    const Deleter& get_deleter() const {
        return std::get<1>(p);
    }

    Deleter& get_deleter() {
        return std::get<1>(p);
    }
};

