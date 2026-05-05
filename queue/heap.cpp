#include <cstdint>
#include <fmt/base.h>
#include <utility>
#include <vector>
#include <fmt/format.h>

// Priority queue is an ADT implemented usaully through binary heap.

/* 
   Heap: its a complete binary tree
   parent(i) -> i/2
   left(i) -> i*2
   right(i) -> i*2+1 , where i is idx

*/

template<typename T> 
class Heap{
private:
  std::vector<T> heap;

  const uint64_t parent(const int64_t& idx)const{return idx/2;}
  const uint64_t left(const int64_t& idx)const{return idx*2;}
  const uint64_t right(const int64_t& idx)const{return idx*2+1;}
  
  void shiftUp(const int64_t& i){
    int64_t idx{i};
    while(idx > 0 && heap[idx] > heap[parent(idx)]){
      std::swap(heap[idx], heap[parent(idx)]);
      idx = parent(idx);
    }
  }

public:
  Heap(){}
  Heap(const T& data){insert(data);}
  
  const T& peek()const{return heap[0];}
  
  const size_t size()const{return heap.size();} 
  
  void insert(const T& data){
    heap.push_back(data);
    shiftUp(heap.size()-1); 
  }
  
  const T extractMax()const{
    if(heap.size() < 1) throw std::runtime_error("HEAP UNDERFLOW");   
    T max = heap.peek();
    heap[0] = heap[heap.size()-1];
    shiftUp(heap.size()-1);
    return max;
  } 

  void increaseKey(){}
  
  void print(){
    for(auto &c : heap)
      fmt::print("{0}, ", c);
    fmt::println("");
    return;
  }
};
