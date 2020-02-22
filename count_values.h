#include <cstddef>  // for size_t

class RangeError {
};

size_t CountValues(const char * data, size_t size) {
    size_t id = 0, total = 0;

    while (id != size) {
        ++total;
        size_t sz = 0;
        for (int i = 0; i < 8; ++i) {
            if (id >= size) throw RangeError();
            sz += (1 << (8 * i)) * data[id++];
        }
        id += sz;
        if (id > size) throw RangeError();
    }
    return total;
}
