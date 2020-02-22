#include "classifiers_test.h"
#include <optional>

using namespace std;

class CombinedClassifier {
private:
    string main_constructor_;
    optional<MainClassifier> main_;
    FastClassifier fast_;
public:
    CombinedClassifier(const string& s1, const string& s2): fast_(s1), main_constructor_(s2) {}

    double classify(const string& s) {
        double result;
        try {
            result = fast_.classify(s);
        } catch(const TooHardObjectException& e) {
            if (!main_.has_value()) {
                main_ = MainClassifier(main_constructor_);
            }
            result = main_->classify(s);
        }
        return result;
    }
};

int main() {
    CombinedClassifier c("123", "233");
    cout << c.classify("hard text") << endl;
}
