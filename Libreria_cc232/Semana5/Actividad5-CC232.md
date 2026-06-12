### Actividad 5 - CC232

- Duración: 3 horas de clase.
- Modalidad: Trabajo individual.
- Entrega: Un archivo llamado `Actividad5-CC232.md`.

#### Objetivo

Consolidar lo trabajado en la Semana 5 a partir de lectura de código, ejecución de demos, revisión de pruebas, trazado manual y defensa escrita breve.

La meta es distinguir con claridad tres niveles de trabajo con árboles:

1. La infraestructura enlazada base: `BinNode` y `BinTree`.
2. La navegación y los recorridos de un árbol binario: `BinaryTree`, sucesor, predecesor, profundidad, altura, tamaño de subárbol e iteración inorden.
3. Las estructuras especializadas de la semana: `BinarySearchTree` y `BinaryHeap`.

Además, se busca conectar la implementación de la semana con las ideas de Morin y Deng: árboles binarios enlazados, mantenimiento de alturas, recorridos recursivos e iterativos, sucesor inorden, recorrido por niveles, representación implícita de heaps, búsqueda en BST, eliminación, `splice`, rotaciones y validación de invariantes.

#### Material de trabajo

##### Código de la semana

- `Semana5/README.md`
- `Semana5/include/BinNode.h`
- `Semana5/include/BinTree.h`
- `Semana5/include/BinaryTree.h`
- `Semana5/include/BinarySearchTree.h`
- `Semana5/include/BinaryHeap.h`
- `Semana5/include/Capitulo5.h`
- `Semana5/demos/demo_binary_tree.cpp`
- `Semana5/demos/demo_bst.cpp`
- `Semana5/demos/demo_heap.cpp`
- `Semana5/demos/demo_capitulo5_panorama.cpp`
- `Semana5/pruebas_publicas/test_public_week5.cpp`
- `Semana5/pruebas_internas/test_internal_week5.cpp`
- `Semana5/lecturas/Notas.md`
- `Semana5/Ejercicios5-CC232.md`

##### Lecturas obligatorias

- Lectura de Deng asociadas a `BinNode`, `BinTree`, mantenimiento de alturas, recorridos, sucesor inorden y recorrido por niveles dado en el repositorio.
- Secciones de Morin asociadas a `BinaryTree`, `BinaryHeap` y `BinarySearchTree` dado en el repositorio.

#### Bloque 1 - Núcleo conceptual de la semana

Revisa:

- `Semana5/README.md`
- `Semana5/lecturas/Notas.md`
- `Semana5/include/BinNode.h`
- `Semana5/include/BinTree.h`
- `Semana5/include/BinaryTree.h`
- `Semana5/include/BinarySearchTree.h`
- `Semana5/include/BinaryHeap.h`

Responde:

1. Explica con tus palabras qué diferencia hay entre un árbol binario enlazado y un árbol binario almacenado implícitamente en un arreglo.
2. Explica qué información guarda un `BinNode`: dato, padre, hijo izquierdo, hijo derecho y altura.
3. Explica por qué el puntero `parent` permite implementar operaciones como `succ()`, `pred()` y actualización ascendente de alturas.
4. Explica qué responsabilidad tiene `BinTree` frente a `BinNode`.
5. Explica qué agrega `BinaryTree` sobre la infraestructura base de `BinTree`.
6. Explica qué propiedad adicional convierte un árbol binario en un `BinarySearchTree`.
7. Explica qué propiedad adicional convierte un arreglo en un `BinaryHeap` mínimo.
8. Compara la propiedad de orden de un BST con la propiedad de prioridad de un heap.
9. Explica por qué un recorrido inorden de un BST produce una secuencia ordenada.
10. Explica por qué un heap no permite, por sí solo, recorrer los elementos en orden sin destruir o copiar la estructura.


#### Bloque 2 - Navegación, altura, profundidad y tamaño

Revisa:

- `Semana5/include/BinNode.h`
- `Semana5/include/BinTree.h`
- `Semana5/include/BinaryTree.h`
- `Semana5/demos/demo_binary_tree.cpp`

Responde:

1. En `BinNode`, explica qué significan `hasLeft()`, `hasRight()`, `isRoot()`, `isLeaf()`, `isLeftChild()` e `isRightChild()`.
2. Explica el caso en que `succ()` baja al subárbol derecho y luego busca el nodo más a la izquierda.
3. Explica el caso en que `succ()` sube por los ancestros hasta encontrar el primer giro hacia la izquierda.
4. Explica simétricamente cómo debe funcionar `pred()`.
5. Dibuja un árbol de al menos 7 nodos y marca el sucesor y predecesor inorden de tres nodos distintos.
6. Explica qué calcula `depth(u)` y por qué puede implementarse subiendo por `parent`.
7. Explica qué calcula `height(u)` y por qué suele implementarse bajando recursivamente por los hijos.
8. Explica qué calcula `subtreeSize(u)`.
9. Demuestra que para todo nodo `u` se cumple `depth(u) + height(u) <= height(T)`.
10. Indica la condición necesaria y suficiente para que se alcance la igualdad anterior.

#### Bloque 3 - Recorridos y trazado guiado

Revisa:

- `Semana5/include/BinNode.h`
- `Semana5/include/BinTree.h`
- `Semana5/demos/demo_binary_tree.cpp`
- `Semana5/demos/demo_capitulo5_panorama.cpp`

Construye una tabla con cinco columnas:

- Recorrido
- Versión revisada
- Estructura auxiliar usada
- Secuencia producida en el árbol de prueba
- Argumento de correctitud y costo

Incluye en la tabla:

- preorden recursivo,
- preorden iterativo,
- inorden recursivo,
- inorden iterativo `#1`,
- inorden iterativo `#2`,
- inorden iterativo `#3`,
- postorden recursivo,
- postorden iterativo,
- recorrido por niveles.

Luego responde:

1. ¿Qué significa visitar un nodo en preorden?
2. ¿Qué significa visitar un nodo en inorden?
3. ¿Qué significa visitar un nodo en postorden?
4. ¿Qué significa visitar un árbol por niveles?
5. ¿Por qué los recorridos recursivos tienen tiempo `O(n)`?
6. ¿Por qué las versiones iterativas también tienen tiempo `O(n)`?
7. ¿Cuál es la memoria auxiliar de un recorrido recursivo en un árbol balanceado?
8. ¿Cuál es la memoria auxiliar de un recorrido recursivo en un árbol degenerado?
9. ¿Qué diferencia hay entre usar una pila explícita y usar la pila de llamadas?
10. ¿Por qué la cola del recorrido por niveles puede crecer mucho más en un árbol completo que en un árbol degenerado?.

#### Bloque 4 - Demostración: evidencia observable

Revisa y ejecuta:

