#ifndef AUTO_MINITASK_HPP
#define AUTO_MINITASK_HPP

#include <vector>
#include <cstddef>

// Sum of the first n even numbers in v (in order). If n > available, sum all evens.
// REQUIREMENTS (style): in the .cpp you MUST use:
//  - 'auto' at least twice (e.g., iterator, accumulator, loop binding)
//  - list-initialization '{}' at least once (e.g., constructing a container or value)
long long sum_prefix_even(const std::vector<int>& v, std::size_t n);

#endif
