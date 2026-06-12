# Respuestas obligatorias - PC3 CC232

- **Estudiante:** Paul Flores Enrique Alejandro
- **Problema asignado:** CSES 1076 - Sliding Window Median
- **Enlace oficial:** https://cses.fi/problemset/task/1076
- **Estructura usada:** dos heaps binarios, un max heap y un min heap, con lazy deletion, reusando BinaryHeap de la Semana 5
- **Semana de apoyo:** Semana 6, heaps y colas de prioridad y lazy deletion, apoyada en BinaryHeap de la Semana 5

---

## 1. Preguntas comunes obligatorias

1. **¿Cuál es el problema exacto asignado?**

El problema es el CSES 1076 Sliding Window Median. Me dan un arreglo de n enteros y un tamaño de ventana k, y tengo que calcular la mediana de cada ventana de k elementos consecutivos de izquierda a derecha. La mediana es el elemento del medio cuando ordeno la ventana, y si k es par se toma el menor de los dos del medio, o sea la mediana inferior.

2. **¿Qué recibe la entrada y qué produce la salida?**

La entrada llega por la entrada estandar. La primera linea trae n y k, y despues vienen los n numeros del arreglo. La salida son n menos k mas 1 valores, que son las medianas de cada ventana separadas por un espacio. Eso lo hace src/main.cpp, que lee n, k y el vector x e imprime las medianas.

3. **¿Cuál es la restricción que vuelve insuficiente una solución ingenua?**

La restriccion es que n y k pueden llegar hasta 2 por 10 a la 5. Si ordeno cada ventana desde cero el costo es n por k por log k, que puede ser como 10 a la 11 operaciones y se pasa del tiempo. El benchmark lo muestra, con n igual a 8000 la fuerza bruta ya tarda como medio segundo.

4. **¿Cuál sería la solución ingenua y cuál es su complejidad?**

La solucion ingenua es copiar cada ventana, ordenarla con sort y tomar la posicion k menos 1 entre 2. Su complejidad es n por k por log k en tiempo y k en espacio extra. Esta en demos/demo_sliding_window_first.cpp y la uso como referencia en las pruebas y el benchmark.

5. **¿Qué estructura de datos elegiste?**

Elegi dos heaps con lazy deletion. small_ es un max heap con la mitad baja de la ventana y large_ es un min heap con la mitad alta. El tope de small_ es la mediana inferior. Todo esto esta en include/SlidingWindowMedian.h.

6. **¿Qué estructura de la librería `cc232` se parece más?**

La que mas se parece es BinaryHeap de las Semanas 5 y 6, que reuso directamente como small_ y large_. Tambien se relaciona con PQ y los heaps de la Semana 6 y con la idea de lazy deletion de esa semana.

7. **¿Qué operación domina el tiempo?**

Lo que domina el tiempo son las inserciones y eliminaciones en los heaps, es decir add y remove, que por dentro hacen bubbleUp y trickleDown y cuestan log k. Por cada ventana hago un add y un remove, asi que cada ventana cuesta log k.

8. **¿Qué invariante mantiene tu estructura?**

El invariante es que small_ es un max heap con la mitad baja, large_ es un min heap con la mitad alta, y los tamaños logicos cumplen que smallSize_ es igual a largeSize_ o uno mas. Por eso el tope de small_ siempre es la mediana inferior. Los tamaños son logicos porque no cuentan los elementos marcados para borrar en delayed_.

9. **¿Dónde se actualiza ese invariante en el código?**

El invariante se actualiza en rebalance, que mueve un tope de un heap al otro para mantener los tamaños, y en add y remove, que actualizan smallSize_, largeSize_ y delayed_. Tambien en prune, que asegura que el tope sea un elemento vivo antes de leer la mediana o de balancear.

10. **¿Qué caso borde puede romper una solución superficial?**

Los casos que rompen una solucion superficial son k par, donde uno podria tomar el promedio en vez de la mediana inferior, los elementos repetidos u obsoletos, donde se podria borrar la ocurrencia equivocada, la ventana de tamaño 1 y el caso k igual a n. Todos estan en tests/test_casos_borde.cpp.

11. **¿Cómo manejas duplicados, empates o elementos obsoletos?**

Los manejo con lazy deletion. Cuando un valor sale de la ventana aumento delayed_ en ese valor y ajusto el tamaño logico, y el elemento fisico se descarta recien cuando llega al tope con prune. Como delayed_ cuenta por valor, si hay duplicados solo se descarta una ocurrencia y no todas.

12. **¿Cuál es la complejidad temporal por operación?**

add cuesta log k, remove cuesta log k amortizado porque el descarte diferido se paga una sola vez por elemento, y median cuesta constante porque solo lee el tope de small_.

13. **¿Cuál es la complejidad total?**

La complejidad total es n por log k, porque por cada una de las n menos k mas 1 ventanas hago un add y un remove y cada uno cuesta log k.

