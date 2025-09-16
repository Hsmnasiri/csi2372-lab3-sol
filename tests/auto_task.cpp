#include <cassert>
#include "auto_minitask.hpp"

int main() {
    std::vector<int> a{5, 2, 9, 2, 8, 3};     
    assert(sum_prefix_even(a, 2) == 4);       
    assert(sum_prefix_even(a, 3) == 12);     
    assert(sum_prefix_even(a, 10) == 12);     
    std::vector<int> b{};                     
    assert(sum_prefix_even(b, 5) == 0);
    std::vector<int> c{1,3,5};                
    assert(sum_prefix_even(c, 1) == 0);
    return 0;
}
