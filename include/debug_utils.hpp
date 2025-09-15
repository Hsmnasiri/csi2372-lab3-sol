#ifndef DEBUG_UTILS_HPP
#define DEBUG_UTILS_HPP

#include <vector>

int find_first_gt(const std::vector<int>& v, int t);  // index of first element > t, else -1
double average(const std::vector<int>& v);            // 0.0 for empty
void curve_last_preview(const std::vector<int>& in, int bonus, std::vector<int>& out);
// preview a curved version: 'out' = 'in' with last element += bonus, but DO NOT mutate 'in'

#endif
