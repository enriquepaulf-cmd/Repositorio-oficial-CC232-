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
  // MOD-A6-B6: compara construir el heap por inserciones vs por Floyd.
  const std::vector<int> entrada{4, 17, 3, 90, 55, 21, 8, 13, 34, 2, 1, 89};
  std::less<int> comp;

  // Construccion A: insertar uno por uno.
  std::vector<int> a;
  std::size_t swapsA = 0;
  for (int x : entrada) {
    a.push_back(x);
    swapsA += ods::complHeapPercolateUpCount(a, a.size() - 1, comp);
  }

  // Construccion B: copiar el vector y aplicar Floyd.
  std::vector<int> b = entrada;
  std::size_t swapsB = 0;
  for (std::size_t i = b.size() / 2; i-- > 0;) {
    swapsB += ods::complHeapPercolateDownCount(b, b.size(), i, comp);
  }

  std::cout << "Bloque 6 - inserciones sucesivas vs Floyd\n";
  printVector(entrada, "arreglo inicial");
  std::cout << "\n";
  printVector(a, "final por inserciones");
  std::cout << "  intercambios = " << swapsA
            << ", valido = " << (ods::complHeapIsValid(a, comp) ? "si" : "no") << "\n\n";
  printVector(b, "final por Floyd");
  std::cout << "  intercambios = " << swapsB
            << ", valido = " << (ods::complHeapIsValid(b, comp) ? "si" : "no") << "\n";
  return 0;
}
