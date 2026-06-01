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

// MOD-A6-B3: verifica la propiedad de max-heap (padre no menor que hijos)
template <typename T, class Compare>
bool esHeapValido(const std::vector<T>& a, Compare comp) {
  for (std::size_t i = 0; i < a.size(); ++i) {
    const std::size_t l = ods::pqLeftChild(i);
    const std::size_t r = ods::pqRightChild(i);
    if (l < a.size() && comp(a[i], a[l])) return false;
    if (r < a.size() && comp(a[i], a[r])) return false;
  }
  return true;
}

}  // namespace

int main() {
  std::vector<int> heap;
  std::less<int> comp;
  const std::vector<int> entrada{40, 10, 70, 30, 90, 20, 80, 60};

  std::cout << "Bloque 3 - conteo de intercambios en percolateUp\n";
  printVector(entrada, "secuencia a insertar");
  std::cout << "\n";

  for (int x : entrada) {
    heap.push_back(x);  // MOD-A6-B3: insercion manual para instrumentar percolateUp
    std::size_t swaps = ods::complHeapPercolateUpCount(heap, heap.size() - 1, comp);
    std::cout << "insert(" << x << ")  intercambios = " << swaps << "\n";
    printVector(heap, "  heap interno");
    std::cout << "  propiedad heap = " << (esHeapValido(heap, comp) ? "OK" : "ROTA")
              << "\n\n";
  }
}
