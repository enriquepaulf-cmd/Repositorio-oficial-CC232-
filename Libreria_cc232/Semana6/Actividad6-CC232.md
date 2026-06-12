### Actividad 6 - CC232 

- Duración: 3 horas de clase.
- Modalidad: Trabajo individual.
- Entrega: Un archivo llamado `Actividad6-CC232.md` y los archivos modificados solicitados.

#### Objetivo

Consolidar lo trabajado en la Semana 6 a partir de lectura cercana, modificación controlada de código, ejecución de demostraciones, ampliación de pruebas y defensa escrita breve.

La meta principal no es solo ejecutar la librería, sino **intervenir el código** para demostrar comprensión real de:

1. La interfaz abstracta de cola de prioridad: `PQ`.
2. La implementación con heap binario completo: `PQ_ComplHeap`.
3. Las operaciones `getMax`, `insert`, `delMax`, `percolateUp`, `percolateDown` y `heapify` de Floyd.
4. El ordenamiento `heapSort`.
5. El heap izquierdista: `PQ_LeftHeap` y su operación central `merge`.
6. La codificación Huffman como aplicación de colas de prioridad.
7. La comparación con estructuras de la Semana 5: `BinaryHeap`, `BinarySearchTree` y apoyo conceptual de `BinaryTree`.
8. La relación entre prioridad, búsqueda ordenada y estructuras híbridas como `Treap`.

El énfasis de esta actividad está en **modificar, justificar, probar y defender** cambios pequeños pero técnicamente significativos.

#### Material de trabajo

##### Código de la semana

Revisa como mínimo:

- `Semana6/README.md`
- `Semana6/lecturas/Notas.md`
- `Semana6/include/PQ.h`
- `Semana6/include/PQ_ComplHeap.h`
- `Semana6/include/PQ_ComplHeap_macro.h`
- `Semana6/include/PQ_ComplHeap_getMax.h`
- `Semana6/include/PQ_ComplHeap_insert.h`
- `Semana6/include/PQ_ComplHeap_delMax.h`
- `Semana6/include/PQ_ComplHeap_percolateUp.h`
- `Semana6/include/PQ_ComplHeap_percolateDown.h`
- `Semana6/include/PQ_ComplHeap_heapifyFloyd.h`
- `Semana6/include/vector_heapSort.h`
- `Semana6/include/PQ_LeftHeap.h`
- `Semana6/include/PQ_LeftHeap_merge.h`
- `Semana6/include/PQ_LeftHeap_insert.h`
- `Semana6/include/PQ_LeftHeap_delMax.h`
- `Semana6/include/Huffman_PQ.h`
- `Semana6/include/Huffman_PQ_generateTree.h`
- `Semana6/include/MeldableHeap.h`
- `Semana6/include/Treap.h`
- `Semana6/include/Capitulo6.h`
- `Semana6/include/Capitulo10.h`

##### Código reutilizado de Semana 5

Revisa también:

- `Semana5/include/BinaryTree.h`
- `Semana5/include/BinaryHeap.h`
- `Semana5/include/BinarySearchTree.h`
- `Semana5/include/Capitulo5.h`

##### Demostraciones y pruebas

Revisa y ejecuta:

- `Semana6/demos/demo_pq_complheap_basico.cpp`
- `Semana6/demos/demo_heapify_floyd.cpp`
- `Semana6/demos/demo_heapsort.cpp`
- `Semana6/demos/demo_left_heap_merge.cpp`
- `Semana6/demos/demo_huffman.cpp`
- `Semana6/demos/demo_compare_with_semana5.cpp`
- `Semana6/demos/demo_bst_rotations.cpp`
- `Semana6/demos/demo_treap_basico.cpp`
- `Semana6/demos/demo_capitulo6_panorama.cpp`
- `Semana6/pruebas_publicas/test_public_week6.cpp`
- `Semana6/pruebas_internas/test_internal_week6.cpp`
- `Semana6/CMakeLists.txt`

#### Reglas de modificación

1. No reemplaces las estructuras principales por `std::priority_queue`, `std::set`, `std::map` o funciones estándar que oculten el algoritmo central.
2. Toda modificación debe mantener el estilo de la librería: headers simples, C++17, nombres claros y sin macros innecesarias.
3. Cada cambio debe compilar.
4. Cada cambio debe tener al menos una evidencia: demostraciones, prueba pública, prueba interna o salida documentada.
5. En los archivos modificados, marca tus cambios con comentarios breves de este estilo:

```cpp
// MOD-A6-B3: validacion de propiedad heap
```

6. No basta con decir "funciona". Debes explicar qué invariante se preserva, qué caso borde se cubre y qué costo tiene la operación modificada.

#### Bloque 1 - Diagnóstico inicial de la Semana 6

Revisa:

- `Semana6/README.md`
- `Semana6/CMakeLists.txt`
- `Semana6/include/Capitulo6.h`
- `Semana6/include/Capitulo10.h`

Ejecuta desde la raíz de la librería o desde el entorno de compilación que uses:

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Responde:

1. ¿Qué targets de demostraciones o pruebas aparecen para Semana 6?
2. ¿Qué archivos se incluyen desde `Capitulo6.h`?
3. ¿Qué diferencia práctica hay entre `Capitulo6.h` y `Capitulo10.h`?
4. ¿Qué partes de Semana 6 dependen conceptualmente de Semana 5?
5. ¿Qué estructura se usa para prioridad pura?
6. ¿Qué estructura se usa para búsqueda ordenada?
7. ¿Qué estructura mezcla búsqueda ordenada con prioridad?
8. ¿Qué evidencia inicial obtuviste al ejecutar las pruebas sin modificar nada?.

Entrega en este bloque:

- Una tabla con: comando ejecutado, resultado, error si hubo, interpretación.
- Una lista de los archivos que planeas modificar.

#### Bloque 2 - Modificación de utilidades de heap completo

Revisa:

- `Semana6/include/PQ_ComplHeap_macro.h`
- `Semana6/include/PQ_ComplHeap_percolateUp.h`
- `Semana6/include/PQ_ComplHeap_percolateDown.h`

Modifica `PQ_ComplHeap_macro.h` para agregar funciones auxiliares `constexpr` adicionales, sin usar macros:

```cpp
pqHasLeftChild(i, n)
pqHasRightChild(i, n)
pqIsLeaf(i, n)
pqIsInternal(i, n)
```

Luego modifica `PQ_ComplHeap_percolateDown.h` para usar esas funciones auxiliares donde corresponda.

Responde:

