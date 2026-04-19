#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
#define endl "\n"
#define DEQUEUE_EMPTY std::runtime_error("Dequeue is Empty!")

template <typename T>
class Dequeue{
    private:
        std::vector<T> v;
        int head{-1};
        int tail{-1};
        int mid{-1};

        void resize(){
            v.resize(v.size()*2+v.size()*1.5);
            mid = v.size()/2;
            head = mid;
            tail = head+tail;
            std::move(v.begin(), v.end(), v.begin()+mid);
        }
    public:
        Dequeue(){}
        Dequeue(T val): head(0), tail(0){v.emplace_back(val);}
        ~Dequeue(){v.erase(v.begin(), v.end());}

        void pushFront(T val){
            if(v.size() == 0){v.emplace_back(val); head=0; tail=0;}
            if(head==0){
                this->resize();
                v[--head] = val;
            }
        }
        void pushBack(T val){
            if(v.size()==0){v.emplace_back(val); head = 0, tail = 0;}
            if(tail==v.capacity()-1){
                this->resize();
                v[++tail] = val;
            }
        }
        void popFront(){
            if(isEmpty()) throw DEQUEUE_EMPTY;
            else++head;
        }
        void popBack(){
            if(isEmpty()) throw DEQUEUE_EMPTY;
            else--tail;
        }
        T peekFront(){return (isEmpty())?throw DEQUEUE_EMPTY: this->v[head];}
        T peekBack(){return (isEmpty())?throw DEQUEUE_EMPTY: this->v[tail];}
        bool isEmpty(){return tail-head<0;}
        size_t size(){return (isEmpty())?0:tail-head+1;}

        void print(){
            for(int i = head; i<= tail; i++)
                std::cout<<v[i]<<", ";
            std::cout<<endl;
        }
};

int main (int argc, char *argv[]) {
    Dequeue d("something");
    d.pushBack("fuck");
    d.pushBack("java");
    d.print();
    std::cout<<d.size()<<endl;
    d.popBack();
    std::cout<<d.peekFront()<<endl;
    std::cout<<d.peekBack()<<endl;
    return EXIT_SUCCESS;
}
