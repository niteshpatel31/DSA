#include <bits/stdc++.h>
#include <cstdint>
#include <fmt/base.h>

class Solution {
private:
  int max{}, min{};
  size_t i{};

public:
  int maxProduct(const std::vector<int> &nums) noexcept {
    max = 0;
    min = 1;
    for (i = 1; i < nums.size(); ++i) {
      if (nums[i] >= nums[max]) {
        min = max;
        max = i;
      } else {
        if (nums[i] > nums[min])
          min = i;
      }
      fmt::println("i: {0}\tmin: {1}\tmax: {2}", nums[i], nums[min], nums[max]);
    }
    max = nums[max] - 1;
    min = nums[min] - 1;
    return max * min;
  }
};

int main() {
  Solution sl;
  fmt::println("ans : {}", sl.maxProduct({3, 4, 5, 2}));
  fmt::println("ans : {}", sl.maxProduct({1, 5, 4, 5}));
  fmt::println("ans : {}", sl.maxProduct({3, 7}));
  fmt::println("ans : {}", sl.maxProduct({10, 2, 5, 2}));
  return EXIT_SUCCESS;
}