- `Semana5/demos/demo_binary_tree.cpp`
- `Semana5/demos/demo_bst.cpp`
- `Semana5/demos/demo_heap.cpp`
- `Semana5/demos/demo_capitulo5_panorama.cpp`

Construye una tabla con cuatro columnas:

- Archivo
- Salida u observable importante
- Idea estructural
- Argumento de costo, espacio o diseño

Luego responde:

1. En `demo_binary_tree.cpp`, ¿qué salida permite verificar que los recorridos visitan los nodos en el orden esperado?
2. ¿Qué parte de la demo permite defender que `succ()` y `pred()` respetan el orden inorden?
3. ¿Qué evidencia produce la representación ASCII del árbol?
4. En `demo_bst.cpp`, ¿qué observable permite defender que el inorden del BST queda ordenado?
5. ¿Qué operaciones de búsqueda se distinguen mejor en la demo del BST: `find`, `findEQ`, `lowerBound` o `upperBound`?
6. En `demo_heap.cpp`, ¿qué salida permite defender que el mínimo queda en la raíz?
7. ¿Qué evidencia permite distinguir entre insertar con `add()` y construir con `heapify()`?
8. En `demo_capitulo5_panorama.cpp`, ¿qué comparación resume mejor la semana: árbol enlazado, BST o heap?.

#### Bloque 5 - Pruebas públicas, pruebas internas e invariantes

Revisa:

- `Semana5/pruebas_publicas/test_public_week5.cpp`
- `Semana5/pruebas_internas/test_internal_week5.cpp`

Responde:

1. ¿Qué operaciones del BST valida la prueba pública?
2. ¿Qué casos validan que el BST no acepta duplicados?
3. ¿Qué se verifica al comparar el inorden recursivo con las versiones iterativas?
4. ¿Qué se espera de `findEQ(8)` en la prueba pública?
5. ¿Qué se espera de `lowerBound(9)` y `upperBound(8)`?
6. ¿Qué propiedad se valida con `isBST()`?
7. ¿Qué se valida después de eliminar un nodo con `remove()`?
8. ¿Qué valida `checkParentLinks()` después de borrar, separar o adjuntar subárboles?
9. ¿Qué operaciones del heap valida la prueba pública?
10. ¿Qué demuestra extraer repetidamente de un min-heap hasta vaciarlo?
11. ¿Qué operaciones de `BinTree` se validan con `attachAsRC`, `secede` y `removeSubtree`?
12. ¿Qué agregan las pruebas internas respecto a rotaciones, `bubbleUp`, `trickleDown`, profundidad, altura, sucesor y predecesor?
13. ¿Qué sí demuestra pasar las pruebas públicas?
14. ¿Qué no demuestra pasar las pruebas públicas?
15. ¿Por qué una defensa correcta debe mencionar invariantes y complejidad además de resultados observables?.


#### Bloque 6 - Lectura cercana: `BinNode`, `BinTree` y `BinaryTree`

Revisa:

- `Semana5/include/BinNode.h`
- `Semana5/include/BinTree.h`
- `Semana5/include/BinaryTree.h`

Responde:

1. En `BinNode`, ¿qué invariantes deben mantenerse entre `parent`, `left` y `right`?
2. ¿Por qué `insertAsLC` e `insertAsRC` deben rechazar una inserción cuando el hijo correspondiente ya existe?
3. Explica cómo `size()` de `BinNode` recorre el subárbol.
4. Explica cómo funcionan `leftmost()` y `rightmost()`.
5. Explica paso a paso cómo funciona `succ()`.
6. Explica paso a paso cómo funciona `pred()`.
7. En `BinTree`, ¿qué papel cumplen `root_` y `size_`?
8. Explica qué hace `updateHeight(Node*)`.
9. Explica qué hace `updateHeightAbove(Node*)` y por qué sube hacia la raíz.
10. Explica cómo `attachAsLC` o `attachAsRC` transfieren un subárbol desde un árbol hacia otro.
11. Explica qué diferencia hay entre `removeSubtree` y `secede`.
12. Explica por qué `secede` no debe destruir los nodos desprendidos.
13. Explica por qué `removeSubtree` sí debe liberar nodos.
14. Explica qué verifica `checkParentLinks()`.
15. En `BinaryTree`, explica cómo se implementan `firstNode`, `lastNode`, `nextNode` y `prevNode`.
16. Explica por qué un iterador basado en `succ()` produce recorrido inorden.
17. Explica qué aporta `asciiArt()` para depuración y sustentación.


#### Bloque 7 - Árbol binario de búsqueda: búsqueda, eliminación y rotaciones

Revisa:

- `Semana5/include/BinarySearchTree.h`
- `Semana5/demos/demo_bst.cpp`
- `Semana5/pruebas_publicas/test_public_week5.cpp`
- `Semana5/pruebas_internas/test_internal_week5.cpp`

Responde:

1. Define formalmente la propiedad BST.
2. Explica por qué el recorrido inorden de un BST debe producir una secuencia no decreciente.
3. Explica la diferencia entre `find`, `findEQ`, `lowerBound` y `upperBound`.
4. Explica por qué `findEQ(x)` puede fallar aunque `lowerBound(x)` no falle.
5. Construye manualmente el BST que se obtiene al insertar: `7, 3, 10, 1, 5, 8, 12, 4, 6`.
6. Escribe el inorden, preorden, postorden y recorrido por niveles de ese árbol.
7. Simula `lowerBound(9)` y `upperBound(8)` paso a paso.
8. Explica qué casos de eliminación existen en un BST: hoja, un hijo, dos hijos.
9. Explica qué papel cumple `splice` durante una eliminación.
10. Después de eliminar una clave, ¿qué invariantes deben seguir siendo ciertos?
11. Explica por qué `remove(3)` en las pruebas debe conservar el inorden ordenado.
12. Explica qué hace `rotateLeft`.
13. Explica qué hace `rotateRight`.
14. Demuestra que una rotación local preserva la propiedad BST.
15. Explica para qué sirve construir un BST balanceado desde un arreglo ordenado.
16. Compara el costo de búsqueda en un BST balanceado y en un BST degenerado.


#### Bloque 8 - Heap binario y representación implícita

Revisa:

- `Semana5/include/BinaryHeap.h`
- `Semana5/demos/demo_heap.cpp`
- `Semana5/pruebas_publicas/test_public_week5.cpp`
- `Semana5/pruebas_internas/test_internal_week5.cpp`

Responde:

1. Explica por qué un heap binario puede almacenarse en un `std::vector` sin punteros.
2. Demuestra las fórmulas:

   ```cpp
   left(i) = 2*i + 1
   right(i) = 2*i + 2
   parent(i) = (i - 1) / 2
   ```

