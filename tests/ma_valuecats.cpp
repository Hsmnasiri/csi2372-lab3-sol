#include <cassert>
#include <utility>
#include "miniarray.hpp"

int main() {
    MiniArray a(std::vector<int>{3,1,4});
    auto copy1 = a.take(); 
    assert((copy1 == std::vector<int>{3,1,4}));
    assert(a.size()==3 && a[0]==3 && a[1]==1 && a[2]==4);

    auto moved = std::move(a).take(); 
    assert((moved == std::vector<int>{3,1,4}));
    assert(a.size()==0);

    MiniArray tmp(std::vector<int>{8,9});
    const int& h1 = head_ref(tmp);
    assert(h1==8);

    int hv = head_value(MiniArray(std::vector<int>{10,20}));
    assert(hv==10);

    return 0;
}
