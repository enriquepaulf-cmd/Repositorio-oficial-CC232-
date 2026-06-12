# PC3 - CC232

## Estudiante

- Nombre: Paul Flores Enrique Alejandro
- Codigo:
- Problema asignado: CSES 1076 - Sliding Window Median
- Enlace oficial: https://cses.fi/problemset/task/1076

## Referencia oficial

- CSV oficial: https://github.com/kapumota/CC-232/blob/main/Practicas/Practica3_CC232/Problemas-Evaluacion3.csv

## Relacion con Semanas 4-6

- Semana principal: Semana 6 (heaps, colas de prioridad y lazy deletion).
- Estructura usada: dos heaps binarios, un max heap y un min heap, con lazy deletion.
- Estructura de la libreria cc232 relacionada: BinaryHeap de la Semana 5, que se reutiliza directamente para los dos heaps.

## Resumen de la solucion

El problema pide la mediana de cada ventana de k elementos consecutivos de un arreglo, de izquierda a derecha. La mediana es el elemento central al ordenar la ventana, y si k es par se toma el menor de los dos centrales (mediana inferior).

Una solucion ingenua ordenaria cada ventana, lo que cuesta O(n*k*log k) y no entra en el tiempo limite cuando n y k llegan a 2*10^5. Para evitarlo se mantienen dos heaps: small_ es un max heap con la mitad baja de la ventana y large_ es un min heap con la mitad alta. El tope de small_ es siempre la mediana inferior.

Al deslizar la ventana entra un elemento con add y sale otro con remove. Como un heap binario no borra un elemento del medio de forma eficiente, el elemento que sale se marca para borrado diferido (lazy deletion) y se descarta recien cuando aparece en el tope. Asi cada ventana cuesta solo O(log k).

## Invariante principal

Despues de cada operacion se mantiene que los tamaños logicos cumplen smallSize_ == largeSize_ o smallSize_ == largeSize_ + 1, y que el tope de small_ no supera al tope de large_. Eso garantiza que el tope de small_ es la mediana inferior. El metodo cumpleInvariante verifica esta propiedad y se prueba en tests/test_invariante.cpp.

## Complejidad

- Tiempo por operacion: add O(log k), remove O(log k) amortizado, median O(1).
- Tiempo total: O(n log k).
- Espacio: O(k).

## Archivos relevantes

- include/SlidingWindowMedian.h: la estructura de dos heaps con lazy deletion (reusa BinaryHeap).
- src/main.cpp: lee de stdin y escribe las medianas en el formato de CSES.
- demos/demo_sliding_window_first.cpp: version ingenua con el ejemplo del enunciado.
- demos/demo_par_impar.cpp: muestra que mediana se usa con k par e impar.
- tests/test_median.cpp: compara la version eficiente contra la fuerza bruta.
- tests/test_casos_borde.cpp: casos borde (k=1, k=n, todos iguales, k par, lazy deletion).
- tests/test_invariante.cpp: revisa el invariante despues de cada ventana.
- benchmark/benchmark_median.cpp: mide tiempos de fuerza bruta vs dos heaps.
- docs/respuestas_obligatorias.md: respuestas a las preguntas comunes y especificas.
- docs/bitacora.md: avance por dias.
- resultados/: evidencias de ejecucion, pruebas y casos borde.

## Limpieza del repositorio

El repositorio no versiona builds, ejecutables ni archivos generados. El archivo .gitignore de la raiz ignora carpetas como build/ y archivos como *.exe, *.o y CMakeCache.txt.

Comando para verificar archivos generados versionados:

```bash
git ls-files | grep -E "(^build/|cmake-build|\.exe$|\.out$|\.o$|\.obj$|CMakeCache.txt|CMakeFiles|__pycache__)"
```

Si no devuelve nada, el repositorio esta limpio.

## Compilacion

```bash
cmake -S . -B build
cmake --build build
```

## Ejecucion

```bash
echo "8 3 2 4 3 5 8 1 2 1" | ./build/pc3_main.exe
```

Salida esperada:

```
3 4 5 5 2 1
```

## Pruebas

Se ejecutan con ctest:

```bash
ctest --test-dir build --output-on-failure
```

Pruebas incluidas:

1. Caso minimo y del enunciado: entrada 8 3 / 2 4 3 5 8 1 2 1, salida esperada 3 4 5 5 2 1. Valida la correctitud general.
2. Comparacion aleatoria contra fuerza bruta (test_median.cpp): 3000 casos con duplicados y k par e impar. Valida que la version eficiente da lo mismo que la ingenua.
3. Casos borde (test_casos_borde.cpp): k=1, k=n, todos iguales, k par, n=1 y lazy deletion con repetidos. Valida los limites.
4. Invariante (test_invariante.cpp): despues de cada ventana se llama a cumpleInvariante y se compara la mediana con la fuerza bruta. Valida que la estructura se mantiene consistente.
5. Benchmark (benchmark/benchmark_median.cpp): no es prueba de ctest, mide tiempos y confirma el O(n log k); ademas la columna coinciden verifica que ambos metodos dan el mismo resultado.

## Preguntas obligatorias

Las preguntas comunes y especificas estan respondidas en docs/respuestas_obligatorias.md, conectadas a funciones concretas del codigo (add, remove, median, prune, rebalance, cumpleInvariante).

## Bitacora

El avance por dias esta en docs/bitacora.md, relacionado con los commits.