3. Define la propiedad de min-heap.
4. Explica por qué `top()` devuelve el mínimo.
5. Explica paso a paso cómo `bubbleUp(i)` restaura la propiedad de heap después de insertar.
6. Explica paso a paso cómo `trickleDown(i)` restaura la propiedad de heap después de eliminar la raíz.
7. Explica por qué `remove()` debe mover el último elemento a la raíz antes de aplicar `trickleDown(0)`.
8. Explica qué verifica `isHeap()`.
9. Compara construir un heap insertando `n` elementos con construirlo usando `heapify()`.
10. Justifica por qué insertar `n` elementos uno por uno cuesta `O(n log n)` en el peor caso.
11. Justifica por qué `heapify()` puede ejecutarse en `O(n)`.
12. Ejecuta una extracción completa del heap construido con `{7, 3, 10, 1, 5, 8, 2}` y explica por qué la secuencia extraída sale ordenada.
13. Compara el heap con el BST: ¿cuál estructura conviene para consultar mínimo repetidamente y cuál conviene para búsquedas ordenadas?.


#### Bloque 9 - Cierre comparativo y preparación de sustentación

Responde esta pregunta final:

¿Qué cambia cuando pasamos de estudiar listas, pilas y colas a diseñar árboles binarios, heaps y árboles binarios de búsqueda?

La respuesta debe incluir obligatoriamente:

- Una afirmación sobre representación enlazada con nodos y punteros.
- Una afirmación sobre representación implícita en arreglo.
- Una afirmación sobre la diferencia entre propiedad estructural y propiedad de orden.
- Una afirmación sobre recorridos y por qué son una forma de convertir un árbol en una secuencia.
- Una afirmación sobre mantenimiento de alturas y enlaces `parent`.
- Una afirmación sobre BST, búsqueda ordenada y recorrido inorden.
- Una afirmación sobre heap, prioridad y costo de `add`, `remove` y `heapify`.
- Una afirmación sobre qué evidencia usarías para defender correctitud: pruebas, demos, invariantes, trazados y complejidad.

#### Formato sugerido de entrega

```markdown
## Actividad 5 - CC232

### Estudiante

- Nombre:

### Bloque 1 - Núcleo conceptual

[Respuestas]

### Bloque 2 - Navegación, altura, profundidad y tamaño

[Respuestas y dibujos]

### Bloque 3 - Recorridos y trazado guiado

[Tabla y respuestas]

### Bloque 4 - Demos

[Tabla y respuestas]

### Bloque 5 - Pruebas e invariantes

[Respuestas]

### Bloque 6 - Lectura cercana de código

[Respuestas]

### Bloque 7 - BST

[Respuestas, trazados y argumentos]

### Bloque 8 - Heap

[Respuestas, trazados y argumentos]

### Bloque 9 - Cierre comparativo

[Respuesta final]

### Autoevaluación breve

- Qué puedo defender con seguridad:
- Qué todavía confundo:
- Qué evidencia usaría en una sustentación:
- Qué parte del código me parece más importante para revisar otra vez:
```

#### Criterio general de trabajo

Se espera lectura real de los archivos, respuestas breves pero justificadas, tablas con evidencia observable, trazados manuales y conexión explícita entre código, correctitud, costo, representación e invariantes.

No basta con ejecutar el programa: debes poder explicar por qué funciona, qué punteros se actualizan, qué propiedad mantiene cada estructura, qué costo tiene cada operación y qué evidencia usarías para defenderlo oralmente.

---
---

## Actividad 5 - CC232

### Estudiante

- Nombre: Paul Flores Enrique Alejandro

### Bloque 1 - Nucleo conceptual

1. En un arbol binario enlazado cada nodo es un objeto con punteros a su padre y a sus hijos, y la estructura se forma con esos enlaces, asi que los nodos pueden estar en cualquier parte de la memoria. En un arbol guardado implicitamente en un arreglo no hay punteros: los nodos viven en posiciones de un vector y la relacion padre-hijo se calcula con formulas (2i+1, 2i+2, (i-1)/2). El enlazado sirve para arboles de cualquier forma, mientras que el implicito ahorra memoria pero conviene solo para arboles casi completos como el heap.

2. Un BinNode guarda el dato (data), un puntero al padre (parent, que es null si el nodo es la raiz), un puntero al hijo izquierdo (left) y uno al hijo derecho (right, ambos null si no existen), y la altura del nodo (height), que sirve para mantener el arbol balanceado.

3. Porque para hallar el sucesor de un nodo que no tiene hijo derecho hay que subir por los ancestros, y para actualizar las alturas despues de un cambio hay que subir desde el nodo hacia la raiz. Sin el puntero parent solo se podria bajar por los hijos, no ir hacia arriba, asi que esas operaciones no se podrian hacer.

4. BinNode representa un nodo individual con sus enlaces, mientras que BinTree maneja el arbol como un todo: guarda la raiz y el tamaño, y ofrece las operaciones globales como insertar, adjuntar o quitar subarboles y mantener las alturas. Es decir BinNode sabe de si mismo y de sus vecinos, y BinTree coordina el conjunto.

5. BinaryTree agrega la navegacion ordenada estilo iterador: firstNode, lastNode, nextNode y prevNode, construidas sobre succ y pred, de modo que el arbol se puede recorrer en inorden como si fuera una secuencia.

6. La propiedad de orden: para cada nodo, todas las claves de su subarbol izquierdo son menores y todas las del derecho son mayores, y aqui no se aceptan duplicados. Esa propiedad de busqueda es la que convierte un arbol binario cualquiera en un BST.

7. La propiedad de min-heap: cada nodo es menor o igual que sus hijos, de modo que el minimo queda en la raiz. Sobre la representacion implicita esto significa a[i] <= a[2i+1] y a[i] <= a[2i+2].

8. El BST ordena izquierda-nodo-derecha, es decir mantiene un orden total que permite saber quien es menor que quien en cualquier parte del arbol. El heap en cambio solo garantiza la relacion padre-hijo, donde el padre es menor que sus hijos, pero no ordena los hermanos ni las ramas entre si. Por eso el BST sirve para busqueda ordenada y el heap solo para sacar el minimo rapido.

9. Porque inorden visita primero todo el subarbol izquierdo, que tiene las claves menores, luego el nodo, y al final el subarbol derecho, que tiene las mayores; aplicando eso de forma recursiva las claves salen de menor a mayor. Se ve en el demo, donde el inorden del BST da 1 3 4 5 6 7 8 10 12.

10. Porque el heap solo ordena la relacion padre-hijo, no de izquierda a derecha, asi que recorrerlo tal cual no entrega los elementos ordenados. La unica forma de obtenerlos en orden es ir extrayendo el minimo una y otra vez, lo que vacia el heap, o copiarlo antes para no perderlo.

### Bloque 2 - Navegacion, altura, profundidad y tamaño