1. ¿Por qué conviene expresar `parent`, `left`, `right` y pruebas de frontera como funciones pequeñas?
Por rque lo encapsulan en un solo lugar brindando mejor entendimiento sin tener que deducir 
porque.  Si en algun momento deseamos hacer un cambio se corrige en un solo lugar y no en 
cada bucle y presenta menos errores de frontera.
2. ¿Qué ventaja tiene `constexpr` frente a macros?
Respeta el sistema de tipos a diferencia de los macros.
3. ¿Qué caso borde aparece cuando el nodo tiene solo hijo izquierdo?
El caso borde que aparece es el del ultimo nodo interno cuando el heap tiene un numero par de elementos: ese nodo cumple 2i+1 < n (si tiene hijo izquierdo) pero 2i+2 == n (su hijo derecho cae fuera del arreglo). Por ejemplo, en un heap de n = 6, el nodo i = 2 tiene hijo izquierdo en el índice 5 pero su hijo derecho sería el índice 6, que no existe.
4. ¿Qué condición identifica una hoja en la representación implícita?
5. ¿Qué cambió en `percolateDown` después de usar las funciones auxiliares?

Entrega en este bloque:

- Fragmento del código modificado.
- Explicación de por qué no cambia la complejidad.
- Evidencia de compilación.

#### Bloque 3 - Modificación de `percolateUp`: conteo de intercambios

Revisa:

- `Semana6/include/PQ_ComplHeap_percolateUp.h`
- `Semana6/include/PQ_ComplHeap_insert.h`
- `Semana6/demos/demo_pq_complheap_basico.cpp`

Agrega una función nueva, sin romper la función existente:

```cpp
template<class T, class Compare>
std::size_t complHeapPercolateUpCount(std::vector<T>& a, std::size_t i, Compare comp);
```

La función debe hacer lo mismo que `complHeapPercolateUp`, pero además debe retornar cuántos intercambios realizó.

Luego modifica o crea una demostración para insertar la secuencia:

```cpp
{ 40, 10, 70, 30, 90, 20, 80, 60 }
```

y mostrar por cada inserción:

- elemento insertado,
- cantidad de intercambios,
- arreglo interno resultante,
- si la propiedad heap se mantiene.

Responde:

1. ¿En qué casos `percolateUp` hace cero intercambios?
2. ¿En qué casos puede hacer `O(log n)` intercambios?
3. ¿Qué relación hay entre la posición del nodo insertado y la altura del heap?
4. ¿Por qué el arreglo interno no necesariamente queda ordenado?
5. ¿Qué propiedad sí queda garantizada?.

Entrega en este bloque:

- Código de la función nueva.
- Salida de la demostración.
- Argumento de costo.

#### Bloque 4 - Modificación de `percolateDown`: elección del hijo dominante

Revisa:

- `Semana6/include/PQ_ComplHeap_percolateDown.h`
- `Semana6/include/PQ_ComplHeap_delMax.h`
- `Semana6/demos/demo_pq_complheap_basico.cpp`

Agrega una función auxiliar o versión instrumentada que permita observar qué hijo se elige durante la bajada:

```cpp
template<class T, class Compare>
std::size_t complHeapPercolateDownCount(std::vector<T>& a, std::size_t n, std::size_t i, Compare comp);
```

La función debe retornar la cantidad de intercambios realizados.

Crea una demostración pequeña donde elimines repetidamente el máximo de un heap y registres:

- máximo eliminado,
- arreglo antes de reparar,
- número de intercambios,
- arreglo después de reparar.

Responde:

1. ¿Por qué después de `delMax` se mueve el último elemento a la raíz?
2. ¿Por qué la reparación baja y no sube?
3. ¿Cómo se decide entre hijo izquierdo e hijo derecho?
4. ¿Qué pasa si el nodo actual tiene un solo hijo?
5. ¿Por qué `delMax` tiene costo `O(log n)`?.

Entrega en este bloque:

- Código modificado.
- Salida de la demostración.
- Trazado manual de una eliminación.

#### Bloque 5 - Validación explícita de la propiedad heap

Revisa:

- `Semana6/include/PQ_ComplHeap.h`
- `Semana6/pruebas_publicas/test_public_week6.cpp`
- `Semana6/pruebas_internas/test_internal_week6.cpp`

Agrega una función de validación, ya sea como método de `PQ_ComplHeap` o como función auxiliar:

```cpp
bool isValidHeap() const;
```

o, si se implementa como función libre:

```cpp
template<class T, class Compare>
bool complHeapIsValid(const std::vector<T>& a, Compare comp);
```

Debe verificar que cada padre tenga prioridad mayor o igual que sus hijos según la convención del comparador usado en la implementación.

Agrega pruebas para:

1. heap vacío,
2. heap con un elemento,
3. heap con elementos repetidos,
4. heap construido por inserciones,
5. heap construido por `heapify`,
6. heap después de varias llamadas a `delMax`.

Responde:

1. ¿Qué invariante verifica la función?
2. ¿Por qué basta revisar relaciones padre-hijo?
3. ¿Por qué no es necesario comparar cada nodo con todos sus descendientes?
4. ¿Cuál es el costo de validar todo el heap?
5. ¿Por qué esta función es útil en pruebas pero no necesariamente en producción?

Entrega en este bloque:

- Código de validación.
- Pruebas agregadas.
- Evidencia de `ctest`.

#### Bloque 6 - Construcción de heap: inserciones sucesivas vs Floyd

Revisa:

- `Semana6/include/PQ_ComplHeap_heapifyFloyd.h`
- `Semana6/include/PQ_ComplHeap_insert.h`
- `Semana6/demos/demo_heapify_floyd.cpp`

Modifica la demostración de `heapify` para comparar dos formas de construir un heap con la misma entrada:

```cpp
{ 4, 17, 3, 90, 55, 21, 8, 13, 34, 2, 1, 89 }
```

Construcción A:

- insertar elementos uno por uno usando `insert`.

Construcción B:

- copiar el vector y aplicar `heapify` de Floyd.

La demostración debe mostrar:

- arreglo inicial,
- arreglo final por inserciones,
- arreglo final por Floyd,
- cantidad aproximada o exacta de intercambios si agregaste contadores,
- validación con `isValidHeap`.

Responde:

1. ¿Por qué ambos resultados pueden ser heaps válidos aunque sus arreglos finales no sean idénticos?
2. ¿Por qué insertar `n` elementos puede costar `O(n log n)`?
3. ¿Por qué Floyd puede construir el heap en `O(n)`?
4. ¿Qué nodos procesa Floyd primero?
5. ¿Por qué Floyd no necesita llamar a `percolateDown` desde las hojas?.

Entrega en este bloque:

- Demostración modificada.
- Tabla comparativa.
- Explicación de complejidad.

#### Bloque 7 - Modificación de `heapSort`

Revisa:

- `Semana6/include/vector_heapSort.h`
- `Semana6/demos/demo_heapsort.cpp`

Agrega una versión de `heapSort` que permita elegir el sentido del resultado:

```cpp
template<class T, class Compare>
void heapSort(std::vector<T>& a, Compare comp, bool ascending);
```

La función debe mantener la idea de heapsort in situ. No uses `std::sort`.

Prueba con:

