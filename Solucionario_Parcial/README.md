# CC232 — Solucionario del Parcial Enrique Alejandro Paaul Flores 20222166G
Versión B

---

## Pregunta 1

### ADT CursorBuffer

```cpp
class CursorBuffer {
public:
    void insert(char c);   // inserta en la posición del cursor
    char erase();          // elimina el carácter bajo el cursor
    void moveLeft();
    void moveRight();
    char current() const;
    int size() const;
};
```

- A: arreglo dinámico con índice de cursor.
- B: lista doblemente enlazada con nodo centinela y puntero al nodo del cursor.

---

### a) Qué especifica el ADT y qué queda abierto

El ADT especifica:
- Las operaciones disponibles y su semántica observable: `insert` agrega un carácter en la posición del cursor; `erase` elimina el carácter bajo el cursor; `moveLeft`/`moveRight` desplazan el cursor; `current` retorna el carácter bajo el cursor; `size` retorna el número de caracteres almacenados.
- Las signaturas: tipo de entrada, tipo de retorno y el efecto visible desde afuera.
- El contrato que todo cliente puede asumir, independientemente de cómo esté implementado internamente.

Queda abierto a la implementación:
- La estructura de datos concreta (arreglo, lista enlazada, árbol, etc.).
- La gestión de memoria (cuándo expandir, cómo shrink, cómo liberar).
- Los invariantes de representación internos.
- La complejidad de cada operación (el ADT no la garantiza; depende de la implementación elegida).
- El comportamiento exacto en casos borde no especificados (e.g. `erase` con buffer vacío, posición del cursor tras `insert`).

---

### b) Comparación de costos

`insert`
- A: O(n). Insertar en posición `cursor` obliga a desplazar hacia la derecha todos los elementos desde `cursor` hasta `size-1`. En el peor caso (insertar al inicio) se mueven n elementos. El amortizado O(1) solo aplica a `pushBack`, no a posición arbitraria.
- B: O(1). Se crea un nodo y se redirigen 4 punteros (`u->prev`, `u->next`, `w->prev->next`, `w->prev`). Ningún otro nodo se toca.

`erase`
- A: O(n). Eliminar el carácter bajo el cursor deja un hueco; hay que desplazar a la izquierda los elementos `cursor+1, …, size-1`.
- B: O(1). Se redirigen 2 punteros (`w->prev->next = w->next`, `w->next->prev = w->prev`) y se libera el nodo.

`moveLeft` / `moveRight`
- A: O(1). Solo se incrementa o decrementa el entero `cursor`.
- B: O(1). `cursor = cursor->prev` o `cursor = cursor->next`.

`current`
- A: O(1). Acceso directo por índice `_elem[cursor]`.
- B: O(1). `cursor->x`.

---

### c) Dos invariantes de representación por alternativa

Representación A:
1. `0 <= cursor && cursor <= _size`: el índice cursor es siempre válido o apunta a la posición "más allá del último elemento". Nunca es negativo ni supera el tamaño.
2. `0 <= _size && _size <= _capacity`: el número de elementos no supera la capacidad reservada en `_elem`.

Representación B:
1. Para todo nodo `u` en la lista: `u->prev->next == u && u->next->prev == u`. Los enlaces son bidireccionales consistentes; en particular `dummy.next->prev == &dummy` y `dummy.prev->next == &dummy`.
2. El puntero `cursor` siempre apunta a un nodo válido de la lista o al centinela `dummy`. Nunca es `nullptr`. Si `cursor == &dummy`, el buffer está vacío o el cursor está posicionado al final.

---

### d) Elección de representación para ediciones locales

Se elige B (lista doblemente enlazada).

El patrón descrito implica muchas llamadas a `insert` y `erase` cerca del cursor, con pocas consultas por índice. En B ambas operaciones son O(1): crear o eliminar un nodo y redirigir punteros, sin mover ningún dato. En A cada `insert` o `erase` en posición arbitraria requiere desplazar hasta n elementos → O(n) por operación.

`moveLeft`/`moveRight` son O(1) en ambas representaciones, así que moverse localmente no tiene costo adicional en ninguna. La única desventaja de B —sin acceso O(1) por índice— es irrelevante porque el patrón descrito no incluye consultas por índice.


---

### e) Caso borde crítico por implementación