1. hasLeft() devuelve true si el nodo tiene hijo izquierdo, y hasRight() si tiene hijo derecho. isRoot() es true cuando el nodo no tiene padre, es decir es la raiz. isLeaf() es true cuando no tiene ningun hijo. isLeftChild() es true cuando el nodo es el hijo izquierdo de su padre, e isRightChild() cuando es el hijo derecho. Sirven para preguntar por la posicion del nodo sin tener que escribir las comparaciones de punteros cada vez.

2. Cuando el nodo si tiene hijo derecho, su sucesor inorden es el mas pequeño de ese subarbol derecho. Por eso succ baja una vez al hijo derecho y desde ahi sigue bajando por los hijos izquierdos (leftmost) hasta el nodo mas a la izquierda. En el demo el sucesor de 5 es 6, que es justamente el mas a la izquierda del subarbol derecho de 5.

3. Cuando el nodo no tiene hijo derecho, su sucesor esta mas arriba. succ sube por los ancestros mientras el nodo venga como hijo derecho, y se detiene en el primer ancestro donde el nodo venia como hijo izquierdo; el padre de ese punto es el sucesor. Dicho de otro modo, sube hasta el primer giro hacia la izquierda. Si nunca lo encuentra, el nodo era el ultimo y devuelve null.

4. pred es simetrico. Si el nodo tiene hijo izquierdo, su predecesor es el mas grande del subarbol izquierdo, asi que baja al hijo izquierdo y luego sigue por los hijos derechos (rightmost). Si no tiene hijo izquierdo, sube por los ancestros mientras venga como hijo izquierdo y se detiene en el primer giro hacia la derecha; el padre de ahi es el predecesor. En el demo el predecesor de 5 es 4.

5. Arbol del demo (insercion 7, 3, 10, 1, 5, 8, 12, 4, 6), cuyo inorden es 1 3 4 5 6 7 8 10 12:

```
            7
          /   \
        3       10
       / \     /  \
      1   5   8    12
         / \
        4   6
```

Sucesor y predecesor inorden de tres nodos:
- Nodo 5: sucesor = 6 (el mas a la izquierda de su subarbol derecho), predecesor = 4 (el mas a la derecha de su subarbol izquierdo).
- Nodo 7 (raiz): sucesor = 8 (mas a la izquierda del subarbol derecho 10), predecesor = 6 (mas a la derecha del subarbol izquierdo 3).
- Nodo 1: sucesor = 3 (no tiene hijo derecho, sube y 1 es hijo izquierdo de 3), predecesor = null (1 es el minimo del arbol).

6. depth(u) cuenta cuantas aristas hay desde la raiz hasta u, es decir el nivel del nodo. Se puede implementar subiendo por parent desde u hasta la raiz y contando los pasos, porque cada salto al padre sube un nivel y la raiz tiene profundidad 0.

7. height(u) es la longitud del camino mas largo desde u hacia abajo hasta una hoja. Se implementa bajando recursivamente por los hijos: la altura de un nodo es 1 mas el maximo entre la altura del hijo izquierdo y la del derecho. En el codigo updateHeight hace height = 1 + max(stature(left), stature(right)), donde stature de un puntero null vale -1. Se baja porque la altura depende de que tan profundo llega el subarbol.

8. subtreeSize(u) es la cantidad de nodos que hay en el subarbol que tiene a u como raiz, contando a u mismo. En el codigo BinNode::size lo calcula como 1 mas el tamaño del subarbol izquierdo mas el del derecho.

9. depth(u) es la longitud del camino de la raiz a u, y height(u) es la longitud del camino mas largo de u hasta una hoja de su subarbol. Si unimos esos dos caminos obtenemos un unico camino que va de la raiz a una hoja pasando por u, cuya longitud es depth(u) + height(u). Pero height(T) es, por definicion, la longitud del camino mas largo de la raiz a cualquier hoja. Como el camino raiz-u-hoja es uno de esos caminos raiz-hoja, su longitud no puede superar a la maxima, de modo que depth(u) + height(u) <= height(T).

10. La igualdad se alcanza cuando u esta sobre un camino mas largo del arbol, es decir cuando existe una hoja descendiente de u tal que el camino raiz-u-hoja tiene longitud maxima, igual a height(T). En palabras simples, cuando u pertenece a alguna de las ramas mas altas del arbol.

### Bloque 3 - Recorridos y trazado guiado

| Recorrido | Version revisada | Estructura auxiliar | Secuencia en el arbol de prueba | Argumento de correctitud y costo |
|---|---|---|---|---|
| Preorden recursivo | travPre | pila de llamadas | 7 3 1 5 4 6 10 8 12 | visita raiz, luego izquierdo, luego derecho; cada nodo se visita una vez, O(n) tiempo y O(h) memoria |
| Preorden iterativo | travPreIterative2 | pila explicita | 7 3 1 5 4 6 10 8 12 | apila primero el derecho y luego el izquierdo para sacar el izquierdo antes; O(n) tiempo, O(h) memoria |
| Inorden recursivo | travInRecursive | pila de llamadas | 1 3 4 5 6 7 8 10 12 | visita izquierdo, raiz, derecho; O(n) tiempo, O(h) memoria |
| Inorden iterativo #1 | travInIterative1 | pila explicita | 1 3 4 5 6 7 8 10 12 | baja apilando los izquierdos, visita al desapilar y pasa al derecho; O(n) tiempo, O(h) memoria |
| Inorden iterativo #2 | travInIterative2 | punteros parent (sin pila) | 1 3 4 5 6 7 8 10 12 | usa prev y curr con el puntero al padre para decidir el siguiente; O(n) tiempo, O(1) memoria extra |
| Inorden iterativo #3 | travInIterative3 | succ y parent (sin pila) | 1 3 4 5 6 7 8 10 12 | parte del leftmost y avanza con succ hasta el final; O(n) tiempo, O(1) memoria extra |
| Postorden recursivo | travPost | pila de llamadas | 1 4 6 5 3 8 12 10 7 | visita izquierdo, derecho y al final la raiz; O(n) tiempo, O(h) memoria |
| Postorden iterativo | travPostIterative | dos pilas | 1 4 6 5 3 8 12 10 7 | una pila genera el orden raiz-derecho-izquierdo y la otra lo invierte; O(n) tiempo, O(n) memoria |
| Recorrido por niveles | travLevel | cola | 7 3 10 1 5 8 12 4 6 | procesa nivel por nivel encolando los hijos; O(n) tiempo y O(ancho) memoria |

1. Visitar un nodo en preorden significa atenderlo antes que a sus subarboles: primero la raiz, luego todo el subarbol izquierdo y por ultimo el derecho.

