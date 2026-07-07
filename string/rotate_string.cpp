#include <bits/stdc++.h>
#include <cstdlib>
#include <fmt/format.h>

class Solution {
public:
  bool rotateString(std::string &s, const std::string &g) const noexcept {
    if (s.size() != g.size())
      return false;
    s += s;
    return s.find(g) != std::string::npos;
  }
};

int main() {
  std::string s1{"abcde"}, s2{"abcde"}, g1{"cdeab"}, g2{"abced"};
  Solution sl;
  fmt::println("{0} : {1} ->  {2}", s1, g1, sl.rotateString(s1, g1));
  fmt::println("{0} : {1} ->  {2}", s2, g2, sl.rotateString(s2, g2));
  return EXIT_SUCCESS;
}
