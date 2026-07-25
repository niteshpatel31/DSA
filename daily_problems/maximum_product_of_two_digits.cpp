#include <bits/stdc++.h>
#include <fmt/base.h>

class Solution {
private:
  int min{}, max{};

public:
  int maxProduct(int n) noexcept {
    min = 0;
    max = 0;
    while (n) {
      if (n % 10 > max) {
        min = max;
        max = n % 10;
      } else {
        if (n % 10 > min)
          min = n % 10;
      }
      fmt::println("n%10: {2}\tmin: {0}\tmax: {1}", min, max, n % 10);
      n /= 10;
    }
    return min * max;
  }
};

int main() {
  Solution sl;
  fmt::println("ans : {0}", sl.maxProduct(31));  // 3
  fmt::println("ans : {0}", sl.maxProduct(22));  // 4
  fmt::println("ans : {0}", sl.maxProduct(124)); // 8
  fmt::println("ans : {0}", sl.maxProduct(20));  // 0
  fmt::println("ans : {0}", sl.maxProduct(890)); // 72
  return EXIT_SUCCESS;
}