2. Visitar en inorden significa atender el nodo en medio de sus subarboles: primero todo el subarbol izquierdo, luego el nodo, y al final el derecho. En un BST esto da las claves en orden creciente.

3. Visitar en postorden significa atender el nodo despues de sus subarboles: primero el izquierdo, luego el derecho, y al final la raiz.

4. Visitar por niveles significa recorrer los nodos por niveles de profundidad, de arriba hacia abajo, y dentro de cada nivel de izquierda a derecha.

5. Porque cada nodo se visita exactamente una vez y el trabajo por nodo es constante, asi que el total de operaciones es proporcional a n.

6. Porque hacen el mismo recorrido: cada nodo entra y sale una sola vez de la estructura auxiliar, de modo que el numero de operaciones sigue siendo proporcional a n.

7. En un arbol balanceado es O(log n), porque la pila de llamadas llega a lo mas a la altura del arbol, que en un arbol balanceado es del orden de log n.

8. En un arbol degenerado es O(n), porque ese arbol se parece a una lista con altura n, asi que la pila de llamadas puede crecer hasta n niveles.

9. La pila de llamadas la maneja el sistema de forma automatica cuando hay recursion, mientras que la pila explicita la creas y controlas tu dentro del codigo. Conceptualmente hacen lo mismo, pero la explicita te da control y evita chocar con el limite de recursion del sistema en arboles muy profundos.

10. Porque la cola guarda los nodos de un nivel mientras se procesan. En un arbol completo el ultimo nivel tiene cerca de la mitad de los nodos, asi que la cola llega a tener del orden de n elementos a la vez. En cambio en un arbol degenerado cada nivel tiene un solo nodo, asi que la cola casi no crece y se queda en O(1).

### Bloque 4 - Demos

| Archivo | Salida u observable importante | Idea estructural | Argumento de costo, espacio o diseño |
|---|---|---|---|
| demo_binary_tree.cpp | recorridos pre/in/post/niveles, sucesor de 5 = 6, predecesor de 5 = 4, altura 3, profundidad de 5 = 2, parent links OK | arbol binario enlazado con navegacion por punteros | los recorridos son O(n); succ y pred suben o bajan O(h); el puntero parent permite navegar en ambos sentidos |
| demo_bst.cpp | inorden ordenado 1..12, findEQ(5)=5, lowerBound(9)=10, upperBound(8)=10, remove(3), rotateLeft, BST balanceado, isBST si | BST con la propiedad izquierda < nodo < derecha | las busquedas cuestan O(h); una rotacion es O(1) y conserva el orden; balanceado da h del orden de log n |
| demo_heap.cpp | heapify 1 3 2 7 5 8 10, isHeap si, add(0) deja 0 en la raiz, remove() devuelve 0, extraccion ordenada 1 2 3 5 7 8 10 | min-heap en arreglo implicito | add y remove son O(log n); heapify es O(n); extraer todo da O(n log n) y sale ordenado |
| demo_capitulo5_panorama.cpp | heap minimo 1, raiz BST 9, altura 2, ascii del arbol, recorrido STL-like 2 4 7 9 10 12 15 | reune arbol enlazado, BST y heap | resume la semana: el heap da el minimo directo y el BST permite recorrido ordenado |

1. Las lineas de cada recorrido con sus secuencias. En especial el inorden 1 3 4 5 6 7 8 10 12 sale ordenado, y las tres versiones iterativas del inorden coinciden con la recursiva, lo que confirma que todos visitan en el orden esperado.

2. Que la salida muestra Sucesor de 5: 6 y Predecesor de 5: 4, que son justo los vecinos de 5 en el inorden (4 5 6). Ademas la linea Iteracion por sucesor reproduce el inorden completo 1 3 4 5 6 7 8 10 12, lo que defiende que succ respeta ese orden.

3. La representacion ASCII muestra la forma real del arbol, es decir quien es hijo de quien y de que lado, asi se puede verificar visualmente la estructura y depurar. Tambien deja ver la altura y la posicion de cada nodo.

4. La linea BST inorden: 1 3 4 5 6 7 8 10 12, que sale en orden creciente. Ese es el observable que defiende que el inorden de un BST queda ordenado.

5. lowerBound y upperBound se distinguen mejor, porque con valores que no estan exactos se nota la diferencia: lowerBound(9) da 10 y upperBound(8) da 10, donde lowerBound devuelve el primero mayor o igual a x y upperBound el primero estrictamente mayor. findEQ(5) en cambio solo encuentra el valor exacto.

6. Tras heapify la primera posicion es 1, que es el menor, e isHeap da si. Ademas, al hacer add(0) el 0 sube hasta la primera posicion, y remove() devuelve 0. Todo eso muestra que el minimo queda en la raiz.

7. heapify reordena todo el arreglo de golpe y deja 1 3 2 7 5 8 10, mientras que add(0) inserta un solo elemento y lo sube con bubbleUp dejando 0 1 2 3 5 8 10 7. Se ve que add cambia solo lo necesario para acomodar el nuevo elemento, en cambio heapify arma el heap completo a partir del vector.

8. La que junta el heap y el BST: el heap entrega el minimo directo (Heap minimo actual: 1) mientras que el BST permite el recorrido ordenado (recorrido STL-like 2 4 7 9 10 12 15). Esa comparacion resume la semana, porque muestra el arbol enlazado, el BST para busqueda ordenada y el heap para prioridad.

### Bloque 5 - Pruebas e invariantes

1. Valida la insercion con add, el inorden en sus cuatro versiones, las busquedas findEQ, find, lowerBound y upperBound, los extremos con minNode y maxNode, la validacion isBST, la eliminacion con remove, la consulta contains y la consistencia de enlaces con checkParentLinks.

2. El caso expect(!bst.add(5), ...): despues de haber insertado el 5, intentar agregarlo de nuevo hace que add devuelva false, lo que comprueba que el BST no acepta duplicados.

3. Se verifica que las tres versiones iterativas del inorden (Iterative1, Iterative2 e Iterative3) producen exactamente la misma secuencia ordenada que la recursiva, 1 3 4 5 6 7 8 10 12. Es decir que todas implementan correctamente el mismo recorrido.

4. Se espera que findEQ(8) devuelva un nodo no nulo cuyo data sea 8, o sea que ubique la clave exacta 8.

5. lowerBound(9) debe devolver 10, porque es el primer valor mayor o igual a 9 y el 9 no esta. upperBound(8) tambien debe devolver 10, porque busca el primer valor estrictamente mayor que 8, y aunque el 8 si esta se salta y sigue el 10.

6. isBST valida la propiedad de busqueda: que para cada nodo el subarbol izquierdo tiene claves menores y el derecho claves mayores, lo que equivale a que el inorden quede ordenado.

7. Tras remove(3) se valida que el inorden sigue ordenado pero sin el 3 (1 4 5 6 7 8 10 12), que contains(3) ahora da false, y que checkParentLinks sigue siendo valido despues del borrado.

