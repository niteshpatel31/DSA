#include <iostream>
#define endl "\n"

struct Node {
  int val;
  Node *prev;
  Node *nxt;
};

void traverse(Node *crt){
  Node *tmp{crt};
  while (tmp != nullptr) {
    printf("%i -> ", tmp->val);
    tmp = tmp->nxt;
  }
  delete tmp;
  printf("nullptr.\n");
}


Node* find(Node* head, const int val){
  Node *tmp = new Node;
  tmp = head;
  while(tmp != nullptr){
    if(tmp->val == val)
      return tmp;
    tmp = tmp->nxt;
  }
  return tmp;
}

void traverse_reverse(Node *tail){
  Node *tmp{tail};
  while(tmp != nullptr){
    printf("%i -> ", tmp->val);
    tmp = tmp->prev;
  }
  printf("nullptr.\n");
}

void insert_after(Node *crt, const int val){
  Node *tmp = new Node{val, nullptr, nullptr};
  if(crt->prev!=nullptr){
     crt->prev->nxt = tmp;
     tmp->prev = crt->prev;
  }
  tmp->prev = crt;
  crt->nxt = tmp;
  return;
}

void insert_before(Node *crt, const int val){
  Node *tmp = new Node{val, nullptr, nullptr};
  if(crt->nxt != nullptr)
    crt->nxt->prev = tmp;
  crt->prev = tmp;
  crt = tmp;
  return;
}

Node *head = new Node{17, nullptr, nullptr};

int main (int argc, char *argv[]) {
  insert_after(head, 224);
  insert_after(head, 333333);
  traverse_reverse(head);
  traverse(head); 
  return 0;
}
