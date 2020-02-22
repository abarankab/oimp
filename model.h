#include <iostream>
#include <vector>

using namespace std;

class Model {
public:
    std::vector<int> data;

    void save(std::ostream& out) const;
    void load(std::istream& in);
};

void Model::save(std::ostream& out) const {
    size_t sz = data.size();
    out.write(reinterpret_cast<const char *>(&sz), sizeof sz);
    out.write(reinterpret_cast<const char *>(&data[0]), data.size() * sizeof(data[0]));
}

void Model::load(std::istream& in) {
    size_t sz;
    in.read(reinterpret_cast<char *>(&sz), sizeof sz);
    data.resize(sz);
    in.read(reinterpret_cast<char *>(&data[0]), sz * sizeof(data[0]));
}
