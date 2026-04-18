#include <iostream>
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
        explicit Queue(T val){enqueue(val);}
        ~Queue(){
            while(head!=nullptr){
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
            length++;
            return;
        }
        void dequeue(){
            if(head!=nullptr){
                Node<T> *tmp = head;
                head = head->next;
                delete tmp;
                length--;
                if(head==nullptr)
                    tail = nullptr;
                return;
            }
            else
                length = 0;
            return;
        }
        T peek(){return (head!=nullptr)?head->val:nullptr;}
        bool isEmpty(){return length==0;}
        size_t size(){return this->length;}
};

int main (int argc, char *argv[]) {
    Queue queue("Fuck");
    std::cout<<queue.size()<<endl;
    queue.enqueue("system");
    std::cout<<queue.peek()<<endl;
    std::cout<<std::boolalpha<<queue.isEmpty()<<endl;
    queue.dequeue();
    std::cout<<queue.size()<<endl;
    queue.dequeue();
    std::cout<<queue.size()<<endl;
    std::cout<<std::boolalpha<<queue.isEmpty()<<endl;
    return 0;
}
