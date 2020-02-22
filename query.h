#include <iostream>
#include <string>
#include <sstream>

const int ACTION_LIST = 1;
const int ACTION_PRINT = 2;
const int ACTION_COMMIT = 3;
const int ACTION_HELP = 4;

struct Query {
    int time;
    char sender_login[256];
    int action;
    char text[4096];
};

Query* parse_query(const char* str) {
    Query* q = new Query;
    
    std::stringstream s(str);
    s >> q->time >> q->sender_login >> q->action;

    return q;
}