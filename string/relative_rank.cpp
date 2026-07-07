#include "../common/vector.h"
#include <bits/stdc++.h>
#include <fmt/format.h>
#include <string>

class Solution {
public:
  std::vector<std::string>
  findRelativeRanks(const std::vector<int> &score) const noexcept {
    std::vector<std::string> ans(score.size(), "");
    std::map<int, int> map;
    for (size_t i{}; i < score.size(); ++i)
      map.insert({score[i], i});

    size_t i{};

    for (auto it{map.rbegin()}; it != map.rend();) {
      ++i;
      switch (i) {
      case 1:
        ans[it->second] = "Gold Medal";
        break;
      case 2:
        ans[it->second] = "Silver Medal";
        break;
      case 3:
        ans[it->second] = "Bronze Medal";
        break;
      default:
        ans[it->second] = std::to_string(i);
        break;
      }
      ++it;
    }
    return ans;
  }
};

int main() {
  Solution sl;
  const std::vector<int> v1{5, 4, 3, 2, 1}, v2{10, 3, 8, 9, 4};
  nc::print_vec(sl.findRelativeRanks(v1));
  nc::print_vec(sl.findRelativeRanks(v2));
}
