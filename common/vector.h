#include <cstdint>
#include <fmt/base.h>
#include <iostream>
#ifndef VECTOR
#define VECTOR
#include <vector>
namespace nc {

constexpr char endl = '\n';

// vector container
template <typename T> class vector {
private:
  size_t v_size{0};
  size_t v_capacity{1};
  T *ptr;

  T &access(const size_t &idx) {
    if (idx == 0)
      return *this->ptr;
    else
      return *(this->ptr + (sizeof(*this->ptr) * (idx - 1)));
  }

public:
  vector() { return; }
  vector(const vector &v) { this = v; }
  ~vector() { delete ptr; }

  size_t size() const { return this->v_size; }
  size_t capacity() const { return this->v_capacity; }
  void reserve(const int &size) {
    this->ptr = new T[size];
    this->v_capacity = size;
    return;
  }
  void push_back(const T &data) {
    this->access(this->v_size) = data;
    v_size++;
    return;
  }
  void emplace_back(const T &data) const {}

  T &operator[](const int &idx) const {
    if (idx == 0)
      return *this->ptr;
    else
      return *(this->ptr + (sizeof(*this->ptr) * (idx - 1)));
  }
};

template <typename T> void print_vec(const std::vector<T> &vec) {
  for (const T &x : vec)
    fmt::print("{}, ", x);
  fmt::println("");
  return;
}
} // namespace nc
#endif
