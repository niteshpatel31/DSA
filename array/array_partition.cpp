#include <bits/stdc++.h>
#include <fmt/base.h>
#include <fmt/format.h>

class Solution {
public:
  int arrayPairSum(std::vector<int> &nums) const noexcept {
    std::sort(nums.begin(), nums.end());
    int sum{};
    for (size_t i{}; i < nums.size(); i += 2)
      sum += nums[i];
    return sum;
  }
};

int main() {
  Solution sl;
  std::vector<int> v1{1, 4, 3, 2}, v2{6, 2, 6, 5, 1, 2};
  fmt::println("{}", sl.arrayPairSum(v1));
  fmt::println("{}", sl.arrayPairSum(v2));
}
