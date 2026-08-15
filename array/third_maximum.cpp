#include <bits/stdc++.h>
#include <fmt/base.h>

class Solution {
public:
  int thirdMax(const std::vector<int> &nums) {
    int f{INT_MIN}, s{INT_MIN}, t{INT_MIN};
    for (const int x : nums) {
      if (x > f) {
        t = s;
        s = f;
        f = x;
      } else if (x > s && x != f) {
        t = s;
        s = x;
      } else {
        if (x > t && x != s)
          t = x;
      }
    }
    fmt::println("f: {0}\ts: {1}\tt: {2}", f, s, t);
    if (t < 0 || f == s || s == t)
      return f;
    return t;
  }
};

int main() {
  Solution sl;
  fmt::println("third : {}", sl.thirdMax({3, 2, 1}));
  fmt::println("third : {}", sl.thirdMax({1, 2}));
  fmt::println("third : {}", sl.thirdMax({2, 2, 3, 1}));
  fmt::println("third : {}", sl.thirdMax({1, 2, 2, 5, 3, 5}));
  exit(EXIT_SUCCESS);
}
