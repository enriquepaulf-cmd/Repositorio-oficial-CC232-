#include <iostream>
#include <vector>

#include "SlidingWindowMedian.h"

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, k;
  if (!(std::cin >> n >> k)) {
    return 0;
  }

  std::vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> x[i];
  }

//Dos heaps + lazy deletion: O(n log k) en vez de la fuerza bruta
  pc3::SlidingWindowMedian ventana;
  for (int i = 0; i < k; ++i) {     //primera ventana
    ventana.add(x[i]);
  }
  std::cout << ventana.median();

  for (int i = k; i < n; ++i) {        //desliza: entra x[i], sale x[i-k]
    ventana.add(x[i]);
    ventana.remove(x[i - k]);
    std::cout << ' ' << ventana.median();
  }
  std::cout << '\n';
  return 0;
}
