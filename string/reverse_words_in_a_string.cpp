#include <algorithm>
#include <bits/stdc++.h>
#include <filesystem>
#include <fmt/base.h>

constexpr char SPACE{' '};

class Solution {
public:
  std::string reverseWords(const std::string &s) const noexcept {
    std::string ans, temp;
    ans.reserve(s.size());
    for (int i{static_cast<int>(s.size() - 1)}; i > -1; --i) {
      if (s[i] != SPACE)
        temp.push_back(s[i]);

      if ((s[i] == SPACE || i == 0) && !temp.empty()) {
        std::reverse(temp.begin(), temp.end());
        ans += temp;
        if (i != 0)
          ans.push_back(SPACE);
        temp.clear();
      }
    }
    if (ans[ans.size() - 1] == SPACE)
      ans.erase(ans.end() - 1);

    // for (int i{static_cast<int>(s.size())}; i > -1; --i) {
    //   if (s[i] == SPACE || s[i] > -1) {
    //     reverse(temp.begin(), temp.end());
    //     ans += temp;
    //     ans.push_back(SPACE);
    //     temp.clear();
    //   } else
    //     temp.push_back(s[i]);
    // }
    return ans;
  }
};

int main() {
  Solution sl;
  std::string s1{"the sky is blue"}, s2{"  hello world  "},
      s3{"a good   example"};
  fmt::println("{}", sl.reverseWords(s1));
  fmt::println("{}", sl.reverseWords(s2));
  fmt::println("{}", sl.reverseWords(s3));
  return EXIT_SUCCESS;
}
