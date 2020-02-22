#include <cstddef>

struct Node {
    int data;
    Node* pr = nullptr;
    Node* nx = nullptr;

    Node(const int& elem): data(elem) {}
};

class List {
private:
    size_t sz = 0;
    Node* first;
    Node* last;

    struct Iterator {
        Node* data;
        bool is_end = false;

        Iterator(Node* data, bool is_end = false): data(data), is_end(is_end) {}

        Iterator& operator++() {
            if (!data->nx) {
                is_end = true;
            } else {
                data = data->nx;
            }
            return *this;
        }

        Iterator operator++(int) {
            if (!data->nx) {
                is_end = true;
            } else {
                data = data->nx;
            }
            return *this;
        }

        Iterator& operator--() {
            if (is_end) {
                is_end = false;
            } else {
                data = data->pr;
            }
            return *this;
        }

        Iterator operator--(int) {
            if (is_end) {
                is_end = false;
            } else {
                data = data->pr;
            }
            return *this;
        }

        bool operator==(const Iterator& other) {
            return data == other.data && is_end == other.is_end;
        }

        bool operator!=(const Iterator& other) {
            return !(*this == other);
        }

        int& operator*() {
            return data->data;
        }
    };
public:
    List() {}
    List(const List& other) {
        for (auto it = other.begin(); it != other.end(); ++it) {
            push_back(*it);
        }
    }

    void push_back(const int& elem) {
        Node* node = new Node(elem);
        if (sz) {
            last->nx = node;
            node->pr = last;
            last = node;
        } else {
            first = last = node;
        }
        ++sz;
    }

    void push_front(const int& elem) {
        Node* node = new Node(elem);
        if (sz) {
            first->pr = node;
            node->nx = first;
            first = node;
        } else {
            first = last = node;
        }
        ++sz;
    }

    void pop_back() {
        Node* to_delete = last;
        if (to_delete->pr) to_delete->pr->nx = nullptr;
        last = to_delete->pr;
        --sz;
        delete to_delete;
    }

    void pop_front() {
        Node* to_delete = first;
        if (to_delete->nx) to_delete->nx->pr = nullptr;
        first = to_delete->nx;
        --sz;
        delete to_delete;
    }

    size_t size() const {
        return sz;
    }

    Iterator begin() {
        return Iterator(first);
    }
    const Iterator begin() const {
        return Iterator(first);
    }

    Iterator end() {
        return Iterator(last, true);
    }

    const Iterator end() const {
        return Iterator(last, true);
    }

    List& operator=(const List& other) {
        while (size()) pop_front();
        for (auto it = other.begin(); it != other.end(); ++it) {
            push_back(*it);
        }
        return *this;
    }

    ~List() {
        while (size()) pop_front();
    }
};
