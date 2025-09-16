#include "auto_minitask.hpp"
#include <algorithm>

long long sum_prefix_even(const std::vector<int>& v, std::size_t n) {
    long long result{0};                      // list-initialization
    std::size_t count{0};

    for (auto it = v.begin(); it != v.end(); ++it) {  // auto with iterator
        if (*it % 2 == 0) {
            result += static_cast<long long>(*it);
            ++count;
            if (count == n) break;
        }
    }

    return result;
}