8. checkParentLinks comprueba que cada nodo apunte realmente a su verdadero padre, es decir que despues de borrar, separar o adjuntar subarboles no quedaron enlaces parent mal puestos o colgando.

9. Valida el constructor con heapify mediante isHeap, la extraccion repetida con remove, e isHeapArray sobre un arreglo dado para reconocer un heap valido.

10. Demuestra que las extracciones salen en orden creciente (1 2 3 5 7 8 10), porque cada remove saca el minimo actual. Eso confirma que el heap mantiene el minimo en la raiz y es justamente la idea detras del heapsort.

11. attachAsRC adjunta un subarbol y suma sus nodos (host queda con tamaño 4 y el arbol extra queda vacio); secede desprende un subarbol y lo devuelve como arbol propio sin destruirlo (host baja a 1, el desprendido tiene tamaño 3 y conserva sus parent links); removeSubtree elimina y libera el subarbol (al quitar el nodo restante devuelve 1 y el arbol queda vacio).

12. Las pruebas internas cubren las rotaciones (rotateRight y rotateLeft conservan el orden y la propiedad BST), bubbleUp (add lleva el minimo a la raiz, top da 1), trickleDown (tras remove el nuevo minimo queda arriba e isHeap sigue valido), la profundidad (depth del hijo izquierdo da 1), la altura (height da 2 y root->height da 2), el tamaño de subarbol (subtreeSize da 6), y el sucesor y predecesor (iterateBySuccessor da 3 5 7 10 15 20 e iterateByPredecessor el inverso), ademas de firstNode y lastNode.

13. Demuestra que en los casos concretos probados las operaciones dan el resultado esperado: el BST queda ordenado, las busquedas devuelven lo correcto, el heap extrae ordenado, los recorridos coinciden y los enlaces se mantienen. Es correctitud observable en esos ejemplos.

14. No demuestra que la estructura sea correcta para todos los casos posibles, ni explica por que funciona, ni garantiza la complejidad. Podria haber casos no probados que fallen o ineficiencias que las pruebas no alcanzan a detectar.

15. Porque los resultados observables solo muestran que en esos ejemplos sale bien, mientras que la correctitud general se apoya en los invariantes que se mantienen en cada operacion, como la propiedad BST, la propiedad de heap y los enlaces parent, y la eficiencia se apoya en la complejidad, como O(h), O(log n) y O(n). Sin mencionar eso, la defensa se queda en que funciono en unos casos, sin explicar el porque ni el costo.

### Bloque 6 - Lectura cercana de codigo

1. El invariante principal es que los punteros sean coherentes: si un nodo u tiene a v como hijo izquierdo (u->left = v) o derecho (u->right = v), entonces v->parent debe ser u. La raiz tiene parent null, y cada nodo que no es la raiz es hijo izquierdo o derecho de exactamente un padre.

2. Porque si sobreescribieran un hijo que ya existe sin liberarlo, ese subarbol quedaria perdido en memoria y se romperian los enlaces. Por eso insertAsLC e insertAsRC lanzan logic_error cuando el hijo correspondiente no es null.

3. De forma recursiva: size cuenta 1 por el propio nodo, mas el size del subarbol izquierdo, mas el del derecho, tomando 0 cuando un hijo es null. Asi suma todos los nodos del subarbol.

4. leftmost baja siguiendo los punteros left mientras existan, hasta el nodo mas a la izquierda, que en un BST es el menor. rightmost hace lo simetrico bajando por right hasta el nodo mas a la derecha, el mayor.

5. Si el nodo tiene hijo derecho, su sucesor es el leftmost de ese subarbol derecho, asi que baja una vez al derecho y luego todo a la izquierda. Si no tiene hijo derecho, sube por los ancestros mientras el nodo venga como hijo derecho, y devuelve el padre del primer nodo que sea hijo izquierdo, que es el primer giro hacia la izquierda. Si llega arriba sin encontrarlo, devuelve null.

6. pred es simetrico: si el nodo tiene hijo izquierdo, su predecesor es el rightmost de ese subarbol izquierdo. Si no, sube mientras venga como hijo izquierdo y devuelve el padre del primer nodo que sea hijo derecho. Si no existe, devuelve null.

7. root_ apunta a la raiz del arbol, o null si esta vacio, y es el punto de entrada para todas las operaciones. size_ guarda la cantidad de nodos, asi no hay que recorrer el arbol cada vez que se quiere saber el tamaño.

8. updateHeight recalcula la altura de un solo nodo como 1 mas el maximo entre la altura de su hijo izquierdo y la del derecho, usando stature que devuelve -1 para un puntero null.

9. updateHeightAbove llama a updateHeight en el nodo y va subiendo por parent hasta la raiz, actualizando la altura de cada ancestro. Sube porque cuando cambia un subarbol las unicas alturas que pueden quedar desactualizadas son las del nodo y las de sus ancestros, no las de abajo.

10. Toman la raiz del subarbol que viene en otro BinTree y la enganchan como hijo izquierdo o derecho del padre indicado, ajustan el puntero parent de esa raiz, suman el tamaño del subarbol al arbol receptor, actualizan las alturas hacia arriba, y dejan el arbol de origen vacio (root_ en null y size_ en 0) para que no se compartan nodos entre los dos arboles.

11. removeSubtree desconecta el subarbol y lo destruye, liberando los nodos con delete, y devuelve cuantos elimino. secede tambien desconecta el subarbol, pero no lo destruye: lo devuelve como un BinTree nuevo e independiente que conserva sus nodos.

12. Porque la idea de secede es trasladar el subarbol a otro arbol o usarlo por separado; si lo destruyera, el arbol devuelto quedaria con punteros a memoria ya liberada. Por eso debe conservar los nodos vivos.

13. Porque la idea de removeSubtree es eliminar definitivamente ese subarbol, y si no liberara los nodos con delete habria fuga de memoria, ya que esos nodos quedarian sin ninguna referencia que los apunte.

14. Verifica que cada nodo tenga como parent exactamente al nodo del que es hijo, recorriendo el arbol y comprobando en cada paso que node->parent coincide con el padre real. Sirve para detectar enlaces parent inconsistentes despues de modificar la estructura.

15. firstNode devuelve el leftmost de la raiz, que es el menor inorden, y lastNode el rightmost, el mayor. nextNode devuelve el succ del nodo dado y prevNode el pred. Es decir, se apoyan directamente en las operaciones de BinNode.

16. Porque empezar en firstNode, que es el menor, e ir aplicando succ repetidamente entrega los nodos en orden inorden, que en un BST es el orden creciente. succ devuelve justamente el siguiente nodo en ese orden.

