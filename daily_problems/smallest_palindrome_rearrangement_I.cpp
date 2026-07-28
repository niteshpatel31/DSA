#include <bits/stdc++.h>
#include <fmt/base.h>
class Solution {
private:
  int n, i, idx, counts[26];

public:
  std::string smallestPalindrome(std::string &s) noexcept {
    n = s.size();
    for (i = 0; i < 26; ++i)
      counts[i] = 0;
    for (i = 0; i < n / 2; ++i)
      ++counts[s[i] - 'a'];

    idx = -1;
    for (i = 0; i < 26; ++i) {
      while (--counts[i] > -1)
        s[++idx] = static_cast<char>(i + 'a');
    }

    for (i = 0; i < n / 2; ++i)
      s[n - 1 - i] = s[i];

    return s;
  }
};

int main() {
  Solution sl;
  return EXIT_SUCCESS;
}
