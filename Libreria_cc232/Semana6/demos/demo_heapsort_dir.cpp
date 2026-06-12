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
  // MOD-A6-B7: heapSort con sentido elegible, probando con repetidos.
  const std::vector<int> entrada{5, 1, 5, 3, 8, 2, 8, 0};
  std::less<int> comp;

  std::cout << "Bloque 7 - heapSort ascendente y descendente\n";
  printVector(entrada, "entrada");

  std::vector<int> asc = entrada;
  ods::heapSort(asc, comp, true);
  printVector(asc, "ascendente");

  std::vector<int> desc = entrada;
  ods::heapSort(desc, comp, false);
  printVector(desc, "descendente");

  std::cout << "Los valores repetidos (5 y 8) aparecen juntos en ambos resultados.\n";
  return 0;
}