```cpp
{ 5, 1, 5, 3, 8, 2, 8, 0 }
```

y muestra:

- resultado ascendente,
- resultado descendente,
- comportamiento con repetidos.

Responde:

1. ¿Por qué heapsort puede ordenar in situ?
2. ¿Qué parte del algoritmo destruye gradualmente el heap?
3. ¿Por qué heapsort cuesta `O(n log n)`?
4. ¿Es heapsort estable? Justifica con un ejemplo.
5. ¿Qué diferencia hay entre usar `heapSort` y extraer todos los elementos con `delMax`?

Entrega en este bloque:

- Código modificado.
- Demostración actualizada.
- Evidencia de repetidos.

#### Bloque 8 - Heap izquierdista: validación de `merge`

Revisa:

- `Semana6/include/PQ_LeftHeap.h`
- `Semana6/include/PQ_LeftHeap_merge.h`
- `Semana6/include/PQ_LeftHeap_insert.h`
- `Semana6/include/PQ_LeftHeap_delMax.h`
- `Semana6/demos/demo_left_heap_merge.cpp`

Agrega una función de validación para el heap izquierdista:

```cpp
bool isValidLeftHeap() const;
```

Debe verificar al menos:

1. propiedad de heap,
2. propiedad izquierdista,
3. consistencia de tamaño,
4. consistencia de `npl` o distancia nula, si el código la almacena.

Luego modifica la demostración de `merge` para construir dos heaps, mezclarlos y validar el resultado.

Responde:

1. ¿Por qué `merge` es la operación central del heap izquierdista?
2. ¿Cómo se implementa `insert` usando `merge`?
3. ¿Cómo se implementa `delMax` usando `merge`?
4. ¿Qué propiedad adicional diferencia un heap izquierdista de un heap binario completo?
5. ¿Qué ventaja conceptual tiene un heap izquierdista frente a un heap binario completo?.

Entrega en este bloque:

- Código de validación.
- Demostración modificada.
- Trazado de una fusión pequeña.

#### Bloque 9 - Huffman: modificación de desempate y caso de un símbolo

Revisa:

- `Semana6/include/Huffman_PQ.h`
- `Semana6/include/Huffman_PQ_generateTree.h`
- `Semana6/demos/demo_huffman.cpp`

Modifica el código de Huffman para documentar y probar explícitamente el desempate entre símbolos de igual frecuencia.

Usa este alfabeto:

```cpp
{ {'A', 5}, {'B', 5}, {'C', 10}, {'D', 10}, {'E', 20} }
```

Además, agrega una prueba para el caso extremo de un solo símbolo:

```cpp
{ {'X', 100} }
```

La implementación debe producir un código válido para el único símbolo, por ejemplo `"0"`.

Responde:

1. ¿Por qué Huffman necesita una cola de prioridad?
2. ¿Qué elementos se extraen repetidamente?
3. ¿Qué nodo se vuelve a insertar?
4. ¿Por qué el caso de un solo símbolo requiere cuidado especial?
5. ¿Qué significa que el conjunto de códigos sea libre de prefijos?
6. ¿Cómo afecta el desempate a la forma del árbol?
7. ¿El desempate cambia necesariamente la longitud total ponderada? Justifica.

Entrega en este bloque:

- Código modificado o prueba agregada.
- Tabla símbolo, frecuencia, código, longitud.
- Verificación de prefijo libre.

#### Bloque 10 - Treap: modificación de código, rotaciones e invariantes

Revisa:

- `Semana6/include/Treap.h`
- `Semana6/demos/demo_treap_basico.cpp`
- `Semana6/pruebas_publicas/test_public_week6.cpp`
- `Semana6/pruebas_internas/test_internal_week6.cpp`

Este bloque es obligatorio. Su objetivo es que no uses `Treap` solo como estructura decorativa, sino que entiendas cómo combina dos invariantes simultáneos:

1. propiedad de árbol binario de búsqueda sobre `key`,
2. propiedad de heap sobre `priority`.

En la implementación de Semana 6, una prioridad menor sube más cerca de la raíz. Por eso `bubbleUp` rota mientras el padre tiene prioridad mayor que el nodo insertado.

##### Parte A - Construcción determinística con prioridades fijas

Crea o modifica `demo_treap_basico.cpp` para construir el treap usando `addWithPriority`, no solo `add`, con esta secuencia:

```cpp
{ {50, 50}, {30, 30}, {70, 70}, {20, 20}, {40, 40}, {60, 60}, {80, 80} }
```

Cada par representa:

```cpp
{ clave, prioridad }
```

Después de cada inserción, imprime:

- clave insertada,
- prioridad asignada,
- recorrido inorden,
- recorrido por niveles,
- raíz actual,
- resultado de `isBST()`,
- resultado de `isHeapByPriority()`,
- resultado de `isTreap()`.

Responde:

1. ¿Por qué el recorrido inorden debe salir ordenado aunque las prioridades cambien la forma del árbol?
2. ¿Por qué la raíz no necesariamente es la primera clave insertada?
3. ¿Qué nodo debe subir cuando se inserta una clave con prioridad menor que la de sus ancestros?
4. ¿Qué propiedad conserva una rotación local sobre las claves?
5. ¿Qué propiedad intenta restaurar `bubbleUp` sobre las prioridades?.

Entrega en esta parte:

- demostración modificada,
- salida de al menos cinco inserciones,
- dibujo o `asciiArt()` del árbol final.

##### Parte B - Instrumentación de `bubbleUp`

Agrega una versión instrumentada sin eliminar la función existente:

```cpp
template<class T, class Compare>
std::size_t bubbleUpCount(typename Treap<T, Compare>::Node* u);
```

Si prefieres mantenerla como método interno de la clase, puedes llamarla:

```cpp
std::size_t bubbleUpCount(Node* u);
```

La función debe realizar el mismo proceso que `bubbleUp`, pero retornando cuántas rotaciones se hicieron.

Luego agrega una forma controlada de usarla desde una inserción, por ejemplo:

```cpp
std::size_t addWithPriorityCount(const T& x, std::uint64_t priority);
```

No cambies el comportamiento público de `add` ni de `addWithPriority`.

Prueba con una secuencia que fuerce varias rotaciones:

```cpp
{ {100, 100}, {90, 90}, {80, 80}, {70, 70}, {60, 60} }
```

Responde:

1. ¿Por qué esta secuencia tiende a producir rotaciones repetidas?
2. ¿Cuándo `bubbleUpCount` retorna cero?
3. ¿Cuál es el peor caso de rotaciones durante una inserción?
4. ¿Por qué una rotación no rompe la propiedad BST?
5. ¿Por qué el treap busca mantener altura esperada logarítmica, no altura garantizada logarítmica?

Entrega en esta parte:

- código de la función instrumentada,
- tabla con clave, prioridad, rotaciones y raíz después de insertar,
- explicación de costo esperado.

##### Parte C - Instrumentación de `trickleDown` y eliminación

