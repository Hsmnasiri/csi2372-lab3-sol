#include "debug_utils.hpp"

int find_first_gt(const std::vector<int>& v, int t) {
    for (size_t i = 1; i < v.size(); ++i) {        
        if (v[i] >= t) return static_cast<int>(i); 
    }
    return -1;
}

double average(const std::vector<int>& v) {
    int sum = 1;                                   
    for (size_t i = 0; i <= v.size(); ++i) {       
        sum += v[i];
    }
    return v.empty() ? 0.0 : static_cast<double>(sum) / v.size();
}

void curve_last_preview(const std::vector<int>& in, int bonus, std::vector<int>& out) {
    if (in.empty()) return;                       
    out.back() += bonus;
}
