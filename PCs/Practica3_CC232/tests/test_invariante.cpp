#include <algorithm>
#include <iostream>
#include <vector>

#include "SlidingWindowMedian.h"

namespace {

//Mediana inferior por fuerza bruta para comparar.
int medianaFuerzaBruta(std::vector<int> ventana) {
  std::sort(ventana.begin(), ventana.end());
  return ventana[(ventana.size() - 1) / 2];
}

}  // namespace

int main() {
  std::vector<int> x{2, 4, 3, 5, 8, 1, 2, 1, 7, 7, 7, 0, 9, 3};
  int k = 4;

  pc3::SlidingWindowMedian ventana;
  int fallos = 0;

  for (int i = 0; i < k; ++i) {
    ventana.add(x[i]);
  }
  //Despues de cada ventana se revisa el invariante y la mediana.
  if (!ventana.cumpleInvariante()) ++fallos;
  if (ventana.median() != medianaFuerzaBruta({x.begin(), x.begin() + k})) ++fallos;

  for (int i = k; i < static_cast<int>(x.size()); ++i) {
    ventana.add(x[i]);
    ventana.remove(x[i - k]);
    if (!ventana.cumpleInvariante()) {
      std::cout << "FALLO: invariante roto en la ventana que termina en " << i << "\n";
      ++fallos;
    }
    int esperado = medianaFuerzaBruta({x.begin() + (i - k + 1), x.begin() + i + 1});
    if (ventana.median() != esperado) {
      std::cout << "FALLO: mediana incorrecta en la ventana que termina en " << i << "\n";
      ++fallos;
    }
  }

  if (fallos == 0) {
    std::cout << "OK: el invariante se mantiene en todas las ventanas\n";
    return 0;
  }
  std::cout << "Hubo " << fallos << " fallo(s)\n";
  return 1;
}
