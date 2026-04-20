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
            // TODO: instead of inplace std::move move to new temp vec
            mid = v.size()/2;
            head = mid;
            tail = head+tail;
            std::move(v.begin(), v.end(), v.begin()+mid);
            this->print();
            std::cout<<"head -> "<<head<<", tail -> "<<tail<<endl;
            std::cout<<"size : "<<this->size()<<", vec.size : "<<v.size()<<endl;
            return;
        }
    public:
        Dequeue(){}
        Dequeue(T val): head(0), tail(0){v.emplace_back(val);}
        ~Dequeue(){v.erase(v.begin(), v.end());}

        void pushFront(T val){
            if(v.size() == 0){v.emplace_back(val); head=0; tail=0; return;}
            if(head==0)
                this->resize();
            v[--head] = val;
        }
        void pushBack(T val){
            if(v.size()==0){v.emplace_back(val); head=0; tail=0;\   ``             return;}
            if(tail==v.capacity()-1)this->resize();
            v[++tail] = val;
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
        bool isEmpty(){return tail<head;}
        size_t size(){return (isEmpty())?0:tail-head+1;}

        void print(){
            for(auto e : v)
                std::cout<<e<<", ";
            std::cout<<endl;
            return;
        }
};

int main (int argc, char *argv[]) {
    std::cout<<endl<<"----Numbers----"<<endl;
    Dequeue<int> num(567);
    num.pushBack(234);
    num.pushBack(345);
    num.pushFront(67);
    num.pushFront(89);
    num.pushFront(90);
    num.popBack();


    std::cout<<endl<<"----std::string----"<<endl;
    Dequeue<std::string> d("something");
    d.pushBack("fuck");
    d.pushBack("asdf");
    d.pushFront("data");
    d.pushFront("data");
    d.pushFront("data");
    d.popBack();

    std::cout<<endl<<"----const char*----"<<endl;
    Dequeue<const char*> c("something");
    c.pushBack("fuck");
    c.pushBack("asdf");
    c.pushFront("data");
    c.pushFront("data");
    c.pushFront("data");
    c.popBack();
    return EXIT_SUCCESS;
}