Representación A — `moveLeft()` con cursor en posición 0:
Si `cursor == 0` y se llama a `moveLeft()` sin verificar el límite, el índice queda en `-1`. La siguiente llamada a `current()` o `erase()` accede a `_elem[-1]` → comportamiento indefinido. Debe verificarse explícitamente: `if (cursor > 0) --cursor;`.

Representación B — `erase()` con buffer vacío (`cursor == &dummy`):
Si el buffer está vacío, el cursor apunta al centinela `dummy`. Una llamada a `erase()` sin verificar `cursor != &dummy` intentaría eliminar el centinela, corrompiendo `dummy->prev->next` y `dummy->next->prev` y dejando la lista sin un centinela válido. Debe verificarse: `assert(cursor != &dummy)`.

---

## Pregunta 2

### Algoritmo de Euclides

```cpp
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
```

---

### a) Trace de gcd(252, 105)

Iteración 1:
-> b = 105 ≠ 0, se entra al ciclo
-> r = 252 % 105 = 42
-> a = 105
-> b = 42

Iteración 2:
-> b = 42 ≠ 0, se entra al ciclo
-> r = 105 % 42 = 21
-> a = 42
-> b = 21

Iteración 3:
-> b = 21 ≠ 0, se entra al ciclo
-> r = 42 % 21 = 0
-> a = 21
-> b = 0

Fin del ciclo: b = 0, se sale del while
-> retorna a = 21

Verificación: 252 = 12 × 21, 105 = 5 × 21 ✓

---

### b) Correctitud

Se demuestra que `gcd(a, b)` es un invariante del ciclo: su valor no cambia entre iteraciones.

Propiedad clave: `gcd(a, b) = gcd(b, a mod b)` para todo `b ≠ 0`.

Sea `d = gcd(a, b)` al comienzo de una iteración. Tras ejecutar `r = a % b`, `a = b`, `b = r`, los nuevos valores son `a' = b` y `b' = a mod b`. Por la propiedad anterior:

```
gcd(a', b') = gcd(b, a mod b) = gcd(a, b) = d
```

El valor buscado se conserva en cada paso.

Condición de salida: cuando `b = 0`, el ciclo termina y se retorna `a`. Por definición `gcd(a, 0) = a` (todo entero divide a 0, así que el mayor divisor común es `a` mismo). Como el invariante garantiza que `gcd(a, b)` siempre es igual al `gcd` original, retornar `a` cuando `b = 0` es correcto.


---

### c) Terminación

La función de cota es el valor de `b`. En cada iteración `b` se reemplaza por `r = a % b`. La operación módulo satisface `0 ≤ r < b` cuando `b > 0`, por lo que `b` estrictamente decrece en cada vuelta. Como `b` es un entero no negativo que decrece estrictamente, debe alcanzar 0 en un número finito de pasos, momento en que el ciclo termina.

---

### d) Precondiciones para evitar ambigüedades

Precondición 1: `a ≥ 0 && b ≥ 0`

En C++ (desde C++11), el operador `%` con operandos negativos produce un resultado con el signo del dividendo; por ejemplo `(-7) % 3 = -1`. Esto viola `0 ≤ r < b` e impide garantizar tanto terminación como correctitud. Restringir a no negativos elimina esta ambigüedad.

Precondición 2: `a > 0 || b > 0`

`gcd(0, 0)` es matemáticamente indefinido: todo entero distinto de cero divide a 0, así que no existe un divisor común máximo finito. La función retornaría 0 sin iterar, lo cual es silenciosamente incorrecto en cualquier contexto matemático. Exigir que al menos uno sea positivo garantiza que el resultado tiene sentido.

---

### e) Comparación con búsqueda exhaustiva de divisores

Algoritmo alternativo (fuerza bruta):
```
d = min(a, b)
mientras d > 0:
    si d divide a y d divide b: retornar d
    d = d - 1
```

La fuerza bruta tiene costo O(min(a, b)): en el peor caso prueba todos los enteros desde min(a, b) hasta 1, lo que para entradas grandes implica un número de iteraciones proporcional al valor de las entradas.

Euclides tiene costo O(log min(a, b)). Por el teorema de Lamé, el número de iteraciones crece como el logaritmo de min(a, b), lo que significa que incluso para valores muy grandes el algoritmo termina en muy pocos pasos.

Por qué pasar pruebas pequeñas no demuestra eficiencia:

