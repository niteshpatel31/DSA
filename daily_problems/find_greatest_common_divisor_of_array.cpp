#include <bits/stdc++.h>
#include <fmt/base.h>

class Solution {
private:
  int gcd(int a, int b) const noexcept {
    while (b) {
      const int temp = b;
      b = a % b;
      a = temp;
    }
    return a;
  }

public:
  int findGCD(const std::vector<int> &nums) const noexcept {
    int max{INT_MIN}, min{INT_MAX};
    for (const int x : nums) {
      if (x > max)
        max = x;
      if (x < min)
        min = x;
    }
    return gcd(max, min);
  }
};

int main() {
  Solution sl;
  fmt::println("{}", sl.findGCD({2, 5, 6, 9, 10}));
  fmt::println("{}", sl.findGCD({7, 5, 6, 8, 3}));
  fmt::println("{}", sl.findGCD({2, 5, 6, 9, 10}));
  return EXIT_SUCCESS;
}
