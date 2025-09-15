#include <cassert>
#include "miniarray.hpp"

int main() {
    MiniArray a(std::vector<int>{5,2,9,2});
    assert(a.size()==4 && !a.empty());

    assert(a[0]==5);
    a[2] = 42;                 // تغییر اندیس
    assert(a[2]==42);

    auto v0 = a.at(0);
    auto v4 = a.at(4);
    assert(v0 && *v0==5);
    assert(!v4);

    auto s = a.to_sorted();
    assert((s == std::vector<int>{2,2,5,42}));        // حالا درست
    assert(a[0]==5 && a[1]==2 && a[2]==42 && a[3]==2); // state داخلی دست‌نخورده

    assert(a.max_or("x",-1)==42);
    MiniArray e;
    assert(e.max_or("x",-1)==-1);

    auto last = a.pop();
    assert(last && *last==2);
    a.push(7);
    assert(a.size()==4 && a[3]==7);

    return 0;
}