Las pruebas pequeñas verifican correctitud, no escalabilidad. Para entradas pequeñas ambos algoritmos terminan en pocos pasos y la diferencia es imperceptible. La divergencia aparece solo cuando las entradas crecen. Un conjunto de pruebas sobre entradas acotadas explora únicamente una región constante del espacio de entradas; la complejidad asintótica describe el comportamiento cuando el tamaño crece sin límite. Ninguna cantidad de tests pequeños puede refutar una cota O(n) ni confirmar una cota O(log n); para eso se requiere análisis formal.

---

## Pregunta 3

### DengVector

El `DengVector` mantiene `_elem`, `_size` y `_capacity`. En `insert(i, x)`:
- Si hay capacidad (`_size < _capacity`): desplaza los elementos en posiciones `i, i+1, …, _size-1` una posición a la derecha, escribe `x` en posición `i` y aumenta `_size`.
- Si no hay capacidad (`_size == _capacity`): primero llama a `expand()`, que duplica `_capacity` y copia todos los elementos al nuevo arreglo, y luego realiza el desplazamiento e inserción.


---

### a) Costos sin redimensionamiento — `_size = 5`, `_capacity = 6`

Como `_size = 5 < _capacity = 6`, hay un espacio libre. `expand()` no se activa en ninguna de las inserciones válidas. Cada caso se analiza de forma independiente partiendo del estado inicial.

`insert(0, x)`:
-> `expand()` no actúa (5 < 6)
-> desplaza `_elem[4]` → posición 5, `_elem[3]` → 4, `_elem[2]` → 3, `_elem[1]` → 2, `_elem[0]` → 1 (5 desplazamientos)
-> escribe `x` en posición 0 (1 escritura)
-> costo total: 5 desplazamientos + 1 escritura

`insert(3, x)`:
-> `expand()` no actúa (5 < 6)
-> desplaza `_elem[4]` → posición 5, `_elem[3]` → 4 (2 desplazamientos)
-> escribe `x` en posición 3 (1 escritura)
-> costo total: 2 desplazamientos + 1 escritura

`insert(7, x)`:
-> `assert(0 <= 7 && 7 <= _size)` falla porque `7 > _size = 5`
-> operación inválida; no se ejecuta. Es un caso borde que el código detecta con el assert.

---

### b) Costos con redimensionamiento — `_size = 6`, `_capacity = 6`

Con `_size = _capacity = 6`, la llamada a `expand()` se activa antes de cualquier inserción. `expand()` duplica la capacidad de 6 a 12 y copia los 6 elementos existentes al nuevo arreglo.

`insert(0, x)`:
-> `expand()`: copia los 6 elementos al nuevo arreglo (6 copias), `_capacity` pasa a 12
-> desplaza los 6 elementos una posición a la derecha (6 desplazamientos)
-> escribe `x` en posición 0 (1 escritura)
-> costo total: 6 copias + 6 desplazamientos + 1 escritura

`insert(3, x)`:
-> `expand()`: copia los 6 elementos (6 copias), `_capacity` pasa a 12
-> desplaza `_elem[5]` → 6, `_elem[4]` → 5, `_elem[3]` → 4 (3 desplazamientos)
-> escribe `x` en posición 3 (1 escritura)
-> costo total: 6 copias + 3 desplazamientos + 1 escritura

`insert(7, x)`:
-> `assert(0 <= 7 && 7 <= _size)` falla porque `7 > _size = 6`
-> operación inválida; igual que en el caso anterior, es un caso borde por acceso fuera de rango.


---

### c) Por qué `pushBack` es amortizado O(1) pero `insert(0, x)`

`pushBack` (inserción al final):
La mayoría de las llamadas solo escriben un elemento en `_elem[_size]` → costo O(1). `expand()` se activa únicamente cuando `_size == _capacity`, y tras duplicar, se necesitan otros n `pushBacks` para llenar el arreglo de nuevo. Si se hacen n `pushBacks` en total, el costo acumulado de todos los `expand()` es `n + n/2 + n/4 + … ≤ 2n` → O(n) en total → amortizado O(1) por operación.

`insert(0, x)` (inserción al inicio):
Independientemente de si hay o no expansión, `insert(0, x)` siempre desplaza los `_size` elementos actuales una posición a la derecha → costo Ω(n) en cada llamada, sin excepción. Este costo no puede repartirse entre operaciones anteriores porque no depende del historial de inserciones, sino del tamaño actual. Si se hacen n llamadas a `insert(0, x)`, el costo total es Ω(n²) → amortizado Ω(n) por operación.

