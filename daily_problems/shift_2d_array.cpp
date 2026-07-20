#include <bits/stdc++.h>
#include <fmt/base.h>

class Solution {
public:
  std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>> &grid,
                                          int k) const noexcept {
    if (!k)
      return grid;
    int r = grid.size(), c = grid[0].size();
    int n = r * c;

    k = k % n;
    if (!k)
      return grid;

    auto shift = [&](int i, int j) {
      while (i < j) {
        std::swap(grid[i / c][i % c], grid[j / c][j % c]);
        i++;
        j--;
      }
    };

    shift(0, n - 1);
    shift(0, k - 1);
    shift(k, n - 1);

    return grid;
  }
};

void print_vec(const std::vector<std::vector<int>> &v) noexcept {
  for (const std::vector<int> &x : v) {
    for (const int n : x)
      fmt::print("{}\t ", n);
    fmt::print("\n");
  }
  fmt::print("\n");
  fmt::print("\n");
  return;
}

int main() {
  Solution sl;
  std::vector<std::vector<int>> v1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
      v2{{{3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13}}},
      v3{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  print_vec(sl.shiftGrid(v1, 1));
  print_vec(sl.shiftGrid(v2, 4));
  print_vec(sl.shiftGrid(v3, 9));
}
