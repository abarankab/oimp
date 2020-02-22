#include <unordered_map>

template <typename Key, typename Value>
class KeyValueStorage {
private:
    std::unordered_map<Key, Value> data;

public:
    void insert(const Key& key, const Value& value) {
        data[key] = value;
    }

    void remove(const Key& key) {
        data.erase(key);
    }

    bool find(const Key& key, Value * const value = nullptr) const;
};


// Почему-то не работает...
//
//template <typename Key, typename Value>
//bool KeyValueStorage<Key, Value>::find(const Key& key, Value * const value) const {
//    auto it = std::find(data.begin(), data.end(), key);
//    auto val = *it;
//    if (value != nullptr)
//        value = &val;
//    return it != data.end();
//}


// Ваша реализация функции KeyValueStorage::find будет вставлена сюда:

#include "main.h"