La diferencia clave es que `pushBack` concentra el costo caro (la copia) en eventos poco frecuentes, mientras que `insert(0, x)` paga O(n) en cada llamada sin importar nada.

---

### d) Invariante que involucra `_size`, `_capacity` y posiciones válidas de `_elem`

`0 ≤ _size ≤ _capacity`, `_elem` apunta a un arreglo de al menos `_capacity` posiciones reservadas, y los únicos elementos inicializados y accesibles al cliente son `_elem[0], _elem[1], …, _elem[_size - 1]`. Las posiciones `_elem[_size], …, _elem[_capacity - 1]` existen en memoria pero no forman parte del contenido lógico del vector.


---

### e) Política de expand/shrink y su efecto

Política de la implementación de clase:
- `expand()`: cuando `_size == _capacity`, duplica la capacidad (`_capacity <<= 1`).
- `shrink()`: cuando `_size * 4 <= _capacity` (vector menos del 25% lleno), reduce la capacidad a la mitad, con piso en `DEFAULT_CAPACITY`.

Efecto sobre memoria desprendida (overhead):
Con duplicación, justo después de un `expand()` el arreglo queda al 50% de ocupación en el peor caso, desperdiciando la mitad de la memoria asignada. Con `shrink()` al 25% de llenado, el factor de desperdicio en régimen estable se mantiene entre 25% y 50%.

Una política más agresiva de `expand()` (crecer en un factor de 1.5 en vez de 2) reduce el desperdicio máximo a costa de que los `expand()` sean más frecuentes; el costo amortizado de `pushBack` sigue siendo O(1) mientras el factor sea mayor que 1.

Propiedad crítica del `shrink()`:
El umbral de `shrink()` debe ser estrictamente menor que el umbral de `expand()` para evitar oscilación (thrashing). Si se expandiera al 100% lleno y se redujera al 50% lleno, una secuencia alternada de `insert`/`remove` en el límite dispararía un `expand()` y un `shrink()` en cada operación → costo O(n) por operación. Usando `shrink()` al 25% se crea una zona de amortiguación: el vector debe perder el 75% de sus elementos antes de reducirse, lo que impide la oscilación y mantiene el costo amortizado en O(1) para `pushBack` y `popBack`.


---

## Pregunta 4

### ArrayQueue circular

La `ArrayQueue` usa un arreglo de longitud 10, índice `j` del primer elemento y tamaño `n`. El elemento lógico `k` está en `a[(j + k) mod 10]`. Estado inicial: `j = 7`, `n = 5`, contenido lógico `[4, 8, 15, 16, 23]`.


---

### a) Estado físico inicial

Calculando cada posición física con `a[(j + k) mod 10]`:

-> k=0: a[(7+0) mod 10] = a[7] = 4
-> k=1: a[(7+1) mod 10] = a[8] = 8
-> k=2: a[(7+2) mod 10] = a[9] = 15
-> k=3: a[(7+3) mod 10] = a[0] = 16
-> k=4: a[(7+4) mod 10] = a[1] = 23

Estado físico del arreglo (índices 0 al 9):

```
índice: [ 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  ]
valor:  [ 16 | 23 | _  | _  | _  | _  | _  | 4  | 8  | 15 ]
```

Los guiones representan posiciones fuera del rango lógico actual.

---

### b) Secuencia de operaciones

Estado inicial: j=7, n=5, contenido lógico=[4, 8, 15, 16, 23]
Posiciones físicas ocupadas: 7(4), 8(8), 9(15), 0(16), 1(23)


add(42):
-> nuevo elemento en a[(j+n) mod 10] = a[(7+5) mod 10] = a[2] = 42
-> n = 6
-> j=7, n=6, contenido=[4, 8, 15, 16, 23, 42]
-> posiciones físicas: 7(4), 8(8), 9(15), 0(16), 1(23), 2(42)

remove():
-> retorna a[j] = a[7] = 4
-> j = (7+1) mod 10 = 8
-> n = 5
-> j=8, n=5, contenido=[8, 15, 16, 23, 42]
-> posiciones físicas: 8(8), 9(15), 0(16), 1(23), 2(42)

add(7):
-> nuevo elemento en a[(8+5) mod 10] = a[3] = 7
-> n = 6
-> j=8, n=6, contenido=[8, 15, 16, 23, 42, 7]
-> posiciones físicas: 8(8), 9(15), 0(16), 1(23), 2(42), 3(7)

