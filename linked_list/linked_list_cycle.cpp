#include "../common/linked_list.cpp"
#include <bits/stdc++.h>
#include <fmt/format.h>

class Solution {
public:
  bool hasCycle(ListNode *head) {
    std::unordered_set<int> set;
    ListNode *temp{head};
    while (temp) {
    }
    return true;
  }
};

int main() {
  Solution sl;
  const std::vector<int> v1{-21, 10, 17,  8,   4,  26,  5,   35, 33, -7,
                            -16, 27, -12, 6,   29, -12, 5,   9,  20, 14,
                            14,  2,  13,  -24, 21, 23,  -21, 5},
      v2{3, 2, 0, -4}, v3{1, 2};

  ListNode *l1{nullptr}, *l2{nullptr}, *l3{nullptr};
  makeList(l1, v1);
  makeList(l2, v2);
  makeList(l3, v3);

  fmt::println("ans : {}", sl.hasCycle(l1));
  fmt::println("ans : {}", sl.hasCycle(l2));
  fmt::println("ans : {}", sl.hasCycle(l3));

  freeList(l1);
  freeList(l2);
  freeList(l3);
  return EXIT_SUCCESS;
}
