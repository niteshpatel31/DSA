#include <iostream>
#define endl "\n"

struct Node {
  int val;
  Node* nxt;
};

Node *head = new Node{121,nullptr};

void traverse(Node *head){
  Node *temp{head};
  while(temp !=nullptr){
    printf("%i -> ", temp->val);
    temp = temp->nxt;
  }
  printf("nullptr.\n");
}

void insert(Node*& head,const int val){
  Node *temp = new Node();
  temp->val = val;
  temp->nxt = head;
  head = temp;
}

void del(Node *head,const int val){
  Node  *crt{head}, *prev{head};
  while(crt != nullptr){
    if(crt->val == val){
       prev->nxt = crt->nxt;
       delete crt;
       return;
    }
    prev = crt;
    crt = crt->nxt;
  }
}


int main (int argc, char *argv[]) {
  insert(head, 23);
  insert(head, 45);
  insert(head, 65);

  traverse(head);

  del(head,45);
  traverse(head);

  printf("Worked Perfectly!\n");
  return 0;
}