add(9):
-> nuevo elemento en a[(8+6) mod 10] = a[4] = 9
-> n = 7
-> j=8, n=7, contenido=[8, 15, 16, 23, 42, 7, 9]
-> posiciones físicas: 8(8), 9(15), 0(16), 1(23), 2(42), 3(7), 4(9)

remove():
-> retorna a[j] = a[8] = 8
-> j = (8+1) mod 10 = 9
-> n = 6
-> j=9, n=6, contenido=[15, 16, 23, 42, 7, 9]
-> posiciones físicas: 9(15), 0(16), 1(23), 2(42), 3(7), 4(9)

---

### c) Por qué es necesario el módulo

El arreglo es circular: los elementos lógicos no siempre ocupan posiciones físicas contiguas de izquierda a derecha. Cuando `j + k >= 10`, la posición lógica "da la vuelta" al inicio del arreglo. El módulo implementa esa vuelta.

Sin módulo, al acceder a `a[j + k]` cuando `j + k >= 10` se sale del arreglo → acceso fuera de límites → comportamiento indefinido. Por ejemplo, con j=7 y k=3, la posición correcta es `a[(7+3) mod 10] = a[0]`, pero `a[7+3] = a[10]` viola los límites del arreglo de longitud 10.


---

### d) Comparación con ArrayList que elimina en posición 0

ArrayQueue circular:
- `add`: O(1) amortizado. El nuevo elemento va a `a[(j+n) mod 10]` sin mover nada.
- `remove`: O(1). Solo se avanza `j = (j+1) mod 10` y se decrementa `n`. No hay desplazamiento de datos.

ArrayList con `remove` en posición 0:
- `add` (al final): O(1) amortizado. Igual que `pushBack`.
- `remove` en posición 0: O(n). Eliminar el primer elemento obliga a desplazar todos los restantes una posición a la izquierda, lo mismo que `insert(0, x)` pero en sentido inverso.

La diferencia crítica está en `remove`. Para una cola con muchos enqueue/dequeue, `ArrayQueue` realiza cada operación en O(1) porque no hay datos que mover; el truco del índice circular evita esa necesidad. El `ArrayList` en cambio paga O(n) en cada `remove`, lo que resulta en O(n²) para n operaciones.


---

### e) DualArrayDeque: dos arreglos y rebalanceo

`DualArrayDeque` mantiene dos arreglos dinámicos (`front` y `back`) que juntos representan el deque:
- `front` almacena la primera mitad del deque en orden inverso (el elemento lógico 0 está en `front[front.size()-1]`).
- `back` almacena la segunda mitad en orden directo (el elemento lógico `front.size()` está en `back[0]`).

Esto permite que `addFirst`/`removeFirst` operen sobre el final de `front` en O(1), y que `addLast`/`removeLast` operen sobre el final de `back` en O(1), sin desplazamientos.

Por qué necesita rebalanceo:
Si se hacen muchos `removeFirst`, `front` se vacía mientras todos los elementos quedan en `back`. A partir de ese punto, `removeFirst` no tiene de dónde sacar el elemento frontal. Sin rebalanceo, la estructura degeneraría y alguna operación tendría que recorrer `back` completo → O(n).

Propiedad que debe mantener el rebalanceo:
Tras el rebalanceo, los tamaños de `front` y `back` deben satisfacer `|front.size() - back.size()| ≤ 1`, es decir, los elementos se redistribuyen equitativamente entre ambos arreglos. Esto garantiza que cualquier operación sobre cualquier extremo encuentre elementos disponibles en el arreglo correspondiente, manteniendo el costo amortizado O(1) por operación.


---

## Pregunta 5

### DLLList con nodo centinela

`DLLList<T>` usa un nodo centinela `dummy` donde `dummy.next` apunta al primer nodo real y `dummy.prev` al último. Si la lista está vacía, ambos apuntan a `dummy`.


---

### a) Pseudocódigo de `addBefore(Node* w, T x)`

`addBefore` inserta un nuevo nodo con valor `x` inmediatamente antes del nodo `w`. Se deben actualizar exactamente 4 enlaces:

```
addBefore(w, x):
    u = nuevo Node con u.x = x
    u.prev = w.prev        // u apunta hacia atrás al nodo que estaba antes de w
    u.next = w             // u apunta hacia adelante a w
    u.prev.next = u        // el nodo anterior a w ahora apunta a u
    u.next.prev = u        // w ahora apunta hacia atrás a u
    n = n + 1
    retornar u
```