17. asciiArt dibuja el arbol en texto mostrando su forma real, con la jerarquia y los lados izquierdo y derecho, asi se puede ver de un vistazo si la estructura quedo como se esperaba y explicarla en una sustentacion sin tener que imaginarla.

### Bloque 7 - BST

1. La propiedad BST dice que para todo nodo u con clave k, todas las claves de su subarbol izquierdo son menores que k y todas las de su subarbol derecho son mayores que k, y esto se cumple de forma recursiva en cada nodo. Aqui no se aceptan duplicados. En el codigo isBST lo comprueba pasando limites low y high por cada rama.

2. Porque el inorden visita izquierda, nodo y derecha. Por la propiedad BST el subarbol izquierdo tiene claves menores y el derecho claves mayores, asi que cada nodo se emite despues de todas las menores y antes de todas las mayores, lo que da una secuencia ordenada. Como aqui no hay duplicados, es estrictamente creciente.

3. findEQ devuelve el nodo con la clave exacta, o null si no esta. lowerBound devuelve el primer nodo con clave mayor o igual a x. upperBound devuelve el primer nodo con clave estrictamente mayor que x. find en este codigo es un alias de lowerBound.

4. Porque findEQ exige la clave exacta y devuelve null si x no esta en el arbol, mientras que lowerBound no exige exactitud: si x no esta, devuelve el siguiente mayor. Por ejemplo findEQ(9) da null porque no hay 9, pero lowerBound(9) da 10.

5. BST que se obtiene al insertar 7, 3, 10, 1, 5, 8, 12, 4, 6:

```
            7
          /   \
        3       10
       / \     /  \
      1   5   8    12
         / \
        4   6
```

El 7 es la raiz, 3 va a la izquierda y 10 a la derecha; 1 y 5 son hijos de 3; 8 y 12 son hijos de 10; 4 y 6 son hijos de 5.

6. Para ese arbol:
- Inorden: 1 3 4 5 6 7 8 10 12
- Preorden: 7 3 1 5 4 6 10 8 12
- Postorden: 1 4 6 5 3 8 12 10 7
- Por niveles: 7 3 10 1 5 8 12 4 6

7. lowerBound(9): empieza en 7, como 9 > 7 va a la derecha (10); en 10, como 9 < 10 guarda candidato 10 y va a la izquierda (8); en 8, como 9 > 8 va a la derecha, que no existe, asi que termina y devuelve el candidato 10.
upperBound(8): empieza en 7, como 8 > 7 va a la derecha (10); en 10, como 8 < 10 guarda candidato 10 y va a la izquierda (8); en 8, como no es 8 < 8 va a la derecha, que no existe, asi que termina y devuelve el candidato 10.

8. Hay tres casos. Si el nodo es hoja, se desconecta y se libera. Si tiene un solo hijo, se reemplaza por ese hijo. Si tiene dos hijos, se copia el dato del sucesor inorden en el nodo y luego se elimina ese sucesor, que tiene a lo mas un hijo.

9. splice quita un nodo que tiene a lo mas un hijo: conecta ese unico hijo, o null si no tiene, directamente con el padre del nodo, ajusta los punteros parent, descuenta el tamaño y actualiza las alturas hacia arriba. Es la operacion base que usan los tres casos de eliminacion.

10. Deben seguir siendo ciertos la propiedad BST (el inorden ordenado), los enlaces parent consistentes que verifica checkParentLinks, las alturas actualizadas, y el tamaño size descontado correctamente.

11. Porque el 3 tiene dos hijos, asi que se reemplaza por su sucesor inorden, que es el 4, y se elimina el nodo 4 original, que es una hoja. El resultado conserva la propiedad BST y el inorden queda 1 4 5 6 7 8 10 12, que sigue ordenado.

12. rotateLeft rota alrededor de u hacia la izquierda: el hijo derecho w sube a ocupar el lugar de u, u baja a ser hijo izquierdo de w, y el subarbol izquierdo de w pasa a ser el hijo derecho de u. Ajusta los punteros parent y las alturas. Sirve para rebalancear sin cambiar el orden.

13. rotateRight es simetrico: el hijo izquierdo w sube, u baja a ser hijo derecho de w, y el subarbol derecho de w pasa a ser el hijo izquierdo de u.

14. En rotateLeft, antes de rotar se cumple left(u) < u < left(w) < w < right(w), donde w es el hijo derecho de u. Despues de la rotacion w queda arriba con u de hijo izquierdo: left(u) sigue a la izquierda de u, el subarbol left(w) que estaba entre u y w pasa a ser el hijo derecho de u (sigue siendo mayor que u y menor que w), y right(w) sigue a la derecha de w. Como ninguna relacion de orden entre los grupos cambia, el inorden es identico antes y despues, de modo que la propiedad BST se conserva.

15. Sirve para obtener un arbol de altura minima, del orden de log n, a partir de datos que ya estan ordenados, eligiendo el elemento del medio como raiz de forma recursiva. Asi las busquedas quedan en O(log n), en lugar de degenerar en una cadena como pasaria si se insertaran las claves ordenadas una por una.

16. En un BST balanceado la altura es del orden de log n, asi que buscar cuesta O(log n). En un BST degenerado, por ejemplo al insertar claves ya ordenadas, el arbol se vuelve una cadena de altura n y buscar cuesta O(n), como en una lista. Por eso mantener el balance es importante.

### Bloque 8 - Heap

1. Porque un heap binario es un arbol binario completo, es decir se llena por niveles de izquierda a derecha sin huecos. En un arbol completo la posicion de cada nodo determina la de sus hijos y su padre mediante formulas, asi que no hacen falta punteros: el indice en el arreglo ya codifica la estructura.

2. Si numeramos los nodos por niveles desde 0, el nivel d empieza en el indice 2^d - 1. Un nodo i que es el j-esimo de su nivel cumple i = 2^d - 1 + j, y sus dos hijos son el 2j-esimo y el (2j+1)-esimo del nivel d+1, que empieza en 2^(d+1) - 1. Haciendo la cuenta, el hijo izquierdo es 2^(d+1) - 1 + 2j = 2(2^d - 1 + j) + 1 = 2i + 1, y el derecho es 2i + 2. El padre es la operacion inversa: de 2i+1 o 2i+2 se recupera i con (hijo - 1) / 2 usando division entera.

3. La propiedad de min-heap dice que cada nodo es menor o igual que sus hijos, es decir a[i] <= a[2i+1] y a[i] <= a[2i+2] cuando esos hijos existen. Como consecuencia, la raiz en el indice 0 es el minimo.

4. Porque por la propiedad de min-heap cada padre es menor o igual que sus hijos, y aplicando eso en cadena desde la raiz, la raiz resulta menor o igual que todos los demas. Por eso el minimo siempre esta en el indice 0, que es lo que devuelve top.

