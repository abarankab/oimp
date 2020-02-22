using namespace std;

template<typename Key, typename Value>
bool KeyValueStorage<Key, Value>::find(const Key& key, Value * const value) const {
    auto it = data.find(key);
    if (value != nullptr && it != data.end()) {
        *value = it->second;
    }
    return it != data.end();
}


