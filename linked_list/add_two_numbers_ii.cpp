#include "../common/linked_list.cpp"
#include <bits/stdc++.h>

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ans{new ListNode(INT_MAX)}, *temp{ans};
    int carry{0}, sum{};
    while (l1 || l2 || carry) {
      if (l1 != nullptr) {
        sum += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        sum += l2->val;
        l2 = l2->next;
      }
      sum += carry;
      carry = sum / 10;
      temp->next = new ListNode(sum % 10);
      temp = temp->next;
      sum = 0;
    }
    return ans->next;
  }
};

int main() {
  Solution sl;
  std::vector<int> v1{7, 2, 4, 3}, v2{5, 6, 4}, v3{2, 4, 3}, v4{v2}, v5{0},
      v6{v5};
  ListNode *l1, *l2, *l3, *l4, *l5, *l6;
  makeList(l1, v1);
  makeList(l2, v2);
  makeList(l3, v3);
  makeList(l4, v4);
  makeList(l5, v5);
  makeList(l6, v6);


  printList(sl.addTwoNumbers(l1, l2));
  printList(sl.addTwoNumbers(l3, l4));
  printList(sl.addTwoNumbers(l5, l6));

  freeList(l1);
  freeList(l2);
  freeList(l3);
  freeList(l4);
  freeList(l5);
  freeList(l6);
}
