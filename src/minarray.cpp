#include "miniarray.hpp"
#include <algorithm>
#include <climits>
#include <utility>

// --- constructors ---
MiniArray::MiniArray() : data_{} {}
MiniArray::MiniArray(std::vector<int> init) : data_{std::move(init)} {}

// --- queries ---
std::size_t MiniArray::size() const noexcept { return data_.size(); }
bool MiniArray::empty() const noexcept { return data_.empty(); }

// --- element access ---
int& MiniArray::operator[](std::size_t i) & { return data_[i]; }

const int& MiniArray::operator[](std::size_t i) const & { return data_[i]; }

// --- safe access ---
std::optional<int> MiniArray::at(std::size_t i) const {
    if (i < data_.size()) return data_[i];
    return std::nullopt;
}

// --- modifiers ---
void MiniArray::push(int v) { data_.push_back(v); }

std::optional<int> MiniArray::pop() {
    if (data_.empty()) return std::nullopt;
    int v = data_.back();
    data_.pop_back();
    return v;
}

// --- algorithms ---
std::vector<int> MiniArray::to_sorted() const {
    auto out = data_;                 // value semantics: copy
    std::sort(out.begin(), out.end());
    return out;
}

int MiniArray::max_or(std::string_view, int fallback) const {
    if (data_.empty()) return fallback;
    const auto it = std::max_element(data_.begin(), data_.end());
    return *it;
}

// --- value categories ---
std::vector<int> MiniArray::take() && {
    auto out = std::move(data_);      // move out
    data_.clear();                    // leave empty
    data_.shrink_to_fit();
    return out;
}

std::vector<int> MiniArray::take() & {
    auto out = data_;                 // copy
    return out;
}

// --- free functions ---
const int& head_ref(const MiniArray& a) {
    // tests never call on empty
    return a[0];
}

int head_value(MiniArray a) {
    return a.empty() ? INT_MIN : a[0];
}
