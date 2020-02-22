#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "query.h"

const int RESULTS_TO_PRINT = 3;

int main() {
    std::map<std::string, int> login_stats;
    std::string line;
    while (std::getline(std::cin, line)) {
        Query* q = parse_query(line.c_str());
        if (q->action == ACTION_COMMIT) {
            login_stats[q->sender_login]++;
        }
        delete q;
    }

    std::vector<std::pair<std::string, int>> stats_vec(
        login_stats.begin(), login_stats.end());
    std::sort(stats_vec.begin(), stats_vec.end(), [](auto p, auto q) -> bool {
            return make_pair(-p.second, p.first) < make_pair(-q.second, q.first);
                });

    for (int i = 0; i < RESULTS_TO_PRINT; ++i) {
        std::cout << stats_vec[i].first << " " << stats_vec[i].second << "\n";
    }
}
