#include <bits/stdc++.h>

class Node {
public:
  int val;
  Node *next{nullptr};
  Node() {}
  Node(int m_data) : val{m_data} {}
};

class MyLinkedList {
private:
  Node *head{};
  Node *tail{};

public:
  MyLinkedList() {}

  int get(int index) {
    int idx{};
    Node *temp{head};
    while (temp) {
      if (idx == index)
        return temp->val;
      temp = temp->next;
      ++idx;
    }
    return -1;
  }

  void addAtHead(int val) {
    Node *tmp = new Node(val);
    tmp->next = head;
    head = tmp;
  }

  void addAtTail(int val) {
    Node *tmp = new Node(val);
    tail->next = tmp;
    tail = tmp;
  }

  void addAtIndex(int index, int val) {
    int idx{};
    Node *tmp{head};
    Node *prev{nullptr};
    while (tmp) {
      if (idx == index) {
        Node *temp = new Node(val);
        prev->next = temp;
        temp->next = tmp;
        break;
      }
      ++idx;
      tmp = tmp->next;
      prev = tmp;
    }
  }

  void deleteAtIndex(int index) {
    int idx{};
    Node *prev{nullptr};
    Node *tmp{head};
    while (tmp) {
      if (idx == index && tmp) {
        prev->next = tmp->next;
        break;
      }
      ++idx;
      tmp = tmp->next;
      prev = tmp;
    }
  }
};

// ---------------- Test cases ----------------

bool test1() { // LeetCode example
  MyLinkedList ll;
  ll.addAtHead(1);
  ll.addAtTail(3);
  ll.addAtIndex(1, 2); // 1->2->3
  int r1 = ll.get(1);  // expect 2
  ll.deleteAtIndex(1); // 1->3
  int r2 = ll.get(1);  // expect 3
  return r1 == 2 && r2 == 3;
}

bool test2() { // get on empty list
  MyLinkedList ll;
  return ll.get(0) == -1;
}

bool test3() { // multiple addAtHead
  MyLinkedList ll;
  ll.addAtHead(1);
  ll.addAtHead(2);
  ll.addAtHead(3); // 3->2->1
  return ll.get(0) == 3 && ll.get(1) == 2 && ll.get(2) == 1;
}

bool test4() { // multiple addAtTail
  MyLinkedList ll;
  ll.addAtTail(1);
  ll.addAtTail(2);
  ll.addAtTail(3); // 1->2->3
  return ll.get(0) == 1 && ll.get(1) == 2 && ll.get(2) == 3;
}

bool test5() { // addAtIndex(0, val) behaves like addAtHead
  MyLinkedList ll;
  ll.addAtTail(2);
  ll.addAtIndex(0, 1); // 1->2
  return ll.get(0) == 1 && ll.get(1) == 2;
}

bool test6() { // addAtIndex(size, val) behaves like addAtTail
  MyLinkedList ll;
  ll.addAtHead(1);
  ll.addAtIndex(1, 2); // 1->2
  return ll.get(0) == 1 && ll.get(1) == 2;
}

bool test7() { // addAtIndex(index > size, val) -> no insertion
  MyLinkedList ll;
  ll.addAtHead(1);
  ll.addAtIndex(5, 10); // ignored
  return ll.get(1) == -1;
}

bool test8() { // deleteAtIndex with invalid index -> no change
  MyLinkedList ll;
  ll.addAtHead(1);
  ll.deleteAtIndex(5); // ignored
  return ll.get(0) == 1;
}

bool test9() { // deleteAtIndex(0) removes the head
  MyLinkedList ll;
  ll.addAtHead(1);
  ll.addAtHead(2);     // 2->1
  ll.deleteAtIndex(0); // 1
  return ll.get(0) == 1;
}

bool test10() { // delete the only node, then add a new head
  MyLinkedList ll;
  ll.addAtHead(7);
  ll.deleteAtIndex(0);
  bool emptyOk = ll.get(0) == -1;
  ll.addAtHead(9);
  return emptyOk && ll.get(0) == 9;
}

int main() {
  std::vector<std::pair<std::string, std::function<bool()>>> tests = {
      {"LeetCode example", test1},
      {"get on empty list", test2},
      {"multiple addAtHead", test3},
      {"multiple addAtTail", test4},
      {"addAtIndex at 0", test5},
      {"addAtIndex equal to length", test6},
      {"addAtIndex greater than length", test7},
      {"deleteAtIndex invalid index", test8},
      {"deleteAtIndex at head", test9},
      {"delete all then re-add", test10},
  };

  for (size_t i = 0; i < tests.size(); i++) {
    bool passed = tests[i].second();
    std::cout << "Test " << (i + 1) << " - " << tests[i].first << ": "
              << (passed ? "[ PASSED ]" : "[ FAILED ]") << std::endl;
  }

  return 0;
}
