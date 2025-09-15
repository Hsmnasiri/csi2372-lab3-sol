#include <iostream>
#include <vector>
int find_first_gt(const std::vector<int>& v, int t) {
    // BUG: starts at 1; misses v[0]
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] >= t) return static_cast<int>(i); // BUG: should be >
    }
    return -1;
}
int main() {
    std::vector<int> a{5, 2, 9, 2};
    int idx = find_first_gt(a, /*t=*/5);
    std::cout << "idx=" << idx << "\n"; // expected: 2 (a[2]=9), actual: 0/-1?
}