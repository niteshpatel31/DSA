#include <bits/stdc++.h>
#include <fmt/format.h>

const std::vector<std::string> mapToChar{{"abc"}, {"def"},  {"ghi"}, {"jkl"},
                                         {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};

class Solution {
private:
  std::vector<std::string> ans;

public:
  explicit Solution() { ans.reserve(144u); }
  std::vector<std::string>
  letterCombinations(const std::string &digits) const noexcept {
    for (size_t i{0}; i < mapToChar[digits[0]-'2'].length(); i++) {
      
      if (digits.size() > 1)
        for (size_t j{0}; i < digits.size(); j++) {
          if (digits.size() > 2)
            for (size_t k{0}; i < digits.size();) {
              if (digits.size() > 3)
                for (size_t l{0}; l < digits.size(); l++) {
                  ans.emplace_back();
                }
            }
        }
    }
    return this->ans;
  }
};

int main() {
  Solution sl;
  const std::string s1{"23"}, s2{"2"};
  fmt::println("ans : {}", sl.letterCombinations(s1));
  fmt::println("ans : {}", sl.letterCombinations(s2));
  return EXIT_SUCCESS;
}