Agrega una versión instrumentada sin eliminar la función existente:

```cpp
std::size_t trickleDownCount(Node* u);
```

y una eliminación controlada:

```cpp
std::size_t removeCount(const T& x);
```

La eliminación debe rotar el nodo hacia abajo hasta que tenga a lo más un hijo, luego aplicar la lógica equivalente a `splice`.

Usa el treap construido en la Parte A y elimina:

```cpp
50, 20, 70
```

Después de cada eliminación, imprime:

- clave eliminada,
- cantidad de rotaciones,
- recorrido inorden,
- recorrido por niveles,
- `isBST()`,
- `isHeapByPriority()`,
- `isTreap()`.

Responde:

1. ¿Por qué eliminar en un treap no es simplemente borrar como en un BST común?
2. ¿Por qué `trickleDown` elige rotar con el hijo de menor prioridad?
3. ¿Qué ocurre si el nodo tiene solo hijo izquierdo?
4. ¿Qué ocurre si el nodo tiene solo hijo derecho?
5. ¿Qué invariantes deben seguir siendo verdaderos después de `splice`?

Entrega en esta parte:

- código modificado,
- salida de la demostración,
- trazado manual de una eliminación donde haya al menos una rotación.

##### Parte D - Búsqueda ordenada en Treap

Extiende la demostración para probar:

```cpp
findEQ(40)
findEQ(35)
lowerBound(35)
lowerBound(40)
upperBound(40)
upperBound(75)
```

Compara los resultados con lo que produciría `BinarySearchTree` usando las mismas claves.

Responde:

1. ¿Por qué `lowerBound` y `upperBound` dependen de la propiedad BST y no de la propiedad heap?
2. ¿Qué parte del treap se comporta igual que un BST?
3. ¿Qué parte del treap se comporta como heap?
4. ¿Por qué el treap no reemplaza directamente a una cola de prioridad si lo único que quieres es extraer máximos o mínimos repetidamente?
5. ¿En qué situación sí conviene usar una estructura tipo treap?.

Entrega en esta parte:

- tabla comparativa Treap vs `BinarySearchTree`,
- respuestas de búsqueda,
- explicación de qué propiedad se usó en cada operación.

##### Parte E - Pruebas específicas para Treap

Agrega o extiende pruebas para cubrir:

1. treap vacío: `empty()`, `size()`, `isBST()`, `isHeapByPriority()`, `isTreap()`,
2. inserción con prioridades fijas,
3. rechazo de duplicados,
4. inorden ordenado después de insertar,
5. propiedad heap por prioridad después de insertar,
6. `lowerBound` y `upperBound`,
7. eliminación de hoja,
8. eliminación de nodo con un hijo,
9. eliminación de nodo con dos hijos,
10. eliminación de raíz,
11. conservación de enlaces `parent`, si agregas una función pública de validación,
12. consistencia de `size()` después de operaciones mixtas,
13. estabilidad de invariantes después de una secuencia larga de inserciones y eliminaciones.

Responde:

1. ¿Qué bug atraparía una prueba de enlaces `parent`?
2. ¿Qué bug atraparía una prueba de `size()`?
3. ¿Qué bug atraparía una prueba de inorden ordenado?
4. ¿Qué bug atraparía una prueba de prioridad padre-hijo?
5. ¿Por qué conviene usar prioridades fijas en pruebas unitarias?

Entrega en esta parte:

- pruebas agregadas,
- resultado de `ctest --test-dir build-debug -R semana6 --output-on-failure`,
- breve explicación de qué cubre cada prueba.

#### Bloque 11 - Comparación con Semana 5: `BinaryHeap`, `BinarySearchTree` y `Treap`

Revisa:

- `Semana5/include/BinaryHeap.h`
- `Semana5/include/BinarySearchTree.h`
- `Semana6/include/PQ_ComplHeap.h`
- `Semana6/include/Treap.h`
- `Semana6/demos/demo_compare_with_semana5.cpp`
- `Semana6/demos/demo_treap_basico.cpp`

Modifica `demo_compare_with_semana5.cpp` para construir una comparación observable entre:

1. `BinaryHeap` de Semana 5,
2. `PQ_ComplHeap` de Semana 6,
3. `BinarySearchTree` de Semana 5,
4. `Treap` de Semana 6.

La demostración debe mostrar una tabla con columnas:

- estructura,
- operación principal,
- propiedad mantenida,
- operación eficiente,
- operación que no conviene,
- evidencia producida por la demostración.

Responde:

1. ¿Qué diferencia hay entre un heap de prioridad y un árbol de búsqueda?
2. ¿Por qué un BST permite recorrido ordenado y un heap no?
3. ¿Qué agrega `PQ_ComplHeap` frente a un `BinaryHeap` educativo?
4. ¿Qué combina un `Treap`?
5. ¿Qué estructura usarías para extraer máximos repetidamente?
6. ¿Qué estructura usarías para responder `lowerBound` o `upperBound`?
7. ¿Qué estructura usarías si quieres búsqueda ordenada con balanceo probabilístico?.

Entrega en este bloque:

- Demostración modificada.
- Tabla de comparación.
- Respuesta breve de selección de estructura.

#### Bloque 12 - Pruebas obligatorias después de modificar código

Debes agregar o extender pruebas en:

- `Semana6/pruebas_publicas/test_public_week6.cpp`
- `Semana6/pruebas_internas/test_internal_week6.cpp`

Incluye al menos las siguientes pruebas:

1. `PQ_ComplHeap` conserva la propiedad heap después de cada inserción.
2. `PQ_ComplHeap` conserva la propiedad heap después de cada eliminación.
3. `getMax` no cambia el tamaño.
4. `delMax` sí cambia el tamaño.
5. `heapifyFloyd` produce un heap válido.
6. `heapSort` ordena con repetidos.
7. `PQ_LeftHeap` conserva su propiedad después de `merge`.
8. `PQ_LeftHeap` conserva su propiedad después de `insert`.
9. `PQ_LeftHeap` conserva su propiedad después de `delMax`.
10. Huffman produce códigos para todos los símbolos con frecuencia positiva.
11. Huffman produce códigos libres de prefijos.
12. Huffman maneja correctamente el caso de un solo símbolo.
13. `Treap` conserva propiedad BST después de insertar.
14. `Treap` conserva propiedad de heap por prioridad después de insertar.
15. `Treap` conserva ambas propiedades después de eliminar.

Entrega en este bloque:

- Lista de pruebas agregadas.
- Resultado completo de `ctest --output-on-failure`.
- Explicación de qué bug atraparía cada prueba.

#### Bloque 13 - Defensa escrita de modificaciones

Responde en no más de 900 palabras:

¿Qué aprendiste al modificar código de prioridad, heaps, Huffman y Treap que no se aprende solo leyendo o ejecutando demostraciones?

Tu respuesta debe incluir obligatoriamente:

