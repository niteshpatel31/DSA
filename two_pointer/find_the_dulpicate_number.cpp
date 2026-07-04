#include <bits/stdc++.h>
#include <cstdlib>
#include <fmt/format.h>
#include <unordered_set>

class Solution {
public:
  int findDuplicate(std::vector<int> &v) const noexcept {
    std::sort(v.begin(), v.end());
    int _xor{0};
    for (size_t i{1}; i < v.size(); i++) {
      _xor = v[i] ^ v[i - 1];
      if (!_xor)
        return v[i];
    }

    return 0;
  }
};

int main() {
  Solution sl;
  std::vector<int> v1{1, 3, 4, 2, 2}, v2{3, 1, 3, 4, 2}, v3{3, 3, 3, 3, 3};
  fmt::println("ans : {}", sl.findDuplicate(v1));
  fmt::println("ans : {}", sl.findDuplicate(v2));
  fmt::println("ans : {}", sl.findDuplicate(v3));
  return EXIT_SUCCESS;
}
