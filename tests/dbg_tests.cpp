#include <cassert>
#include "debug_utils.hpp"

int main() {
    // find_first_gt
    {
        std::vector<int> a{5,2,9,2};
        assert(find_first_gt(a, 5) == 2);     // first strictly greater than 5 is 9 at idx 2
        assert(find_first_gt(a, 10) == -1);
    }

    // average
    {
        std::vector<int> x{};
        std::vector<int> y{80,90,85};
        assert(average(x) == 0.0);
        double ay = average(y);
        assert(ay > 84.9 && ay < 85.1);       // ~85
    }

    // curve_last_preview: preview should NOT mutate input
    {
        std::vector<int> in{70,75,78};
        std::vector<int> out{};
        curve_last_preview(in, 5, out);
        assert((out == std::vector<int>{70,75,83}));
        assert((in  == std::vector<int>{70,75,78}));
    }

    return 0;
}