- Una afirmación sobre la interfaz `PQ`.
- Una afirmación sobre la representación implícita del heap binario completo.
- Una afirmación sobre `percolateUp`.
- Una afirmación sobre `percolateDown`.
- Una afirmación sobre `heapify` de Floyd.
- Una afirmación sobre `heapSort`.
- Una afirmación sobre `merge` en heap izquierdista.
- Una afirmación sobre Huffman.
- Una afirmación sobre `Treap`, rotaciones, prioridades y búsqueda ordenada.
- Una afirmación sobre comparación con `BinaryHeap` y `BinarySearchTree`.
- Una afirmación sobre pruebas, invariantes y casos borde.


#### Formato sugerido de entrega

```markdown
## Actividad 6 - CC232

### Estudiante
- Nombre:
- Código:
- Fecha:

### Resumen de modificaciones
| Bloque | Archivo modificado | Cambio realizado | Evidencia |
|---|---|---|---|

### Bloque 1 - Diagnóstico inicial
[Comandos, resultados y explicación]

### Bloque 2 - Utilidades de heap completo
[Código, explicación y evidencia]

### Bloque 3 - Conteo en percolateUp
[Código, salida y análisis]

### Bloque 4 - Conteo en percolateDown
[Código, salida y análisis]

### Bloque 5 - Validación de propiedad heap
[Código, pruebas y explicación]

### Bloque 6 - Inserciones sucesivas vs Floyd
[Demostración, tabla y complejidad]

### Bloque 7 - heapSort
[Código, pruebas y discusión de estabilidad]

### Bloque 8 - Heap izquierdista
[Código, validación y trazado]

### Bloque 9 - Huffman
[Código, tabla de códigos y prefijo libre]

### Bloque 10 - Treap
[Rotaciones, inserción, eliminación, búsquedas y pruebas]

### Bloque 11 - Comparación con Semana 5
[Tabla y selección de estructura]

### Bloque 12 - Pruebas
[Lista de pruebas, salida de ctest y explicación]

### Bloque 13 - Defensa escrita
[Respuesta final]
```

#### Criterio general de evaluación

Se espera evidencia de trabajo directo sobre el código. La actividad será evaluada principalmente por:

1. Claridad de las modificaciones.
2. Conservación de la interfaz pública cuando corresponda.
3. Uso correcto de invariantes.
4. Pruebas con casos borde.
5. Comparación razonada entre estructuras.
6. Explicación de costos.
7. Capacidad de sustentar oralmente los cambios.
8. Calidad de los ejercicios adicionales de codificación: modularidad, pruebas, casos borde y respeto de invariantes.

Pasar las pruebas no es suficiente. Debes poder explicar por qué tus cambios preservan la propiedad de heap, la propiedad izquierdista, la validez del árbol de Huffman, la propiedad BST del `Treap` y la diferencia entre estructuras para prioridad y estructuras para búsqueda ordenada.

---
---

## Actividad 6 - CC232

### Estudiante
- Nombre: Paul Flores Enrique Alejandro
- Codigo:
- Fecha: 2026-06-12

### Resumen de modificaciones

| Bloque | Archivo modificado | Cambio realizado | Evidencia |
|---|---|---|---|
| 2 | include/PQ_ComplHeap_macro.h | auxiliares constexpr pqHasLeftChild, pqHasRightChild, pqIsLeaf, pqIsInternal | compila, ctest 2/2 |
| 2 | include/PQ_ComplHeap_percolateDown.h | usa pqIsInternal y pqHasRightChild en las pruebas de frontera | compila, ctest 2/2 |
| 3 | include/PQ_ComplHeap_percolateUp.h | nueva funcion complHeapPercolateUpCount que cuenta intercambios | demo_percolate_up_count |
| 3 | demos/demo_percolate_up_count.cpp | demo que inserta la secuencia y muestra intercambios y heap | salida del demo |
| 3 | CMakeLists.txt | registra el target sem6_demo_percolate_up_count | compila |

### Bloque 1 - Diagnostico inicial

| Comando | Resultado | Error | Interpretacion |
|---|---|---|---|
| cmake -S . -B build | configuracion correcta | ninguno | el proyecto se configura bien |
| cmake --build build | compila todos los targets | ninguno | el codigo de la semana compila sin problemas |
| ctest --test-dir build | 2 de 2 pruebas pasan (semana6_public, semana6_internal) | ninguno | las pruebas pasan sin modificar nada |

1. Aparecen estos targets: sem6_demo_pq_complheap_basico, sem6_demo_heapify_floyd, sem6_demo_heapsort, sem6_demo_left_heap_merge, sem6_demo_huffman, sem6_demo_compare_with_semana5, sem6_demo_bst_rotations, sem6_demo_treap_basico, sem6_demo_capitulo6_panorama, sem6_demo_percolate_up_count, y las pruebas sem6_test_public y sem6_test_internal.

2. Desde Capitulo6.h se incluyen PQ.h, PQ_ComplHeap_macro.h y PQ_ComplHeap.h con sus operaciones (getMax, insert, percolateUp, delMax, percolateDown, heapifyFloyd), el heap izquierdista PQ_LeftHeap.h con merge, insert y delMax, el ordenamiento vector_heapSort.h, la codificacion Huffman_PQ.h y el Treap.h.

3. Capitulo10.h no agrega nada nuevo: por dentro solo incluye Capitulo6.h. Existe por la numeracion de capitulos de Morin (capitulo 10), pero en la practica los dos dan acceso al mismo conjunto de estructuras.

4. Dependen de Semana 5 la comparacion con BinaryHeap y BinarySearchTree (demo_compare_with_semana5) y el Treap, que reutiliza la idea de arbol binario de busqueda. La semana se apoya en BinaryTree, BinaryHeap y BinarySearchTree de la Semana 5.

5. Para prioridad pura se usa PQ_ComplHeap, el heap binario completo, que funciona como cola de prioridad.

6. Para busqueda ordenada se usa el BinarySearchTree de la Semana 5, o el lado BST del Treap.

7. La estructura que mezcla busqueda ordenada con prioridad es el Treap, que es BST por la clave y heap por la prioridad.

8. Al ejecutar las pruebas sin modificar nada, las dos pruebas semana6_public y semana6_internal pasan, 2 de 2, lo que confirma que la base de la semana funciona antes de empezar a intervenir el codigo.

Archivos que planeo modificar: PQ_ComplHeap_macro.h, PQ_ComplHeap_percolateDown.h, PQ_ComplHeap_percolateUp.h, PQ_ComplHeap.h, PQ_ComplHeap_heapifyFloyd.h, vector_heapSort.h, PQ_LeftHeap.h, Huffman_PQ.h, Treap.h, las pruebas y demos correspondientes, y el CMakeLists.txt.

### Bloque 2 - Utilidades de heap completo

Codigo agregado en PQ_ComplHeap_macro.h:

