#include <bits/stdc++.h>
#include <cstdlib>
#include <fmt/base.h>
#include <fmt/format.h>

class Solution {
public:
  bool isSubsequence(const std::string &s, const std::string &t) {
    size_t i{}, j{};
    for (; i < s.size() && j < t.size(); ++j) {
      if (s[i] == t[j])
        ++i;
    }
    return (i == s.size()) ? true : false;
  }
};

int main() {
  Solution sl;
  fmt::println("{}", sl.isSubsequence("abc", "ahbgdc"));
  fmt::println("{}", sl.isSubsequence("axc", "ahbgdc"));
  return EXIT_SUCCESS;
}
