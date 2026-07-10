#include <bits/stdc++.h>
#include <cstdlib>
#include <fmt/base.h>
#include <fmt/format.h>

class Solution {
public:
  int search(const std::vector<int> &nums, int target) const noexcept {
    int idx{static_cast<int>(nums.size()) - 1};
    for (; idx >= 0; --idx)
      if (nums[idx] == target)
        return idx;

    return -1;
  }
};

int main() {
  Solution sl;
  std::vector<int> v1{4, 5, 6, 7, 0, 1, 2}, v2{4, 5, 6, 7, 0, 1, 2}, v3{1};
  fmt::println("{}", sl.search(v1, 0));
  fmt::println("{}", sl.search(v2, 3));
  fmt::println("{}", sl.search(v3, 0));
  return EXIT_SUCCESS;
}