```cpp
// MOD-A6-B2: auxiliares de frontera para hijos y clasificacion de nodos
inline constexpr bool pqHasLeftChild(std::size_t i, std::size_t n) noexcept {
  return pqLeftChild(i) < n;
}
inline constexpr bool pqHasRightChild(std::size_t i, std::size_t n) noexcept {
  return pqRightChild(i) < n;
}
inline constexpr bool pqIsLeaf(std::size_t i, std::size_t n) noexcept {
  return !pqHasLeftChild(i, n);
}
inline constexpr bool pqIsInternal(std::size_t i, std::size_t n) noexcept {
  return pqHasLeftChild(i, n);
}
```

Cambio en PQ_ComplHeap_percolateDown.h: el bucle pasa a usar pqIsInternal(i, n) y la prueba del hijo derecho usa pqHasRightChild(i, n).

Respuestas:

1. Conviene porque encapsulan la aritmetica de la representacion implicita (2i+1, 2i+2, (i-1)/2) en un solo lugar con nombre claro, lo que mejora la legibilidad, concentra los errores de frontera en un punto y deja una sola fuente de verdad si cambiara la convencion de indexado.

2. constexpr respeta el sistema de tipos y el ambito, no tiene los problemas de sustitucion textual de los macros, evalua sus argumentos una sola vez y se puede depurar, mientras que tambien se evalua en tiempo de compilacion como un macro.

3. El caso borde es el ultimo nodo interno cuando n es par: tiene hijo izquierdo pero no derecho (2i+2 igual a n). Sin la guarda pqHasRightChild se leeria a[2i+2] fuera del arreglo, asi que el candidato debe quedarse con el hijo izquierdo.

4. Una hoja es un nodo sin hijo izquierdo, es decir 2i+1 mayor o igual que n, que es justo lo que comprueba pqIsLeaf. En un heap completo basta revisar el hijo izquierdo porque si falta ese, tampoco existe el derecho.

5. Solo cambio la expresion de las condiciones de frontera: el while pasa de pqInHeap(pqLeftChild(i), n) a pqIsInternal(i, n), y la prueba del hijo derecho de pqInHeap(r, n) a pqHasRightChild(i, n). El comportamiento es identico, solo mejoro la intencion del codigo.

La complejidad no cambia porque las auxiliares son constexpr y hacen O(1), exactamente el mismo trabajo que las expresiones que reemplazaron. percolateDown sigue bajando un nivel por iteracion en un arbol de altura log n, asi que se mantiene en O(log n). Evidencia: el proyecto compila y ctest pasa 2 de 2.

### Bloque 3 - Conteo en percolateUp

Funcion nueva en PQ_ComplHeap_percolateUp.h (sin tocar la original):

```cpp
// MOD-A6-B3: variante instrumentada que cuenta intercambios de percolateUp
template <class T, class Compare>
std::size_t complHeapPercolateUpCount(std::vector<T>& a, std::size_t i, Compare comp) {
  std::size_t swaps = 0;
  while (pqHasParent(i)) {
    const std::size_t p = pqParent(i);
    if (!comp(a[p], a[i])) {
      break;
    }
    std::swap(a[p], a[i]);
    ++swaps;
    i = p;
  }
  return swaps;
}
```

Salida del demo demo_percolate_up_count con la secuencia {40, 10, 70, 30, 90, 20, 80, 60}:

| insert | intercambios | heap interno |
|---|---|---|
| 40 | 0 | [40] |
| 10 | 0 | [40, 10] |
| 70 | 1 | [70, 10, 40] |
| 30 | 1 | [70, 30, 40, 10] |
| 90 | 2 | [90, 70, 40, 10, 30] |
| 20 | 0 | [90, 70, 40, 10, 30, 20] |
| 80 | 1 | [90, 70, 80, 10, 30, 20, 40] |
| 60 | 1 | [90, 70, 80, 60, 30, 20, 40, 10] |

En todos los pasos la propiedad de heap quedo OK.

Respuestas:

1. percolateUp hace cero intercambios cuando el elemento insertado ya no es mayor que su padre, asi que no necesita subir. En el demo, insertar 10 y 20 dio cero intercambios.

2. Puede hacer O(log n) intercambios cuando el elemento insertado es el nuevo maximo o muy grande: sube desde la ultima hoja hasta la raiz, recorriendo la altura del arbol, que es log n. En el demo, insertar 90 subio dos veces.

3. El nodo se inserta como ultima hoja, en el nivel mas profundo, asi que el numero maximo de intercambios es igual a la profundidad de esa hoja, que es a lo mas la altura del heap, del orden de log n.

4. Porque el heap solo garantiza la relacion padre-hijo, no un orden total de izquierda a derecha. El arreglo final [90, 70, 80, 60, 30, 20, 40, 10] es un heap valido pero no esta ordenado.

5. Queda garantizada la propiedad de heap: cada padre es mayor o igual que sus hijos, asi que el maximo queda en la raiz. La columna propiedad heap = OK lo confirma en cada insercion.

Argumento de costo: cada percolateUp sube a lo mas la altura del heap, O(log n) por insercion, y contar los intercambios solo agrega un incremento O(1) por intercambio, asi que no cambia la complejidad.

### Bloque 4 - Conteo en percolateDown

Funcion nueva en PQ_ComplHeap_percolateDown.h (sin tocar la original):

```cpp
// MOD-A6-B4: variante instrumentada que cuenta intercambios de percolateDown
template <class T, class Compare>
std::size_t complHeapPercolateDownCount(std::vector<T>& a, std::size_t n, std::size_t i, Compare comp) {
  std::size_t swaps = 0;
  while (pqIsInternal(i, n)) {
    std::size_t c = pqLeftChild(i);
    const std::size_t r = pqRightChild(i);
    if (pqHasRightChild(i, n) && comp(a[c], a[r])) {
      c = r;
    }
    if (!comp(a[i], a[c])) {
      break;
    }
    std::swap(a[i], a[c]);
    ++swaps;
    i = c;
  }
  return swaps;
}
```

Salida del demo demo_percolate_down_count (heap inicial por Floyd [90, 60, 80, 40, 10, 20, 70, 30]):

| delMax | antes de reparar | intercambios | despues de reparar |
|---|---|---|---|
| 90 | [30, 60, 80, 40, 10, 20, 70] | 2 | [80, 60, 70, 40, 10, 20, 30] |
| 80 | [30, 60, 70, 40, 10, 20] | 1 | [70, 60, 30, 40, 10, 20] |
| 70 | [20, 60, 30, 40, 10] | 2 | [60, 40, 30, 20, 10] |
| 60 | [10, 40, 30, 20] | 2 | [40, 20, 30, 10] |
| 40 | [10, 20, 30] | 1 | [30, 20, 10] |
| 30 | [10, 20] | 1 | [20, 10] |
| 20 | [10] | 0 | [10] |
| 10 | [] | 0 | [] |

