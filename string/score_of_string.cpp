#include <bits/stdc++.h>
#include <cstdlib>
#include <fmt/base.h>
#include <fmt/format.h>
#include <vector>

class Solution {
public:
  int scoreOfString(const std::string &s) {
    int score{}, size{static_cast<int>(s.size())};
    for (int i{1}; i < size; ++i)
      score += std::abs(s[i - 1] - s[i]);
    return score;
  }
};

int main() {
  Solution sl;
  fmt::println("{}", sl.scoreOfString("hello"));
  return EXIT_SUCCESS;
}
