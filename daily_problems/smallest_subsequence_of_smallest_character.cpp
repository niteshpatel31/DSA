#include <bits/stdc++.h>
#include <fmt/base.h>

/*
class Solution {
private:
    char stackArr[26];   // reused every call — no heap, no re-init cost beyond
memset int  freq[26];        // reused every call

public:
    string smallestSubsequence(const string& s) noexcept {
        std::memset(freq, 0, sizeof(freq));   // cheap: 26 ints, vectorized by
compiler

        for (unsigned char c : s)
            ++freq[c - 'a'];

        int top = 0;
        uint32_t inStack = 0;

        for (unsigned char c : s) {
            int x = c - 'a';
            --freq[x];

            if (inStack & (1u << x))
                continue;

            while (top > 0 && stackArr[top - 1] > c &&
                   freq[stackArr[top - 1] - 'a'] > 0) {
                inStack &= ~(1u << (stackArr[--top] - 'a'));
            }
            stackArr[top++] = c;
            inStack |= (1u << x);
        }
        return string(stackArr, top);   // only unavoidable allocation: the
return value
    }
};

*/

class Solution {
private:
  std::string stack;
  int freq[26];

public:
  Solution() { stack.reserve(26u); };
  std::string smallestSubsequence(const std::string &s) noexcept {
    stack.clear();
    for (int x{}; x < 26; ++x)
      freq[x] = 0;
    std::bitset<26> seen;

    for (auto c : s)
      freq[c & 31]++;

    for (auto c : s) {
      int x = c & 31;
      freq[x]--;

      if (seen.test(x))
        continue;

      while (stack.length() && stack.back() > c && freq[stack.back() & 31]) {
        seen.reset(stack.back() & 31);
        stack.pop_back();
      }

      stack.push_back(c);
      seen.set(x);
    }

    return stack;
  }
};

int main() {
  Solution sl;
  fmt::println("{}", sl.smallestSubsequence("bcabc"));    // abc
  fmt::println("{}", sl.smallestSubsequence("cbacdcbc")); // abcdb
  return EXIT_SUCCESS;
}