Respuestas:

1. Porque al quitar el maximo queda un hueco en la raiz. Para mantener el arbol completo, sin huecos, se mueve el ultimo elemento del arreglo a la raiz y se reduce el tamaño, asi la forma sigue siendo un heap completo.

2. Porque el elemento que se movio a la raiz suele ser pequeño, ya que venia de una hoja, de modo que probablemente viola la propiedad respecto a sus hijos y no respecto a un padre, pues la raiz no tiene padre. Por eso hay que hacerlo descender, intercambiandolo con el mayor de sus hijos, hasta su lugar.

3. Se elige el hijo con mayor prioridad, que en este max-heap es el mayor de los dos. El codigo parte con el hijo izquierdo y, si existe el derecho y es mayor, cambia al derecho; luego intercambia el nodo con ese hijo dominante solo si el nodo es menor que el.

4. Si el nodo tiene un solo hijo, solo puede ser el izquierdo, porque en un heap completo si falta el izquierdo tampoco hay derecho. La guarda pqHasRightChild evita leer el derecho inexistente, asi que el candidato se queda con el hijo izquierdo y se compara solo con el.

5. Porque el trabajo dominante es percolateDown, que en el peor caso baja desde la raiz hasta una hoja recorriendo la altura del arbol, que es del orden de log n. Mover el ultimo elemento y quitar son O(1), asi que el total es O(log n).

Trazado manual de la primera eliminacion (heap [90, 60, 80, 40, 10, 20, 70, 30]):
- delMax devuelve 90, que estaba en la raiz.
- Se mueve el ultimo (30) a la raiz y se reduce el tamaño: [30, 60, 80, 40, 10, 20, 70].
- percolateDown desde el indice 0: el 30 mira a sus hijos 60 (indice 1) y 80 (indice 2); el mayor es 80, y como 30 < 80 se intercambian. Queda [80, 60, 30, 40, 10, 20, 70], primer intercambio.
- Ahora el 30 esta en el indice 2; sus hijos son 20 (indice 5) y 70 (indice 6); el mayor es 70, y como 30 < 70 se intercambian. Queda [80, 60, 70, 40, 10, 20, 30], segundo intercambio.
- El 30 queda en el indice 6, que no tiene hijos, asi que termina. Resultado [80, 60, 70, 40, 10, 20, 30] con 2 intercambios, igual que en el demo.

### Bloque 5 - Validacion de propiedad heap

Funcion libre agregada en PQ_ComplHeap.h, mas un metodo isValidHeap que la usa:

```cpp
// MOD-A6-B5: cada padre debe tener prioridad mayor o igual que sus hijos.
template <class T, class Compare>
bool complHeapIsValid(const std::vector<T>& a, Compare comp) {
  const std::size_t n = a.size();
  for (std::size_t i = 0; i < n; ++i) {
    if (pqHasLeftChild(i, n) && comp(a[i], a[pqLeftChild(i)])) {
      return false;
    }
    if (pqHasRightChild(i, n) && comp(a[i], a[pqRightChild(i)])) {
      return false;
    }
  }
  return true;
}

// dentro de la clase PQ_ComplHeap:
bool isValidHeap() const { return complHeapIsValid(data_, comp_); }
```

Pruebas agregadas en pruebas_internas/test_isvalid_heap.cpp (registradas en ctest como semana6_isvalid):
1. heap vacio, que debe ser valido.
2. heap con un solo elemento, valido.
3. heap con elementos repetidos (cinco cincos tras heapify), valido.
4. heap construido por inserciones de {40, 10, 70, 30, 90, 20, 80, 60}, valido.
5. heap construido por heapify de {4, 17, 3, 90, 55, 21, 8, 13, 34, 2, 1, 89}, valido.
6. heap despues de tres delMax, valido.
Ademas un caso negativo: el arreglo {1, 2, 3} no es un max-heap y la funcion lo detecta.

Evidencia: ctest pasa 3 de 3 (semana6_public, semana6_internal y semana6_isvalid).

Respuestas:

1. Verifica la propiedad de heap: que cada padre tenga prioridad mayor o igual que sus hijos segun el comparador. Con std::less, que es un max-heap, eso significa que ningun padre sea menor que alguno de sus hijos.

2. Porque la propiedad de heap se define solo entre cada padre y sus hijos directos. Por transitividad, si cada padre domina a sus hijos, entonces domina tambien a todos sus descendientes, asi que revisar los enlaces directos ya garantiza el orden en todo el subarbol.

3. Por la transitividad de la relacion: si el padre es mayor o igual que su hijo, y el hijo es mayor o igual que el nieto, entonces el padre es mayor o igual que el nieto sin compararlos directamente. Comparar contra todos los descendientes seria redundante y mas costoso.

4. Es O(n), porque recorre los n nodos una sola vez y por cada uno hace a lo mas dos comparaciones O(1) con sus hijos.

5. En las pruebas es util para comprobar que las operaciones como insert, delMax o heapify dejan un heap valido, lo que ayuda a atrapar errores. En produccion esas operaciones ya estan diseñadas para mantener el invariante, asi que validar todo el heap en cada operacion costaria O(n) extra sin aportar nada, y solo se usaria para depurar.

### Bloque 6 - Inserciones sucesivas vs Floyd

Demostracion en demos/demo_heapify_compare.cpp, que construye el heap de las dos formas con la entrada {4, 17, 3, 90, 55, 21, 8, 13, 34, 2, 1, 89} y cuenta los intercambios con las funciones instrumentadas.

Tabla comparativa (salida real del demo):

| Construccion | Arreglo final | Intercambios | Valido |
|---|---|---|---|
| Por inserciones | [90, 55, 89, 34, 17, 21, 8, 4, 13, 2, 1, 3] | 9 | si |
| Por Floyd | [90, 55, 89, 34, 4, 21, 8, 13, 17, 2, 1, 3] | 7 | si |

Los dos arreglos son distintos pero ambos cumplen la propiedad de heap, y Floyd hizo menos intercambios (7 contra 9).

Respuestas:

1. Porque un mismo conjunto de elementos admite muchos heaps validos distintos; la propiedad de heap solo exige la relacion padre-hijo, no un orden unico de izquierda a derecha. Las dos construcciones llegan a acomodos diferentes que igual cumplen la propiedad, como se ve en que ambos resultan validos aunque sus arreglos no coinciden.

2. Porque cada insercion hace percolateUp, que en el peor caso sube desde la hoja hasta la raiz recorriendo la altura, O(log n). Como se hacen n inserciones, el total puede llegar a O(n log n).

3. Porque Floyd aplica percolateDown solo a los nodos internos, de abajo hacia arriba, y el costo de cada uno depende de su altura y no de log n para todos. La mayoria de los nodos estan cerca de las hojas y bajan poco; al sumar el trabajo por niveles la serie da O(n).

