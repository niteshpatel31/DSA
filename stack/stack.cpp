#include <iostream>
#include "../common/node.h"
#define endl "\n"

template <typename T>
class Stack{
    private:
        Node<T> *top{nullptr};

    public:
        Stack():top(nullptr){}
        Stack(T val){this->push(val);}
        ~Stack(){
            while (top!=nullptr) {
                Node<T> *tmp = top;
                top = top->next;
                delete tmp;
            }
        }

        void push(T val){
            Node<T> *tmp = new Node(val);
            if(top!=nullptr)tmp->next = top;
            top = tmp;
            return;
        }
        void pop(){
            if(this->top!=nullptr){
                Node<T> *tmp = this->top;
                top = top->next;
                delete tmp;
            }
            return;
        }
        T peek(){return (top==nullptr)?throw
            std::runtime_error("Motherfuck Stack is empty"):top->data;}
};

int main (int argc, char *argv[]) {
    Stack stack("System");
    std::cout<<"top : "<<stack.peek()<<endl;
    stack.push("fuck");
    std::cout<<"top : "<<stack.peek()<<endl;
    stack.push("you");
    std::cout<<"top : "<<stack.peek()<<endl;
    stack.push("bitch");
    std::cout<<"top : "<<stack.peek()<<endl;
    std::cout<<"top : "<<stack.peek()<<endl;
    stack.pop();
    std::cout<<"top : "<<stack.peek()<<endl;
    stack.pop();
    std::cout<<"top : "<<stack.peek()<<endl;
    stack.pop();
    stack.pop();
    std::cout<<"top : "<<stack.peek()<<endl;
    stack.push("fuck");
    std::cout<<"top : "<<stack.peek()<<endl;
    std::cout<<"top : "<<stack.peek()<<endl;
    return 0;
}
