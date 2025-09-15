#include "debug_utils.hpp"

int find_first_gt(const std::vector<int>& v, int t) {
    for (size_t i = 0; i < v.size(); ++i)
        if (v[i] > t) return static_cast<int>(i);
    return -1;
}

double average(const std::vector<int>& v) {
    if (v.empty()) return 0.0;
    int sum = 0;
    for (size_t i = 0; i < v.size(); ++i) sum += v[i];
    return static_cast<double>(sum) / v.size();
}

void curve_last_preview(const std::vector<int>& in, int bonus, std::vector<int>& out) {
    out = in;                // copy for preview
    if (!out.empty()) out.back() += bonus;
}