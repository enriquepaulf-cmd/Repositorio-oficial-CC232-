#pragma once

#include <algorithm>
#include <functional>
#include <vector>

#include "PQ_ComplHeap_heapifyFloyd.h"
#include "PQ_ComplHeap_percolateDown.h"

namespace ods {

template <class T, class Compare = std::less<T>>
void heapSort(std::vector<T>& a, Compare comp = Compare{}) {
  if (a.size() < 2) {
    return;
  }
  complHeapHeapifyFloyd(a, comp);
  for (std::size_t n = a.size(); n > 1; --n) {
    std::swap(a[0], a[n - 1]);
    complHeapPercolateDown(a, n - 1, 0, comp);
  }
}

template <class T, class Compare = std::less<T>>
std::vector<T> heapSorted(std::vector<T> a, Compare comp = Compare{}) {
  heapSort(a, comp);
  return a;
}

// MOD-A6-B7: heapsort in situ con el mismo esquema, parametrizado por comparador.
template <class T, class Cmp>
void heapSortImpl(std::vector<T>& a, Cmp cmp) {
  complHeapHeapifyFloyd(a, cmp);
  for (std::size_t n = a.size(); n > 1; --n) {
    std::swap(a[0], a[n - 1]);
    complHeapPercolateDown(a, n - 1, 0, cmp);
  }
}

// MOD-A6-B7: permite elegir el sentido del resultado.
// ascending = true usa el comparador tal cual (heap maximo -> orden ascendente);
// ascending = false invierte el comparador (heap minimo -> orden descendente).
template <class T, class Compare>
void heapSort(std::vector<T>& a, Compare comp, bool ascending) {
  if (a.size() < 2) {
    return;
  }
  if (ascending) {
    heapSortImpl(a, comp);
  } else {
    heapSortImpl(a, [comp](const T& x, const T& y) { return comp(y, x); });
  }
}

}  // namespace ods
