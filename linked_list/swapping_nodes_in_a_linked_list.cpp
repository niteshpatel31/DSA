#include "../common/linked_list.cpp"
#include <cstdlib>
#include <iostream>

class Solution {
public:
  ListNode *swapNodes(ListNode *&head, int k) const noexcept {
    if (!head || !head->next)
      return head;
    ListNode *fast{head}, *slow{head}, *first{nullptr};
    int sc{}, fc{};
    while (slow) {
      ++sc;
      if (fast) {
        if (fast->next) {
          fast = fast->next->next;
          fc += 2;
        } else {
          fast = fast->next;
          ++fc;
        }
      }
      fmt::print("sc:{0}, fc:{1}, sv:{2}", sc, fc, slow->val);
      if (fast)
        fmt::print(", fv:{}", fast->val);
      fmt::println("");
      if (k == sc)
        first = slow;

      if (sc == fc - k)
        break;
      else
        slow = slow->next;
    }
    fc = slow->val;
    slow->val = first->val;
    first->val = fc;
    return head;
  }
};

int main() {
  Solution sl;
  const std::vector<int> v1{1, 2, 3, 4, 5}, v2{7, 9, 6, 6, 7, 8, 3, 0, 9, 5};
  ListNode *l1{}, *l2{};
  makeList(l1, v1);
  makeList(l2, v2);
  sl.swapNodes(l1, 2);
  printList(l1);
  sl.swapNodes(l2, 5);
  printList(l2);
  freeList(l1);
  freeList(l2);
  return EXIT_SUCCESS;
}
