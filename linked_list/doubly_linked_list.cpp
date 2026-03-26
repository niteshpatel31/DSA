#include <iostream>
#define endl "\n"

struct Node {
  int val;
  Node *prev;
  Node *nxt;
};

void traverse(Node *head){
  Node *tmp{head};
  while (tmp != nullptr) {
    printf("%i -> ", tmp->val);
    tmp = tmp->nxt;
  }
  delete tmp;
  printf("nullptr.\n");
}

void traverse_reverse(Node *tail){
  Node *tmp{tail};
  while(tmp != nullptr){
    printf("%i -> ", tmp->val);
    tmp = tmp->prev;
  }
  delete tmp;
  printf("nullptr.\n");
}

void insert_after(Node *head, const int val){
  Node *tmp = new Node{val, nullptr, nullptr};
  tmp->prev = head;
  head->nxt = tmp;
  head = tmp;
  return;
}

void insert_before(Node *tail, const int val){
  Node *tmp = new Node{val, nullptr, nullptr};
  tmp->prev = tail;
  tail->nxt =  tmp;
  tail = tmp;
  return;
}

Node *head = new Node{17, nullptr, nullptr};
Node *tail = new Node{81, nullptr, nullptr};

int main (int argc, char *argv[]) {
  head -> nxt = tail;
  tail -> prev = head;
  insert_before(tail, 234);
  insert_after(head, 224);
  traverse(head); 
  traverse_reverse(tail);
  return 0;
}
