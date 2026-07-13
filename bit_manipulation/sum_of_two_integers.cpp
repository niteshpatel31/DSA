#include <bits/stdc++.h>
#include <fmt/base.h>
// class Solution {
// private:
//   int sum;
// int carry;
// int n;

// public:
//   int getSum(int a, int b) {
//     sum = a + b;
//     return sum;
//   }
// };

class Solution {
private:
  std::vector<char> stack;

public:
  Solution() { stack.reserve(1000); }
  int minAddToMakeValid(const std::string &s) noexcept {
    stack.clear();
    for (const char c : s) {
      if (!stack.empty() && stack[stack.size() - 1] == '(' && c == ')')
        stack.pop_back();
      else
        stack.emplace_back(c);
    }
    return static_cast<int>(stack.size());
  }
};

int main() {
  Solution sl;
  fmt::println("{}", sl.minAddToMakeValid("(())"));   // 1
  fmt::println("{}", sl.minAddToMakeValid("()))((")); // 4
  fmt::println("{}", sl.minAddToMakeValid("((("));    // 3
  return EXIT_SUCCESS;
}
