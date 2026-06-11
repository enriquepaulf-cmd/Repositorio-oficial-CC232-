#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "SlidingWindowMedian.h"

namespace {

//Solucion inicial: ordena cada ventana y toma la posicion (k-1)/2
std::vector<int> medianasFuerzaBruta(const std::vector<int>& x, int k) {
  std::vector<int> salida;
  for (int i = 0; i + k <= static_cast<int>(x.size()); ++i) {
    std::vector<int> ventana(x.begin() + i, x.begin() + i + k);
    std::sort(ventana.begin(), ventana.end());
    salida.push_back(ventana[(k - 1) / 2]);
  }
  return salida;
}

//Solucion mejorada: dos heaps + lazy deletion
std::vector<int> medianasDosHeaps(const std::vector<int>& x, int k) {
  pc3::SlidingWindowMedian ventana;
  std::vector<int> salida;
  for (int i = 0; i < k; ++i) {
    ventana.add(x[i]);
  }
  salida.push_back(ventana.median());
  for (int i = k; i < static_cast<int>(x.size()); ++i) {
    ventana.add(x[i]);
    ventana.remove(x[i - k]);
    salida.push_back(ventana.median());
  }
  return salida;
}

}  // namespace

int main() {
  {                                //1)Caso del enunciado
    std::vector<int> x{2, 4, 3, 5, 8, 1, 2, 1};
    std::vector<int> esperado{3, 4, 5, 5, 2, 1};
    if (medianasDosHeaps(x, 3) != esperado) {
      std::cerr << "FALLO: caso del enunciado\n";
      return 1;
    }
  }

//2)Comparacion aleatoria contra fuerza bruta (incluye duplicados y k par/impar)
  std::srand(12345);
  for (int t = 0; t < 3000; ++t) {
    int n = 1 + std::rand() % 40;
    int k = 1 + std::rand() % n;
    std::vector<int> x(n);
    for (int& v : x) {
      v = 1 + std::rand() % 15;              //rango chico -> muchos duplicados
    }
    if (medianasDosHeaps(x, k) != medianasFuerzaBruta(x, k)) {
      std::cerr << "FALLO en t=" << t << " n=" << n << " k=" << k << "\n";
      return 1;
    }
  }

  std::cout << "OK: todas las pruebas pasaron\n";
  return 0;
}
