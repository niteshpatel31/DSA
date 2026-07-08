#include "../common/vector.h"
#include <bits/stdc++.h>
#include <cstddef>
#include <fmt/base.h>
#include <fmt/format.h>

class Solution {
public:
  void rotate(std::vector<int> &nums, size_t k) const noexcept {
    if (k == 0 || nums.size() == k || nums.size() < 2)
      return;
    if (k > nums.size())
      k = k % nums.size();
    int n{static_cast<int>(nums.size())};
    int temp[n];
    for (int i{0}; i < n; ++i) {
      temp[(i + k) % n] = nums[i];
    }
    for (int i = 0; i < n; i++) {
      nums[i] = temp[i];
    }
    return;
  }
};

int main() {
  Solution sl;
  std::vector<int> v1{1, 2, 3, 4, 5, 6, 7}, v2{-1, -100, 3, 99}, v3{1, 2},
      v4{1, 2}, v5{1, 2}, v6{1, 2, 3, 4, 5};
  sl.rotate(v1, 3);
  nc::print_vec(v1);
  sl.rotate(v2, 2);
  nc::print_vec(v2);
  sl.rotate(v3, 7);
  nc::print_vec(v3);
  sl.rotate(v4, 0);
  nc::print_vec(v4);
  sl.rotate(v5, 1);
  nc::print_vec(v5);
  sl.rotate(v6, 11);
  nc::print_vec(v6);
}
