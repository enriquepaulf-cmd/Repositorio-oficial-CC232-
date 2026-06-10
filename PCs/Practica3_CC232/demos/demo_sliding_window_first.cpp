#include <algorithm>
#include <iostream>
#include <vector>

//Borrador

namespace {

//Mediana inferior: al ordenar la ventana posicion (k-1)/2.
int medianaInferior(std::vector<int> ventana) {
  std::sort(ventana.begin(), ventana.end());
  return ventana[(ventana.size() - 1) / 2];
}

}  // namespace

int main() {
  //ejemplo del enunciado: n = 8, k = 3, x = {2, 4, 3, 5, 8, 1, 2, 1}
  const int n = 8;
  const int k = 3;
  const std::vector<int> x{2, 4, 3, 5, 8, 1, 2, 1};

  std::cout << "Sliding Window Median - primera version (borrador)\n";
  std::cout << "n = " << n << ", k = " << k << "\n\n";

  std::vector<int> medianas;
  for (int i = 0; i + k <= n; ++i) {
    std::vector<int> ventana(x.begin() + i, x.begin() + i + k);
    std::vector<int> ordenada = ventana;
    std::sort(ordenada.begin(), ordenada.end());
    int m = ordenada[(ordenada.size() - 1) / 2];
    medianas.push_back(m);

    std::cout << "ventana [" << i << ".." << (i + k - 1) << "] = {";
    for (std::size_t j = 0; j < ventana.size(); ++j)
      std::cout << (j ? ", " : "") << ventana[j];
    std::cout << "}  ordenada = {";
    for (std::size_t j = 0; j < ordenada.size(); ++j)
      std::cout << (j ? ", " : "") << ordenada[j];
    std::cout << "}  mediana = " << m << "\n";
  }

  std::cout << "\nSalida final: ";
  for (std::size_t i = 0; i < medianas.size(); ++i)
    std::cout << medianas[i] << (i + 1 < medianas.size() ? " " : "\n");
  return 0;
}
