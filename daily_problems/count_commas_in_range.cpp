#include <bits/stdc++.h>
#include <fmt/base.h>
#include <fmt/format.h>

class Solution {
private:
  // constexpr std::unordered_map<int, int> mp{{4,1000}, };
public:
  [[gnu::always_inline]] inline int countCommas(const int n) const noexcept {
    int temp{n};
    int digits{};
    while (temp) {
      temp >>= 1;
      ++digits;
    }

    return (digits > 3) ? n - 999 : 0;
  }
};

int main() {

  Solution sl;
  fmt::println("ans : {}", sl.countCommas(1344));
  fmt::println("ans : {}", sl.countCommas(998));
  fmt::println("ans : {}", sl.countCommas(1002));
  return EXIT_SUCCESS;
}
