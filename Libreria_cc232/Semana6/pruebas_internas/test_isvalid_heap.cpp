#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "Capitulo6.h"

namespace {

void expect(bool cond, const std::string& msg) {
  if (!cond) {
    std::cerr << "[FALLO] " << msg << "\n";
    std::exit(1);
  }
}

}  // namespace

int main() {
  std::less<int> comp;

  // 1. heap vacio
  expect(ods::complHeapIsValid(std::vector<int>{}, comp), "heap vacio debe ser valido");

  // 2. heap con un elemento
  expect(ods::complHeapIsValid(std::vector<int>{42}, comp), "heap de un elemento debe ser valido");

  // 3. heap con elementos repetidos
  {
    std::vector<int> a{5, 5, 5, 5, 5};
    ods::complHeapHeapifyFloyd(a, comp);
    expect(ods::complHeapIsValid(a, comp), "heap con repetidos debe ser valido");
  }

  // 4. heap construido por inserciones
  {
    ods::PQ_ComplHeap<int> pq;
    for (int x : {40, 10, 70, 30, 90, 20, 80, 60}) {
      pq.insert(x);
    }
    expect(pq.isValidHeap(), "heap por inserciones debe ser valido");
  }

  // 5. heap construido por heapify
  {
    ods::PQ_ComplHeap<int> pq(std::vector<int>{4, 17, 3, 90, 55, 21, 8, 13, 34, 2, 1, 89});
    expect(pq.isValidHeap(), "heap por heapify debe ser valido");
  }

  // 6. heap despues de varios delMax
  {
    ods::PQ_ComplHeap<int> pq(std::vector<int>{40, 10, 70, 30, 90, 20, 80, 60});
    pq.delMax();
    pq.delMax();
    pq.delMax();
    expect(pq.isValidHeap(), "heap tras varios delMax debe ser valido");
  }

  // negativo: debe detectar un arreglo que no respeta la propiedad de heap
  expect(!ods::complHeapIsValid(std::vector<int>{1, 2, 3}, comp),
         "debe detectar un arreglo que no es heap");

  std::cout << "OK test_isvalid_heap (bloque 5)\n";
  return 0;
}
