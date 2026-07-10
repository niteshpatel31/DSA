#include <bits/stdc++.h>
#include <cstdlib>
#include <fmt/base.h>
#include <fmt/format.h>

class Solution {
public:
  size_t sumAndMultiply(size_t n) {
    size_t mul{1}, x{}, sum{};
    while (n) {
      if (n % 10) {
        x += (n % 10) * mul;
        sum += n % 10;
        mul *= 10;
      }
      n /= 10;
    }
    return x * sum;
  }
};

int main() {
  Solution sl;
  fmt::println("{}", sl.sumAndMultiply(10203004));
  fmt::println("{}", sl.sumAndMultiply(1000));
  return EXIT_SUCCESS;
}
