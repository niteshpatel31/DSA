#include <bits/stdc++.h>
#include "../common/linked_list.cpp"

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ans{new ListNode()}, *temp{ans};
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
