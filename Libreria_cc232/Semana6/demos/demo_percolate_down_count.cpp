#include <functional>
#include <iostream>
#include <vector>

#include "Capitulo6.h"

namespace {

template <typename T>
void printVector(const std::vector<T>& xs, const char* label) {
  std::cout << label << ": [";
  for (std::size_t i = 0; i < xs.size(); ++i) {
    if (i != 0) std::cout << ", ";
    std::cout << xs[i];
  }
  std::cout << "]\n";
}

}  // namespace

int main() {
  // MOD-A6-B4: demo de delMax mostrando los intercambios de percolateDown.
  std::vector<int> heap{40, 10, 70, 30, 90, 20, 80, 60};
  std::less<int> comp;
  ods::complHeapHeapifyFloyd(heap, comp);  // max-heap con Floyd

  std::cout << "Bloque 4 - conteo de intercambios en percolateDown (delMax)\n";
  printVector(heap, "heap inicial (Floyd)");
  std::cout << "\n";

  while (!heap.empty()) {
    int maxv = heap.front();
    heap.front() = heap.back();  // mueve el ultimo a la raiz
    heap.pop_back();

    std::cout << "delMax() -> " << maxv << "\n";
    printVector(heap, "  antes de reparar");
    std::size_t swaps =
        heap.empty() ? 0 : ods::complHeapPercolateDownCount(heap, heap.size(), 0, comp);
    std::cout << "  intercambios = " << swaps << "\n";
    printVector(heap, "  despues de reparar");
    std::cout << "\n";
  }
  return 0;
}
