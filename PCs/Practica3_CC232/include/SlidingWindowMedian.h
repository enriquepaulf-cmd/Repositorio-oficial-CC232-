#pragma once

#include <functional>
#include <unordered_map>

#include "BinaryHeap.h"  //de Libreria_cc232/Semana5

namespace pc3 {

class SlidingWindowMedian {
 public:
  // Inserta x en la ventana
  void add(int x) {
    if (small_.empty() || x <= small_.top()) {
      small_.add(x);
      ++smallSize_;
    } else {
      large_.add(x);
      ++largeSize_;
    }
    rebalance();
  }

  //Marca x(que sale de la ventana) para borrado diferido
  void remove(int x) {
    ++delayed_[x];
    if (x <= small_.top()) {
      --smallSize_;
      if (x == small_.top()) prune(small_);
    } else {
      --largeSize_;
      if (x == large_.top()) prune(large_);
    }
    rebalance();
  }

  //Mediana inferior de la ventana actual.
  int median() const { return small_.top(); }

  int size() const { return smallSize_ + largeSize_; }
  bool empty() const { return size() == 0; }

 private:
  ods::BinaryHeap<int, std::greater<int>> small_; //max-heap (mitad baja)
  ods::BinaryHeap<int, std::less<int>> large_;    //min-heap (mitad alta)
  std::unordered_map<int, int> delayed_;     //valores pendientes de borrar
  int smallSize_ = 0;
  int largeSize_ = 0;

  //Descarta del tope de h los elementos ya marcados como diferidos.
  template <class Heap>
  void prune(Heap& h) {
    while (!h.empty()) {
      const int top = h.top();
      auto it = delayed_.find(top);
      if (it != delayed_.end() && it->second > 0) {
        --it->second;
        if (it->second == 0) delayed_.erase(it);
        h.remove();
      } else {
        break;
      }
    }
  }

  //Restaura el invariante de tamanos moviendo un tope entre heaps.
  void rebalance() {
    if (smallSize_ > largeSize_ + 1) {
      large_.add(small_.top());
      small_.remove();
      --smallSize_;
      ++largeSize_;
      prune(small_);
    } else if (smallSize_ < largeSize_) {
      small_.add(large_.top());
      large_.remove();
      ++smallSize_;
      --largeSize_;
      prune(large_);
    }
  }
};

}  // namespace pc3
