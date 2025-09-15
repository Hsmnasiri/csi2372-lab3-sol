#ifndef MINIARRAY_HPP
#define MINIARRAY_HPP

#include <vector>
#include <cstddef>
#include <optional>
#include <string>
#include <string_view>

class MiniArray {
public:
    MiniArray();
    explicit MiniArray(std::vector<int> init);

    std::size_t size() const noexcept;
    bool empty() const noexcept;

    int& operator[](std::size_t i) &;             // lvalue, non-const
    const int& operator[](std::size_t i) const &; // lvalue, const

    std::optional<int> at(std::size_t i) const;

    void push(int v);
    std::optional<int> pop();

    std::vector<int> to_sorted() const;
    int max_or(std::string_view label, int fallback) const;

    // value categories (ref-qualified)
    std::vector<int> take() &&;  // rvalue → move out, leave empty
    std::vector<int> take() &;   // lvalue → return copy

private:
    std::vector<int> data_;
};

// binding rules / temporary materialization
const int& head_ref(const MiniArray& a);
int head_value(MiniArray a);

#endif
