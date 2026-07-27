#include <bits/stdc++.h>
#include <fmt/base.h>

// class Solution {
// private:
//   const std::unordered_map<int, std::string> map{
//       {1, "I"},  {2, "II"},  {3, "III"}, {4, "IV"},  {5, "V"},
//       {6, "VI"}, {7, "VII"}, {8, "VII"}, {9, "IX"},  {10, "X"},
//       {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}};
//   std::string roman;
//   int temp{}, mul{};
//   inline void reverse(int &n) {
//     temp = n;
//     n = 0;
//     mul = -1;
//     while (temp) {
//       ++mul;
//       n *= 10;
//       n += temp % 10;
//       temp /= 10;
//     }
//   }

// public:
//   std::string intToRoman(int num) noexcept {
//     roman.clear();
//     reverse(num);
//     while (num) {
//       temp *= num % 10 * (std::pow(10, mul));
//       fmt::println("");
//       num /= 10;
//       --mul;
//     }
//     return roman;
//   }
// };

class Solution {
private:
  const std::string ones[10]{"",  "I",  "II",  "III",  "IV",
                             "V", "VI", "VII", "VIII", "IX"};
  const std::string tens[10]{"",  "X",  "XX",  "XXX",  "XL",
                             "L", "LX", "LXX", "LXXX", "XC"};
  const std::string hrns[10] = {"",  "C",  "CC",  "CCC",  "CD",
                                "D", "DC", "DCC", "DCCC", "CM"};
  const std::string ths[4] = {"", "M", "MM", "MMM"};

public:
  std::string intToRoman(int num) {
    return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] +
           ones[num % 10];
  }
};

int main() {
  Solution sl;
  fmt::println("roman: {1} ", 3749, sl.intToRoman(3749));
  // "MMMDCCXLIX"
  fmt::println("roman: {1}", 58, sl.intToRoman(58));     // "LVIII"
  fmt::println("roman: {1}", 1994, sl.intToRoman(1994)); // "MCMXCIV"
  return EXIT_SUCCESS;
}