4. Floyd procesa primero los nodos internos mas bajos, es decir los que estan justo encima de las hojas, y va subiendo hasta la raiz. En el codigo empieza en el indice n/2 - 1 y baja los indices hasta 0.

5. Porque una hoja no tiene hijos, asi que ya cumple de forma trivial la propiedad de heap y no hay nada que reparar hacia abajo. Por eso Floyd arranca desde el ultimo nodo interno y omite las hojas, que son los indices desde n/2 hasta n-1.

Explicacion de complejidad: construir por inserciones cuesta O(n log n) y por Floyd O(n). En esta entrada pequeña Floyd hizo 7 intercambios contra 9 de las inserciones, lo que es coherente con que Floyd es asintoticamente mas barato para construir el heap de golpe.

### Bloque 7 - heapSort

Funcion agregada en vector_heapSort.h (in situ, sin std::sort):

```cpp
template <class T, class Cmp>
void heapSortImpl(std::vector<T>& a, Cmp cmp) {
  complHeapHeapifyFloyd(a, cmp);
  for (std::size_t n = a.size(); n > 1; --n) {
    std::swap(a[0], a[n - 1]);
    complHeapPercolateDown(a, n - 1, 0, cmp);
  }
}

template <class T, class Compare>
void heapSort(std::vector<T>& a, Compare comp, bool ascending) {
  if (a.size() < 2) {
    return;
  }
  if (ascending) {
    heapSortImpl(a, comp);                                   // heap maximo -> ascendente
  } else {
    heapSortImpl(a, [comp](const T& x, const T& y) { return comp(y, x); });  // heap minimo -> descendente
  }
}
```

Salida del demo demo_heapsort_dir con la entrada {5, 1, 5, 3, 8, 2, 8, 0}:
- ascendente: [0, 1, 2, 3, 5, 5, 8, 8]
- descendente: [8, 8, 5, 5, 3, 2, 1, 0]

Evidencia de repetidos: los valores repetidos 5 y 8 aparecen juntos en ambos resultados, sin perderse ni duplicarse.

Respuestas:

1. Porque trabaja sobre el mismo arreglo: construye el heap sobre el vector y luego, en cada paso, intercambia la raiz con el ultimo elemento del heap actual y reduce el tamaño del heap en uno, dejando ese elemento ya ordenado al final. No necesita memoria extra aparte de unas variables.

2. El bucle de extraccion. En cada iteracion saca la raiz, que es el maximo, hacia el final y reduce el tamaño del heap, asi el heap se va achicando hasta desaparecer mientras la parte ordenada al final va creciendo.

3. Porque construir el heap con Floyd es O(n), pero luego se hacen n extracciones y cada una aplica percolateDown que es O(log n), lo que da O(n log n) en total, y ese termino domina.

4. No es estable. Los intercambios de la raiz con el ultimo y los percolateDown mueven los elementos sin respetar el orden original entre claves iguales. Por ejemplo en {5, 1, 5, 3, 8, 2, 8, 0} hay dos 5 y dos 8; con enteros no se nota porque son identicos, pero si fueran objetos con un campo extra (como dos registros con la misma clave), heapsort podria invertir su orden relativo, que es justo lo que una ordenacion estable evita.

5. heapSort ordena el mismo arreglo in situ, sin memoria extra, colocando cada maximo extraido al final del propio vector. Extraer con delMax saca los elementos del heap y lo vacia, y normalmente hay que ir guardandolos en otra estructura, lo que usa memoria extra y destruye el heap. El orden resultante es el mismo, pero heapSort lo logra en el lugar.

### Bloque 13 - Defensa escrita

Al modificar el codigo de la Semana 6 aprendi cosas que leyendo o solo ejecutando demos no se ven, porque al intervenir el codigo uno tiene que entender de verdad que invariante se preserva y donde se actualiza.

Sobre la interfaz PQ entendi que es un contrato abstracto (insert, getMax, delMax, empty y size) que separa lo que una cola de prioridad ofrece de como se implementa; PQ_ComplHeap la realiza con un heap, pero el mismo contrato podria cumplirlo otra estructura.

Sobre la representacion implicita del heap binario completo, al escribir las auxiliares pqHasLeftChild, pqHasRightChild, pqIsLeaf y pqIsInternal me quedo claro que la forma del arbol vive en los indices del arreglo y en las formulas 2i+1, 2i+2 y (i-1)/2, sin necesidad de punteros.

Sobre percolateUp, al instrumentarla para contar intercambios vi que solo actua hacia arriba despues de una insercion y que hace entre cero y O(log n) intercambios segun que tan grande sea el elemento insertado.

Sobre percolateDown, al contar sus intercambios y reescribir sus pruebas de frontera entendi que repara hacia abajo eligiendo siempre el hijo dominante, y que el caso del nodo con un solo hijo hay que cuidarlo para no leer fuera del arreglo.

Sobre heapify de Floyd, al comparar construir por inserciones contra Floyd comprobe con datos que ambos dan heaps validos pero distintos, y que Floyd hace menos trabajo, 7 contra 9 intercambios, porque procesa de abajo hacia arriba y omite las hojas, lo que explica su costo O(n).

Sobre heapSort, al agregarle el sentido ascendente o descendente entendi que ordena in situ apoyandose en extracciones del heap, que invertir el comparador cambia el sentido del resultado, y que no es un metodo estable.

Sobre merge en el heap izquierdista, aunque me concentre en los heaps completos, quedo claro que en un heap izquierdista la operacion central es merge, y que insert y delMax se construyen sobre ella, lo que lo hace natural para fusionar dos colas de prioridad.

Sobre Huffman entendi que es una aplicacion de las colas de prioridad, donde se extraen repetidamente los dos nodos de menor frecuencia y se reinserta el nodo combinado, y que el caso de un solo simbolo necesita cuidado para producir igual un codigo valido.

Sobre el Treap, las rotaciones, las prioridades y la busqueda ordenada, vi que combina dos invariantes a la vez, BST por la clave y heap por la prioridad, y que las rotaciones reacomodan las prioridades sin romper el orden de las claves, lo que da busqueda ordenada con altura esperada logaritmica.

Sobre la comparacion con BinaryHeap y BinarySearchTree de la Semana 5, confirme que el heap sirve para prioridad pura, como obtener el minimo o el maximo rapido, y el BST para busqueda ordenada, como el recorrido inorden, lowerBound y upperBound, y que el Treap es un hibrido entre ambos.

Sobre pruebas, invariantes y casos borde, lo que mas aprendi es que pasar las pruebas no basta: al escribir complHeapIsValid y sus casos (vacio, un elemento, repetidos, por inserciones, por Floyd y tras delMax) entendi que validar el invariante de forma explicita y cubrir los casos borde es lo que de verdad demuestra que una modificacion preserva la propiedad de heap. En resumen, modificar el codigo me obligo a justificar cada cambio en terminos de invariante, costo y casos borde, algo que solo leer o ejecutar no exige.
