# Bitácora de desarrollo - PC3 CC232

- **Estudiante:** Paul Flores Enrique Alejandro
- **Problema asignado:** CSES 1076 - Sliding Window Median
- **Enlace oficial:** https://cses.fi/problemset/task/1076

> Cada entrada debe describir el avance real del día y relacionarse con los commits.

---

## Día 1 -

- **Lectura del problema**
- **Creacion del repo**
- **Primera intuicion de como resolver el problema(borrador)**
- **Lee datos reales, calcula la mediana de cada ventana ordenandola desde cero, e imprime en el formato pedido.**
- **Primer Demo para entender y demostrar visualmente como se calcula la mediana paso a paso**
- **Pendientes: Probar una solucion mas optima, probar con dos heaps**

---

## Día 2 -

- **Implementación de la solución óptima con dos heaps + lazy deletion en include/SlidingWindowMedian.h**
- **Reúso de BinaryHeap de la Semana 5: small_ es max-heap (mitad baja) y large_ es min-heap (mitad alta)**
- **Invariante de tamaño: small_ tiene igual o un elemento más que large_, así su tope es siempre la mediana inferior**
- **Operaciones creadas: add, remove (borrado diferido), median, prune (limpia el tope) y rebalance (mantiene el equilibrio)**
- **Conexión de src/main.cpp para usar la estructura, pasando de fuerza bruta O(n·k·log k) a O(n log k)**
- **Prueba en tests/test_median.cpp que compara dos heaps contra fuerza bruta: caso del enunciado + 3000 casos aleatorios con duplicados y k par/impar**
- **Actualización de CMakeLists.txt: rutas de include, target de prueba y registro en ctest**
- **Pendientes: agregar pruebas de casos borde (k=1, k=n, todos iguales, k par vs impar), hacer un benchmark de tiempos comparando fuerza bruta vs dos heaps con n grande, y guardar las evidencias en resultados/ (ejecucion_pc3.txt, tests_pc3.txt, casos_borde.txt)**

---

## Día 3 -

- **Avance del día:**
- **Operaciones implementadas:**
- **Errores encontrados:**
- **Pruebas agregadas:**
- **Refactorizaciones:**
- **Commits relacionados:**

---

## Día 4 -

- **Avance del día:**
- **Preparación del bloque de modificación grabada:**
- **Pruebas agregadas:**
- **Commits relacionados:**
