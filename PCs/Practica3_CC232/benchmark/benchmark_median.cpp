#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "SlidingWindowMedian.h"

namespace {
using Reloj = std::chrono::high_resolution_clock;
//Suma de todas las medianas con fuerza bruta: O(n * k * log k).
long long sumaFuerzaBruta(const std::vector<int>& x, int k) {
  long long suma = 0;
  std::vector<int> ventana;
  for (int i = 0; i + k <= static_cast<int>(x.size()); ++i) {
    ventana.assign(x.begin() + i, x.begin() + i + k);
    std::sort(ventana.begin(), ventana.end());
    suma += ventana[(k - 1) / 2];
  }
  return suma;
}

//Suma de todas las medianas con dos heaps + lazy deletion: O(n log k)
long long sumaDosHeaps(const std::vector<int>& x, int k) {
  pc3::SlidingWindowMedian ventana;
  long long suma = 0;
  for (int i = 0; i < k; ++i) {
    ventana.add(x[i]);
  }
  suma += ventana.median();
  for (int i = k; i < static_cast<int>(x.size()); ++i) {
    ventana.add(x[i]);
    ventana.remove(x[i - k]);
    suma += ventana.median();
  }
  return suma;
}

double ms(Reloj::time_point a, Reloj::time_point b) {
  return std::chrono::duration<double, std::milli>(b - a).count();
}

std::vector<int> generar(int n, std::mt19937& rng) {
  std::uniform_int_distribution<int> dist(1, 1000000000);
  std::vector<int> x(n);
  for (int& v : x) {
    v = dist(rng);
  }
  return x;
}

}  // namespace

int main() {
  std::mt19937 rng(12345);

  std::cout << "Benchmark: fuerza bruta O(n*k*log k) vs dos heaps O(n log k)\n\n";
  std::cout << "    n        k    bruta(ms)    heaps(ms)   coinciden\n";

  for (int n : {1000, 2000, 4000, 8000}) {
    int k = n / 2;
    std::vector<int> x = generar(n, rng);

    auto t0 = Reloj::now();
    long long s1 = sumaFuerzaBruta(x, k);
    auto t1 = Reloj::now();
    long long s2 = sumaDosHeaps(x, k);
    auto t2 = Reloj::now();

    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << "  " << n << "     " << k << "     " << ms(t0, t1)
              << "        " << ms(t1, t2) << "        "
              << (s1 == s2 ? "si" : "NO") << "\n";
  }

// Caso grande (maximo de CSES): solo dos heaps; la fuerza bruta no escala
  {
    int n = 200000, k = 100000;
    std::vector<int> x = generar(n, rng);
    auto t0 = Reloj::now();
    long long s = sumaDosHeaps(x, k);
    auto t1 = Reloj::now();
    std::cout << "\nCaso grande (solo dos heaps): n=" << n << " k=" << k
              << " -> " << ms(t0, t1) << " ms\n";
  }
  return 0;
}