14. **¿Cuál es la complejidad espacial?**

El espacio es del orden de k, porque los heaps guardan a lo mas la ventana mas algunos elementos diferidos que todavia no se purgan, y delayed_ tiene a lo mas k entradas distintas.

15. **¿Qué parte del código sería más fácil de romper?**

Lo mas facil de romper es la decision de a que heap entra cada valor, que es la comparacion x menor o igual al tope de small_, junto con el rebalance. Si eso falla se rompe el invariante y salen medianas malas. Tambien el prune, porque si no se limpia el tope antes de leer la mediana o de balancear se podria mover o leer un elemento ya borrado.

16. **¿Qué alternativa de estructura existe y qué perderías con ella?**

Una alternativa es un Treap aumentado con size y la operacion kth, que es un order statistic tree. Es elegante pero hay que aumentar los nodos y manejar duplicados, con mas codigo y mas dificil de explicar. Otra opcion seria un multiset con un iterador al medio, pero eso seria una caja negra que la rubrica no acepta como estructura central. Con el Treap perderia simplicidad y el uso directo de la idea de lazy deletion.

17. **¿Qué prueba propia escribiste?**

Escrib dos pruebas. test_median.cpp corre el caso del enunciado mas 3000 casos aleatorios comparando la version eficiente contra la fuerza bruta, con duplicados y k par e impar. test_casos_borde.cpp prueba k igual a 1, k igual a n, todos iguales, k par, n igual a 1 y lazy deletion con repetidos. La evidencia esta en resultados/tests_pc3.txt y resultados/casos_borde.txt.

18. **¿Qué cambiaste durante el bloque sin cortes?**

Agregue un metodo cumpleInvariante a la estructura SlidingWindowMedian, que revisa que los tamaños esten balanceados, es decir smallSize_ igual a largeSize_ o uno mas, y que el tope de small_ no sea mayor que el tope de large_. Tambien agregue una prueba nueva en tests/test_invariante.cpp que, despues de cada ventana, llama a cumpleInvariante y compara la mediana contra la fuerza bruta, y la registre en ctest.

19. **¿Cómo sabes que el cambio no rompió la solución?**

Porque volvi a compilar y a correr ctest, y las tres pruebas pasan, incluida la nueva del invariante, ademas la salida del programa con el ejemplo sigue siendo 3 4 5 5 2 1. Como cumpleInvariante da true en todas las ventanas y la mediana sigue coincidiendo con la fuerza bruta, se que el cambio no altero el comportamiento.

20. **¿Qué demuestra que no es una solución de caja negra?**

Que el codigo es mio y lo puedo seguir linea por linea. No use un multiset ni un priority_queue ya armado para sacar la mediana, sino que monte los dos heaps a mano sobre el BinaryHeap del curso. Puedo explicar por que comparo x con el tope de small_ para decidir a que lado va, o por que el prune tiene que limpiar el tope antes de leer la mediana. Si me cambian un detalle se que parte se rompe y por que. Ademas no me quedo en que parece funcionar, lo compare contra la fuerza bruta en muchos casos para estar seguro.

---

## 2. Preguntas específicas del problema (CSES 1076)

1. **¿Cómo se mantiene el elemento medio al mover la ventana?**

Se mantiene gracias al invariante de tamaños entre los dos heaps. Al mover la ventana hago add del nuevo elemento y remove del que sale con lazy deletion, y despues rebalance reajusta los tamaños para que small_ conserve la mitad baja. Asi el tope de small_ sigue siendo la mediana sin tener que reordenar toda la ventana.

2. **¿Qué ocurre con duplicados?**

Los duplicados se manejan con delayed_, que cuenta cuantas veces hay que borrar cada valor. Los heaps pueden tener varias copias del mismo numero sin problema y al purgar solo se quita una ocurrencia. La regla x menor o igual al tope de small_ mantiene la consistencia de a que mitad va cada copia.

3. **¿Qué operación domina el tiempo por ventana?**

Lo que domina el tiempo por ventana son las operaciones de heap dentro de add y remove, o sea bubbleUp y trickleDown, que cuestan log k. Por ventana hago un add y un remove, asi que el costo por ventana es log k y el total n por log k.

---

## 3. Reto grabado obligatorio

> Agregar una prueba con `k` par e impar y explicar qué mediana se usa.

La prueba esta en demos/demo_par_impar.cpp. La mediana siempre es el elemento de la posicion (k-1)/2 al ordenar la ventana, tanto para k par como impar. Con k impar la ventana {2,3,4} tiene un solo elemento central y la mediana es 3. Con k par la ventana {1,2,3,4} tiene dos elementos centrales, 2 y 3, y se usa el menor de los dos, es decir la mediana inferior, que es 2 y no el promedio 2.5. Esto tambien queda cubierto en tests/test_casos_borde.cpp con los casos de k par.