El orden de las asignaciones es importante: `u.prev` y `u.next` deben establecerse antes de usarlos para actualizar los enlaces del entorno, porque `u.prev.next = u` necesita que `u.prev` ya apunte al nodo correcto.


---

### b) Por qué el nodo centinela elimina casos especiales

Sin centinela, insertar al inicio requeriría verificar si la lista está vacía para actualizar `head`, y al final requeriría verificar `tail`. Con centinela, `dummy` siempre es un nodo válido con `prev` y `next` bien definidos:

- Insertar al inicio: `addBefore(dummy.next, x)`. Si la lista está vacía, `dummy.next == &dummy`, así que se inserta antes del centinela mismo — exactamente el comportamiento correcto.
- Insertar al final: `addBefore(&dummy, x)`. El nuevo nodo queda antes del centinela, que es la posición "al final".

En ambos casos se ejecutan los mismos 4 pasos sin ningún `if`. El centinela actúa como vecino universal garantizando que siempre hay un nodo anterior y uno siguiente válidos.


---

### c) Por qué `getNode(i)` es O(1 + min{i, n−i})

La lista puede recorrerse desde ambos extremos:

- Desde `dummy.next` hacia adelante: llegar al nodo `i` cuesta `i` pasos.
- Desde `dummy.prev` hacia atrás: llegar al nodo `i` cuesta `n − i` pasos (se recorren los últimos `n − i` nodos).

La implementación elige el extremo más cercano:
- Si `i < n/2` → recorre desde el frente (`i` pasos).
- Si `i >= n/2` → recorre desde el final (`n − i` pasos).

El costo es entonces `min{i, n−i}` pasos de traversal más 1 acceso inicial al centinela → O(1 + min{i, n−i}).


---

### d) Diseño de `rotate(r)` sin mover datos

Rotar `r` posiciones a la derecha significa que los últimos `r` elementos pasan a ser los primeros. El nuevo primer nodo es el que estaba en la posición `n − r`.

Se identifican cuatro nodos clave y se actualizan 6 punteros:

```
rotate(r):
    si n <= 1: retornar
    r = r mod n
    si r < 0: r = r + n
    si r == 0: retornar

    oldFirst = dummy.next          // primer nodo actual
    oldLast  = dummy.prev          // último nodo actual
    newFirst = getNode(n - r)      // nuevo primer nodo tras la rotación
    newLast  = newFirst.prev       // nodo justo antes del punto de corte

    // unir los dos extremos originales (cierra el anillo temporalmente)
    oldLast.next  = oldFirst
    oldFirst.prev = oldLast

    // reconectar dummy al nuevo primer y último nodo
    dummy.next    = newFirst
    newFirst.prev = dummy
    dummy.prev    = newLast
    newLast.next  = dummy
```

No se copia ni mueve ningún dato; solo se redirigen 6 punteros. Costo: O(1 + min{n−r, r}) por el `getNode`, más O(1) para los redireccionamientos.


---

### e) Dos invariantes estructurales para detectar errores de punteros

Invariante 1 — consistencia bidireccional:
Para todo nodo `u` en la lista (incluyendo `dummy`): `u.prev.next == u` y `u.next.prev == u`. Un recorrido hacia adelante desde `dummy.next` que verifica esta propiedad en cada nodo detecta punteros rotos en cualquiera de los dos sentidos.

Invariante 2 — conteo consistente en ambas direcciones:
Un recorrido hacia adelante desde `dummy.next` hasta llegar de vuelta a `dummy` debe contar exactamente `n` nodos. Un recorrido hacia atrás desde `dummy.prev` hasta `dummy` también debe contar exactamente `n` nodos. Si los dos conteos difieren, o si alguno difiere de `n`, hay un ciclo roto o un enlace que apunta fuera de la lista.

Juntos estos invariantes son suficientes para detectar: nodos con `prev` o `next` nulos inesperados, inserciones que actualizaron solo la mitad de los punteros, y rotaciones que dejaron el centinela desconectado.


---

## Pregunta 6

### isBalanced

`isBalanced(string s)` retorna `true` si toda apertura `(`, `[`, `{` se cierra en orden correcto con su par correspondiente.


---

### a) Casos de prueba con salida esperada

Grupo 1 — casos que deben retornar `true`:

