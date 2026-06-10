#include <algorithm>
#include <iostream>
#include <vector>

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

  for (int i = 0; i + k <= n; ++i) {
    std::vector<int> ventana(x.begin() + i, x.begin() + i + k);
    std::sort(ventana.begin(), ventana.end());
    int mediana = ventana[(k - 1) / 2];   //mediana inferior
    std::cout << mediana << (i + k < n ? ' ' : '\n');
  }
  return 0;
}