5. Despues de insertar el nuevo elemento al final del arreglo, este puede ser menor que su padre. bubbleUp compara el elemento con su padre en (i-1)/2; si es menor, los intercambia y sube i al lugar del padre, y repite mientras siga siendo menor que su nuevo padre o hasta llegar a la raiz. Asi restaura la propiedad subiendo el elemento a su lugar.

6. Despues de poner el ultimo elemento en la raiz, este puede ser mayor que sus hijos. trickleDown mira los dos hijos, elige el menor, y si ese hijo es menor que el nodo los intercambia y baja al lugar del hijo; repite mientras el nodo sea mayor que alguno de sus hijos o hasta llegar a una hoja. Asi restaura la propiedad bajando el elemento.

7. Porque al sacar el minimo, que es la raiz, queda un hueco en la cima. Para no dejar huecos y conservar la forma de arbol completo, se mueve el ultimo elemento del arreglo a la raiz y se reduce el tamaño. Ese elemento probablemente viola la propiedad, asi que trickleDown(0) lo baja a su lugar. Mover el ultimo es lo que mantiene el arbol completo.

8. isHeap verifica que el arreglo cumpla la propiedad de heap, es decir que ningun hijo sea menor que su padre, recorriendo cada nodo y comparandolo con sus hijos. Si encuentra un hijo que rompe la relacion, devuelve false.

9. Insertar n elementos uno por uno hace n llamadas a bubbleUp, cada una O(log n), lo que da O(n log n). heapify parte del vector completo y aplica trickleDown desde la mitad hacia la raiz, lo que cuesta O(n). Por eso heapify es mas eficiente cuando se quiere construir el heap de golpe.

10. Porque cada insercion hace bubbleUp, que en el peor caso sube desde una hoja hasta la raiz recorriendo la altura del arbol, que es del orden de log n. Como se hacen n inserciones, el total es n por log n, es decir O(n log n).

11. Porque heapify aplica trickleDown solo a los nodos internos y de abajo hacia arriba, y el costo de cada trickleDown depende de la altura de ese nodo, no de log n para todos. La mayoria de los nodos estan cerca de las hojas y casi no bajan; al sumar el trabajo por niveles la serie da O(n) en lugar de O(n log n).

12. Construyendo el heap con {7, 3, 10, 1, 5, 8, 2} y extrayendo repetidamente el minimo se obtiene 1, 2, 3, 5, 7, 8, 10. Sale ordenada porque cada remove saca el minimo actual y reordena el resto con trickleDown, asi que los elementos van saliendo de menor a mayor. Esto coincide con la prueba publica, donde la extraccion da 1 2 3 5 7 8 10.

13. El heap conviene para consultar y extraer el minimo repetidamente, porque top es O(1) y remove es O(log n), pero no permite busqueda ordenada. El BST conviene para busquedas ordenadas como find, lowerBound, upperBound y el recorrido inorden, porque mantiene un orden total. En resumen, el heap sirve para prioridad y el BST para orden.

### Bloque 9 - Cierre comparativo

Cuando pasamos de listas, pilas y colas a arboles binarios, heaps y BST, lo que cambia es que dejamos de trabajar con estructuras lineales, donde cada elemento tiene a lo mas un siguiente, y empezamos a trabajar con estructuras jerarquicas, donde un nodo puede tener dos hijos y los datos se organizan por niveles y ramas.

En la representacion enlazada con nodos y punteros, cada nodo es un objeto que guarda su dato y punteros a su padre y a sus hijos; la forma del arbol vive en esos enlaces y puede ser cualquiera, lo que da flexibilidad para insertar, borrar, adjuntar o separar subarboles moviendo punteros.

En la representacion implicita en arreglo, como la del heap, no hay punteros: los nodos se guardan en posiciones de un vector y la relacion padre-hijo se calcula con formulas (2i+1, 2i+2, (i-1)/2). Eso ahorra memoria y es muy rapido, pero solo funciona bien para arboles casi completos.

Una diferencia clave es entre propiedad estructural y propiedad de orden. La propiedad estructural habla de la forma, como que el heap sea un arbol completo, mientras que la propiedad de orden habla de los valores, como que en un BST la izquierda sea menor y la derecha mayor, o que en un heap el padre sea menor que sus hijos. Una estructura puede tener buena forma y aun asi necesitar que se respete su propiedad de orden.

Los recorridos son la forma de convertir un arbol, que es jerarquico, en una secuencia lineal. Segun el orden en que se visiten los nodos (preorden, inorden, postorden o por niveles) se obtiene una lista distinta, y eso permite imprimir, comparar o procesar el arbol como si fuera una secuencia.

El mantenimiento de alturas y de los enlaces parent es lo que sostiene que las operaciones sigan siendo correctas: cada vez que se inserta, se borra o se rota, hay que actualizar las alturas hacia arriba con updateHeightAbove y dejar los punteros parent consistentes, porque de ellos dependen succ, pred, depth y las propias rotaciones.

El BST sirve para busqueda ordenada: gracias a la propiedad de orden, find, lowerBound y upperBound bajan por una sola rama en O(h), y su recorrido inorden entrega las claves ordenadas. El heap, en cambio, sirve para prioridad: mantiene el minimo en la raiz, con add y remove en O(log n) y construccion con heapify en O(n), pero no permite recorrer en orden sin vaciarlo.

Para defender la correctitud usaria varias evidencias juntas: las pruebas publicas e internas que muestran resultados esperados, las demos que hacen observable el comportamiento (inorden ordenado, sucesor y predecesor, extraccion ordenada del heap), los invariantes que se mantienen en cada operacion (propiedad BST, propiedad de heap, enlaces parent), los trazados manuales de inserciones, busquedas y rotaciones, y el analisis de complejidad de cada operacion.

### Autoevaluacion breve

- Que puedo defender con seguridad: la diferencia entre representacion enlazada e implicita, por que el inorden de un BST sale ordenado, como funcionan succ y pred, y por que el heap mantiene el minimo en la raiz con add y remove en O(log n).

- Que todavia confundo: a veces me cuesta seguir al detalle el caso de eliminacion con dos hijos y el papel exacto de splice, y tambien me cuesta justificar con cuidado por que heapify es O(n) y no O(n log n).

- Que evidencia usaria en una sustentacion: las salidas reales de los demos (inorden 1 3 4 5 6 7 8 10 12, sucesor de 5 igual a 6, extraccion del heap 1 2 3 5 7 8 10), los trazados de lowerBound y upperBound, y la validacion con isBST y checkParentLinks.

- Que parte del codigo me parece mas importante para revisar otra vez: la eliminacion en el BST (remove y splice) y las rotaciones, porque son las operaciones que mas tocan los punteros y donde es mas facil romper la propiedad o los enlaces parent.