- `isBalanced("")` → `true`
  Cadena vacía: no hay aperturas ni cierres, la condición se satisface trivialmente.

- `isBalanced("({[]})")` → `true`
  Anidamiento correcto: cada apertura se cierra en orden inverso, sin cruces.

Grupo 2 — casos que deben retornar `false`:

- `isBalanced("([)]")` → `false`
  Cruce incorrecto: `[` abre antes que `)` intenta cerrar `(`, pero el tope de la pila es `[`, no `(`.

- `isBalanced(")")` → `false`
  Cierre sin apertura: se encuentra `)` con la pila vacía, no hay ningún `(` pendiente.

- `isBalanced("({[")` → `false`
  Apertura sin cierre: al terminar la cadena, la pila contiene `(`, `{`, `[` sin cerrar.


---

### b) Error específico que detecta cada grupo

Grupo 1 detecta que la función no produce falsos negativos: la cadena vacía no debe fallar por acceso a pila vacía, y el anidamiento correcto debe reconocerse íntegramente.

Grupo 2 detecta tres familias de error distintas:
- `"([)]"` detecta que la función verifica el tipo del cierre, no solo que la pila no esté vacía. Un error común sería solo verificar `!stack.empty()` y olvidar comparar el par.
- `")"` detecta que se maneja el caso de pila vacía al encontrar un cierre: sin esta verificación, `stack.pop()` dispara comportamiento indefinido o excepción.
- `"({["` detecta que al terminar la cadena se verifica que la pila quedó vacía: sin esta verificación, aperturas sin cierre pasarían como válidas.


---

### c) ADT adecuado

El ADT adecuado es una Pila (Stack), con operaciones `push`, `pop`, `top` y `empty`.

La lógica del problema requiere acceso LIFO: al encontrar un cierre, debe verificarse que el último símbolo abierto pendiente sea el par correspondiente. Una pila mantiene exactamente esta propiedad: `push` al encontrar una apertura, `pop` + verificación al encontrar un cierre. Ninguna otra estructura (cola, lista) ofrece acceso directo al último elemento insertado sin costo adicional.

```
isBalanced(s):
    pila = Pila vacía
    para cada carácter ch en s:
        si ch es '(' o '[' o '{':
            pila.push(ch)
        si ch es ')':
            si pila.empty() o pila.pop() ≠ '(': retornar false
        si ch es ']':
            si pila.empty() o pila.pop() ≠ '[': retornar false
        si ch es '}':
            si pila.empty() o pila.pop() ≠ '{': retornar false
    retornar pila.empty()
```


---

### d) Complejidad temporal y espacial

- Temporal: O(n), donde `n` es la longitud de la cadena. Cada carácter se procesa exactamente una vez: una operación `push` o `pop` de costo O(1), más ignorar caracteres que no son paréntesis.

- Espacial: O(n) en el peor caso. Si la cadena contiene solo aperturas (e.g., `"(((("`), todos los caracteres se apilan y la pila alcanza tamaño `n`.


---

## Pregunta 7 (3 pts)

### Mínimo en ventana deslizante


---

### a) Entrada, salida y precondiciones sobre k

- Entrada: una secuencia de `n` enteros `a[0], a[1], …, a[n-1]` recibidos en orden, y un entero `k`.
- Salida: para cada posición `i` con `i >= k-1`, el mínimo de `a[i-k+1], …, a[i]` (los últimos `k` elementos). Se producen en total `n-k+1` valores.
- Precondiciones sobre k: `1 <= k <= n`. Si `k = 1`, el mínimo de cada ventana es el propio elemento. Si `k > n`, no existe ninguna ventana completa y no se produce ninguna salida.


---

### b) Representación con deque de candidatos a mínimo

Se usa un deque monótono de índices: una cola de doble extremo que almacena índices de la secuencia original, manteniendo en todo momento que los valores asociados son estrictamente crecientes de frente a fondo.

- El frente del deque siempre contiene el índice del mínimo de la ventana actual.
- Al procesar `a[i]`, se eliminan del fondo todos los índices `j` donde `a[j] >= a[i]`, porque `a[i]` es más reciente y más pequeño: `a[j]` ya nunca puede ser el mínimo de ninguna ventana futura que incluya `a[i]`.
- Se elimina del frente cualquier índice que quedó fuera de la ventana (`índice < i - k + 1`).
- Tras estas dos limpiezas, se inserta `i` al fondo y se consulta el frente para obtener el mínimo.

