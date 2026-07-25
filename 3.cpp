#include <cstdlib>
#include <fmt/base.h>
#include <fmt/format.h>
#include <string>
#include <unordered_set>

class Solution {
private:
  std::unordered_set<char> set;
  int left{}, right{}, max{}, size{};

public:
  Solution() { set.reserve(26); }
  int lengthOfLongestSubstring(const std::string &s) noexcept {
    if (s.size() < 2)
      return s.size();
    max = 0;
    left = 0;
    size = static_cast<int>(s.size());
    for (right = 0; right < size; ++right) {
      if (set.find(s[right]) == set.end()) {
        set.insert(s[right]);
        max = std::max(max, right - left + 1);
      } else {
        while (s[left] != s[right]) {
          set.erase(s[left]);
          ++left;
        }
        set.erase(s[left]);
        ++left;
        set.insert(s[right]);
      }
    }

    return (max) ? max : 1;
  }
};

int main() {
  std::string s1{"abcabcbb"}, s2{"bbbbb"}, s3{"pwwkew"}, s4{"dvdf"}, s5{"au"},
      s6{" "};
  Solution sl;
  fmt::println("{1} : {0}", s1, sl.lengthOfLongestSubstring(s1));
  fmt::println("{1} : {0}", s2, sl.lengthOfLongestSubstring(s2));
  fmt::println("{1} : {0}", s3, sl.lengthOfLongestSubstring(s3));
  fmt::println("{1} : {0}", s4, sl.lengthOfLongestSubstring(s4));
  fmt::println("{1} : {0}", s5, sl.lengthOfLongestSubstring(s5));
  fmt::println("{1} : {0}", s6, sl.lengthOfLongestSubstring(s6));
  return EXIT_SUCCESS;
}
