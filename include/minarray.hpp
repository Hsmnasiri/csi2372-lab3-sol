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

    // element access (lvalue overloads)
    int& operator[](std::size_t i) &;
    const int& operator[](std::size_t i) const &;

    // safe access
    std::optional<int> at(std::size_t i) const;

    // modifiers
    void push(int v);
    std::optional<int> pop();

    // algorithms
    std::vector<int> to_sorted() const;
    int max_or(std::string_view label, int fallback) const;

    // value categories (ref-qualified)
    std::vector<int> take() &&;  // rvalue: move out, leave empty
    std::vector<int> take() &;   // lvalue: copy, keep state

private:
    std::vector<int> data_;
};

// free functions
const int& head_ref(const MiniArray& a);
int head_value(MiniArray a);

#endif
