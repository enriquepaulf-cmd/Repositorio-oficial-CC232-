#include <iostream>
#include <string>
#include <vector>

#include "SlidingWindowMedian.h"

namespace {

// Calcula las medianas deslizantes con la estructura de dos heaps.
std::vector<int> medianas(const std::vector<int>& x, int k) {
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

int fallos = 0;

// Compara el resultado contra el esperado e informa.
void revisar(const std::string& nombre, const std::vector<int>& x, int k,
             const std::vector<int>& esperado) {
  std::vector<int> obtenido = medianas(x, k);
  if (obtenido == esperado) {
    std::cout << "OK   " << nombre << "\n";
  } else {
    std::cout << "FALLO " << nombre << "\n";
    ++fallos;
  }
}

}  // namespace

int main() {
  // k = 1: cada elemento es su propia mediana (ventana de tamaño minimo).
  revisar("k=1 (ventana minima)", {5, 2, 9, 1, 7}, 1, {5, 2, 9, 1, 7});

  // k = n: una sola ventana con todo el arreglo. sorted {1,2,4,7,9}, pos 2 -> 4.
  revisar("k=n (una sola ventana)", {4, 2, 7, 1, 9}, 5, {4});

  // Todos iguales: prueba duplicados extremos y el lazy deletion.
  revisar("todos iguales", {7, 7, 7, 7}, 2, {7, 7, 7});

  // k par: debe tomar la mediana INFERIOR, no el promedio.
  revisar("k par (mediana inferior)", {4, 1, 3, 2, 5}, 2, {1, 1, 2, 2});

  // k par grande: sorted {1,2,3,4}, pos (4-1)/2 = 1 -> 2.
  revisar("k par = n", {1, 2, 3, 4}, 4, {2});

  // n = 1, k = 1: el caso mas pequeño posible.
  revisar("n=1 k=1", {42}, 1, {42});

  // Repetidos alternados: estresa el borrado diferido al deslizar.
  revisar("lazy deletion con repetidos", {5, 5, 1, 1, 5, 5}, 3, {5, 1, 1, 5});

  if (fallos == 0) {
    std::cout << "\nOK: todos los casos borde pasaron\n";
    return 0;
  }
  std::cout << "\nHubo " << fallos << " caso(s) borde con fallo\n";
  return 1;
}
