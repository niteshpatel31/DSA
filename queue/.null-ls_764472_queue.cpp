#include <iostream>
#include <stdexcept>
#include "../common/node.h"
#define endl "\n"
#define QUEUE_EMPTY std::runtime_error("Queue is Empty!")

template <typename T>
class Queue{
    private:
        Node<T> *tail{nullptr};
        Node<T> *head{nullptr};
        size_t length{0};

    public:
        Queue(){}
        Queue(T val){enqueue(val);}
        ~Queue(){
            while(head!=tail){
                Node<T> *tmp = head;
                head = head->next;
                delete tmp;
            }
        }

        void enqueue(T val){
            Node<T> *tmp = new Node(val);
            if(tail!=nullptr)
                tail->next = tmp;
            else
                head = tmp;
            tail = tmp;
            return;
        }
        void dequeue(){
            if(head!=nullptr){
                Node<T> *tmp = head;
                head = head->next;
                delete tmp;
                return;
            }
            else{
                throw QUEUE_EMPTY;
            }
        }
        T peek(){return (head!=nullptr)?head->val:throw QUEUE_EMPTY;}
        bool isEmpty(){return length==0;}
        size_t size(){return this->length;}
};

int main (int argc, char *argv[]) {
    Queue queue("Fuck");
    queue.enqueue("system");

    std::cout<<queue.peek()<<endl;
    return 0;
}
