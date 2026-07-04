#include <bits/stdc++.h>
#include <cstdlib>
#include <fmt/format.h>
#include <functional>
#include <unordered_set>

class Solution {
public:
  int characterReplacement(const std::string &s, int k) const noexcept {
    int max{}, crt{}, idx{}, rep{k};
    std::unordered_set<char> set;
    set.reserve(26);

    for (size_t i{0}; i < s.size(); i++) {
      if (set.find(s[i]) == set.end() {
        ++cur;
        set.insert(s[i]);
      } else if (set.find(s[i]) == set.end())
    }
    return max;
  }
};

int main() {
  Solution sl;
  const std::string s1{"ABAB"}, s2{"AABABBA"};
  fmt::println("ans : {}", sl.characterReplacement(s1, 2));
  fmt::println("ans : {}", sl.characterReplacement(s2, 1));
  return EXIT_SUCCESS;
}
