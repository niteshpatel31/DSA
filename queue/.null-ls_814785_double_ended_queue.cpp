#include <cstdlib>
#include <iostream>
#include <vector>
#define endl "\n"
#define DEQUEUE_EMPTY std::runtime_error("Dequeue is Empty!")

template <typename T>
class Dequeue{
    private:
        std::vector<T> v;
        int head{-1};
        int tail{-1};
    public:
        Dequeue(){}
        Dequeue(T val): head(0), tail(0){v.emplace_back(val);}
        ~Dequeue(){v.erase(v.begin(), v.end());}

        void pushFront(){
            if(v.size() == 0){1;}
        }
        void pushBack(){}
        void popFront(){}
        void popBack(){}
        T peekFront(){}
        T peekBack(){}
        bool isEmpty(){return v.size()==0;}
        size_t size(){return this->v.size();}
};

int main (int argc, char *argv[]) {
    Dequeue d("something");
    return EXIT_SUCCESS;
}
