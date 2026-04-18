#include <iostream>

class vector{
  private:
    void *ptr;
    size_t capacity;
    size_t size;

  public:
    vector(size_t capacity = 0 ){
      ptr = new int[capacity];
    }
};

int main (int argc, char *argv[]) {
  
  return 0;
}
