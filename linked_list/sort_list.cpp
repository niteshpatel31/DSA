#include "../common/linked_list.cpp"
#include <cstdlib>
#include <fmt/base.h>
#include <functional>
#include <vector>

void print(const std::vector<int> &v) {
  for (const int x : v) {
    fmt::print("{0:d}, ", x);
  }
  fmt::println("");
  return;
}

class Solution {
public:
  ListNode *sortList(ListNode *head) const noexcept {
    std::vector<int> v{};
    while (head) {
      v.push_back(head->val);
      head = head->next;
    }
    std::sort(v.begin(), v.end(), std::less<int>());
    ListNode *result{};
    makeList(result, v);
    return result;
  }
};

int main() {
  const std::vector<int> v1{4, 2, 1, 3}, v2{-1, 5, 3, 4, 0}, v3{};
  ListNode *l1{nullptr}, *l2{nullptr}, *l3{nullptr};
  makeList(l1, v1);
  makeList(l2, v2);
  makeList(l3, v3);

  Solution sl;
  ListNode *s1 = sl.sortList(l1);
  ListNode *s2 = sl.sortList(l2);
  ListNode *s3 = sl.sortList(l3);

  printList(s1);
  printList(s2);
  printList(s3);

  freeList(l1);
  freeList(l2);
  freeList(l3);

  freeList(s1);
  freeList(s2);
  freeList(s3);

  return EXIT_SUCCESS;
}
