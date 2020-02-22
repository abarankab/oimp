template<typename it, typename Pred> bool any_of(it first, it last, Pred f) {
    while (first != last) {
        if (f(*first)) return true;
        ++first;
    }
    return false;
}

