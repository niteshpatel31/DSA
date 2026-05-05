#include <cstdlib>
#include "heap.cpp"

template<typename T>
class PriorityQueue{
private:
  Heap<T> queue;

public:
  PriorityQueue(){} 
  PriorityQueue(const T& data){insert(data);}

  void insert(const T& data){queue.insert(data);}
  const T extractMax(){return queue.extractMax();}
  const T& peek()const{return this->queue.peek();}
  const T& size()const{return queue.size();}
  void print(){queue.print();}
};

int main(int argc, const char* argv[]){
  PriorityQueue<int> pq(45);
  pq.insert(367);
  pq.insert(8);
  pq.insert(67);
  fmt::println("max -> {0}", pq.extractMax());
  pq.print();
  return EXIT_SUCCESS;
}
