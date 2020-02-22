#include <stdexcept>
#include <optional>
#include <map>

using namespace std;

template <typename Key1, typename Key2, typename Value>
class BiMap {
    map<Key1, Value> m1;
    map<Key2, Value> m2;
public:
    // Вставить значение, указав один или оба ключа.
    // Генерирует исключение std::invalid_argument("some text") в случае,
    // если оба ключа пусты, либо один из ключей уже имеется в хранилище.
    void Insert(const std::optional<Key1>& key1, const std::optional<Key2>& key2, const Value& value) {
        if ((!key1.has_value() && !key2.has_value()) || m1.find(key1.value()) != m1.end() || m2.find(key2.value()) != m2.end()) throw invalid_argument("some_text");
    }       

    // Получить значение по ключу первого типа.
    // Генерирует исключение std::out_of_range("some text")
    // в случае отсутствия ключа (как и функция at в std::map).
    Value& GetByPrimaryKey(const Key1& key);
    const Value& GetByPrimaryKey(const Key1& key) const {
        if (m1.find(key) == m1.end()) throw out_of_range("some text");
        return *m1.find(key);
    }

    // Аналогичная функция для ключа второго типа.
    Value& GetBySecondaryKey(const Key2& key);
    const Value& GetBySecondaryKey(const Key2& key) const {
        if (m2.find(key) != m2.end()) throw out_of_range("some text");
        return *m2.find(key);
    }
};
