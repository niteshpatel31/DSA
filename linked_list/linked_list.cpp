#include <iostream>

#define endl '\n'

struct Node {
  int data;
  Node* next= nullptr;
};

int main (int argc, char *argv[]) {
  Node *head;
  head->data = 435;
  Node *tail = nullptr;
  head->next = tail;
  std::cout<<head->data<<" : "<<tail<<endl;
  return 0;
}
