#include "../common/vector.h"
#include <bits/stdc++.h>
#include <cstdlib>
#include <fmt/base.h>
#include <fmt/format.h>
typedef unsigned int uint128_t __attribute__((mode(TI)));

class Solution {
public:
  std::vector<int>
  sumAndMultiply(const std::string &s,
                 const std::vector<std::vector<int>> &q) const noexcept {
    if (q.empty() || q.empty())
      return {};
    std::vector<int> ans;
    ans.reserve(q.size());

    for (const std::vector<int> &v : q) {
      size_t num{}, sum{}, mul{1}, temp{};
      temp = std::atol(
          std::string(s.begin() + v[0], s.begin() + v[1] + 1).c_str());
      while (temp) {
        if (temp % 10) {
          num += temp % 10 * mul;
          sum += temp % 10;
          mul *= 10;
        }
        temp /= 10;
      }
      uint128_t x = num * sum;
      if (x > INT_MAX)
       x %= 1000000007;
      ans.emplace_back(x);
    }

    return ans;
  }
};

int main() {
  Solution sl;
  const std::string s1{"10203004"}, s2{"1000"}, s3{"9876543210"},
      s4{"941983443"};
  std::vector<std::vector<int>> v1{{0, 7}, {1, 3}, {5, 6}}, v2{{0, 3}, {1, 1}},
      v3{{0, 9}},
      v4{{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8},
         {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 6}, {1, 8}, {2, 2}, {2, 3},
         {2, 4}, {2, 6}, {2, 7}, {2, 8}, {3, 4}, {3, 5}, {3, 6}, {3, 7},
         {3, 8}, {4, 4}, {4, 5}, {4, 6}, {4, 8}, {5, 5}, {5, 6}, {5, 7},
         {5, 8}, {6, 7}, {7, 7}, {7, 8}};
  nc::print_vec(sl.sumAndMultiply(s1, v1));
  nc::print_vec(sl.sumAndMultiply(s2, v2));
  nc::print_vec(sl.sumAndMultiply(s3, v3));
  nc::print_vec(sl.sumAndMultiply(s4, v4));
  return EXIT_SUCCESS;
}
