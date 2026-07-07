#include <bits/stdc++.h>
#include <cstddef>
#include <fmt/format.h>

void printVec(const std::vector<int> &v) noexcept {
  for (const int e : v)
    fmt::print("{}, ", e);
  fmt::println("");
  return;
}

class Solution {
public:
  void rotate(std::vector<int> &nums, size_t k) const noexcept {
    if (nums.size() < 2 || nums.size() == k)
      return;
    k = nums.size() - k;
    nums.reserve(nums.size() + k);
    for (size_t i{}; i < k; ++i)
      nums.emplace_back(nums[i]);
    nums.erase(nums.begin(), nums.begin() + k);
    return;
  }
};

int main() {
  Solution sl;
  std::vector<int> v1{1, 2, 3, 4, 5, 6, 7}, v2{-1, -100, 3, 99};
  sl.rotate(v1, 3);
  printVec(v1);
  sl.rotate(v2, 2);
  printVec(v2);
}