```
slidingMin(a, n, k):
    deque = Deque vacío   // almacena índices
    para i = 0 hasta n-1:
        // eliminar del frente índices fuera de la ventana
        mientras deque no vacío y deque.front() < i - k + 1:
            deque.pop_front()
        // eliminar del fondo candidatos dominados por a[i]
        mientras deque no vacío y a[deque.back()] >= a[i]:
            deque.pop_back()
        deque.push_back(i)
        // reportar mínimo cuando la ventana está completa
        si i >= k - 1:
            reportar a[deque.front()]
```


---

### c) Invariantes de la estructura auxiliar

Invariante 1 — todos los índices pertenecen a la ventana actual:
Para todo índice `j` almacenado en el deque: `i - k + 1 <= j <= i`. Ningún índice fuera del rango de la ventana permanece en el deque.

Invariante 2 — valores estrictamente crecientes de frente a fondo:
Para índices consecutivos `j1, j2` en el deque (j1 antes que j2): `a[j1] < a[j2]`. Esto garantiza que el frente es siempre el mínimo de la ventana y que todos los elementos del deque son candidatos viables para futuras ventanas.


---

### d) Trace para [5, 2, 4, 1, 3, 0, 6] con k=3

Se muestran índice procesado, valor, estado del deque (como índices → valores) y el mínimo reportado.

i=0, a[0]=5:
-> deque vacío, push 0
-> deque = [0] → [5]
-> i < k-1, sin salida aún

i=1, a[1]=2:
-> fondo: a[0]=5 >= 2, pop 0
-> deque vacío, push 1
-> deque = [1] → [2]
-> i < k-1, sin salida aún

i=2, a[2]=4:
-> fondo: a[1]=2 < 4, se conserva
-> push 2
-> deque = [1, 2] → [2, 4]
-> frente (índice 1) dentro de ventana [0..2]
-> min ventana [5,2,4] = a[1] = 2

i=3, a[3]=1:
-> fondo: a[2]=4 >= 1, pop 2
-> fondo: a[1]=2 >= 1, pop 1
-> deque vacío, push 3
-> deque = [3] → [1]
-> frente (índice 3) dentro de ventana [1..3]
-> min ventana [2,4,1] = a[3] = 1

i=4, a[4]=3:
-> fondo: a[3]=1 < 3, se conserva
-> push 4
-> deque = [3, 4] → [1, 3]
-> frente (índice 3) dentro de ventana [2..4]
-> min ventana [4,1,3] = a[3] = 1

i=5, a[5]=0:
-> fondo: a[4]=3 >= 0, pop 4
-> fondo: a[3]=1 >= 0, pop 3
-> deque vacío, push 5
-> deque = [5] → [0]
-> frente (índice 5) dentro de ventana [3..5]
-> min ventana [1,3,0] = a[5] = 0

i=6, a[6]=6:
-> fondo: a[5]=0 < 6, se conserva
-> push 6
-> deque = [5, 6] → [0, 6]
-> frente (índice 5) dentro de ventana [4..6]
-> min ventana [3,0,6] = a[5] = 0

Salida: [2, 1, 1, 0, 0]


---

### e) Complejidad total y costo amortizado

Total: O(n). Cada índice se inserta al deque exactamente una vez (un `push_back`) y se elimina a lo sumo una vez (un `pop_back` o `pop_front`). El total de operaciones sobre el deque a lo largo de toda la secuencia es por tanto ≤ 2n → O(n).

Amortizado por elemento: O(1). Aunque en algunas iteraciones se realizan varios `pop_back` consecutivos, cada elemento "paga" su propio pop cuando fue insertado. Distribuyendo el costo de todos los pops entre los n elementos, el costo amortizado por elemento es O(1).


---

### f) Comparación con recalcular el mínimo recorriendo la ventana

El algoritmo de fuerza bruta recorre los `k` elementos de la ventana en cada posición para encontrar el mínimo → O(k) por posición → O(n·k) total.

El deque monótono mantiene el mínimo de forma incremental → O(n) total.

Para `k` grande, el naívo repite trabajo en cada paso porque no aprovecha el mínimo ya calculado en la ventana anterior. El deque en cambio descarta candidatos imposibles de forma permanente, evitando esas comparaciones repetidas. La diferencia se vuelve significativa cuando `k` crece proporcionalmente a `n`.
