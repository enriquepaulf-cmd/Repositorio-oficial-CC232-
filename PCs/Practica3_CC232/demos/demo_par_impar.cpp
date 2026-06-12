#include <iostream>
#include <vector>

#include "SlidingWindowMedian.h"

namespace {

//Calcula e imprime las medianas de cada ventana, indicando si k es par o impar.
void correr(const std::vector<int>& x, int k) {
  pc3::SlidingWindowMedian ventana;
  for (int i = 0; i < k; ++i) {
    ventana.add(x[i]);
  }
  std::cout << "k=" << k << " (" << (k % 2 == 0 ? "par" : "impar") << ")"
            << " -> medianas: " << ventana.median();
  for (int i = k; i < static_cast<int>(x.size()); ++i) {
    ventana.add(x[i]);
    ventana.remove(x[i - k]);
    std::cout << " " << ventana.median();
  }
  std::cout << "\n";
}

}  // namespace

int main() {
  std::cout << "Demo: que mediana se usa con k par e impar\n";
  std::cout << "La mediana siempre es la posicion (k-1)/2 al ordenar la ventana.\n\n";

  //k impar: hay un unico elemento central.
  std::vector<int> a{2, 3, 4};
  std::cout << "Ventana {2,3,4} ordenada {2,3,4}, central = 3\n";
  correr(a, 3);

  //k par: se toma el menor de los dos centrales (mediana inferior).
  std::vector<int> b{1, 2, 3, 4};
  std::cout << "\nVentana {1,2,3,4} ordenada {1,2,3,4}, dos centrales 2 y 3, se usa el menor = 2\n";
  correr(b, 4);

  return 0;
}
