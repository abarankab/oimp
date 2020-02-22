#include "writer.h"

class BufferedWriter: public Writer {
private:
    const size_t max_len;
    size_t current_len = 0;
    char * buf;

    void put(char c) {
        buf[current_len++] = c;
        if (current_len == max_len) {
            Writer::Write(buf, current_len);
            current_len = 0;
        }
    }
public:
    BufferedWriter(size_t max_len): max_len(max_len), buf(new char[max_len]) {}
    void Write(const char * data, size_t len) override {
        for (size_t i = 0; i != len; ++i) {
            put(data[i]);
        }
    }

    ~BufferedWriter() {
        Writer::Write(buf, current_len);
        delete[] buf;
    }
};
