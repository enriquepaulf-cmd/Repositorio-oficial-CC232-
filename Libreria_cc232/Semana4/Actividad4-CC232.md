### Actividad 4 - Semana 4

- Duración: 3 horas de clase.
- Modalidad: Trabajo individual.
- Tiempo de instalación: 15 minutos al inicio.
- Entrega: Un archivo llamado `Actividad4-CC232.md`.

#### Objetivo

Consolidar lo trabajado en la Semana 4 a partir de código, demos, pruebas, experimentos y una defensa escrita breve.

La meta es distinguir con claridad cómo `Stack` y `Queue` dejan de ser solo estructuras lineales y pasan a funcionar como herramientas algorítmicas para resolver problemas de conversión de base, verificación de paréntesis, evaluación de expresiones, búsqueda con retroceso y simulación.

Además, se busca comparar explícitamente enfoques recursivos e iterativos, justificar qué información guarda cada estructura auxiliar, defender por qué una pila explícita puede reemplazar recursión implícita, y analizar cómo pequeñas decisiones de diseño cambian el comportamiento observable en N-Reinas, laberintos y simulación bancaria.

#### Material de trabajo

##### Código de la semana

- `Semana4/README.md`
- `Semana4/CMakeLists.txt`
- `Semana4/include/Stack.h`
- `Semana4/include/Queue.h`
- `Semana4/include/BaseConversion.h`
- `Semana4/include/Parentheses.h`
- `Semana4/include/OperatorPriority.h`
- `Semana4/include/ExpressionEvaluator.h`
- `Semana4/include/Queen.h`
- `Semana4/include/NQueens.h`
- `Semana4/include/Maze.h`
- `Semana4/include/BankSimulation.h`
- `Semana4/include/Capitulo4.h`
- `Semana4/demos/demo_stack_queue.cpp`
- `Semana4/demos/demo_base_conversion.cpp`
- `Semana4/demos/demo_paren_rpn.cpp`
- `Semana4/demos/demo_nqueens.cpp`
- `Semana4/demos/demo_maze.cpp`
- `Semana4/demos/demo_bank.cpp`
- `Semana4/demos/demo_capitulo4_panorama.cpp`
- `Semana4/pruebas_publicas/test_public_week4.cpp`
- `Semana4/pruebas_internas/test_internal_week4.cpp`
- `Semana4/Ejercicios4-CC232.md`

#### Lecturas obligatorias

- Capítulo 4 de Deng: pilas, colas y aplicaciones.
- README de la Semana 4.

#### Bloque 0 - Instalación y preparación

1. Deja lista tu carpeta de trabajo.
2. Verifica que puedes abrir `Semana4`, las lecturas y el archivo de entrega.
3. Crea el archivo `Actividad4-CC232.md`.
4. Anota tu nombre completo.
5. Compila y ejecuta al menos una demostración y una prueba pública de Semana 4.

#### Bloque 1 - Núcleo conceptual de la semana

Revisa:

- `Semana4/README.md`
- `Semana4/include/Stack.h`
- `Semana4/include/Queue.h`
- `Semana4/include/BaseConversion.h`
- `Semana4/include/Parentheses.h`
- `Semana4/include/ExpressionEvaluator.h`
- `Semana4/include/NQueens.h`
- `Semana4/include/Maze.h`
- `Semana4/include/BankSimulation.h`
- Capítulo 4 de Deng.

Responde:

1. Explica con tus palabras la diferencia entre acceso `LIFO` y acceso `FIFO`.
2. Explica por qué `Stack` resuelve naturalmente problemas donde importa "lo último pendiente".
3. Explica por qué `Queue` modela naturalmente procesos de espera y atención.
4. Explica qué significa reemplazar recursión implícita por una estructura explícita.
5. Explica qué información mínima debe guardarse para que una pila permita reconstruir una solución parcial.
6. Compara la conversión de base recursiva e iterativa: ¿qué comparten y qué cambia en el control del proceso?
7. Explica por qué la verificación iterativa de paréntesis necesita almacenar aperturas pendientes.
8. Explica por qué el evaluador de expresiones necesita dos pilas y no una sola.
9. Explica por qué N-Reinas y laberinto son ejemplos naturales de backtracking.
10. Explica por qué la simulación bancaria no se modela bien con pila, pero sí con colas.
11. Explica qué relación hay entre estructura auxiliar, estado parcial y correctitud.
12. Explica qué diferencia conceptual hay entre "resolver un problema" y "simular un proceso".

#### Bloque 2 - Demostración y trazado guiado

Revisa:

- `Semana4/demos/demo_stack_queue.cpp`
- `Semana4/demos/demo_base_conversion.cpp`
- `Semana4/demos/demo_paren_rpn.cpp`
- `Semana4/demos/demo_nqueens.cpp`
- `Semana4/demos/demo_maze.cpp`
- `Semana4/demos/demo_bank.cpp`
- `Semana4/demos/demo_capitulo4_panorama.cpp`

Construye una tabla con cuatro columnas:

- Archivo
- Salida u observable importante
- Estructura o técnica central
- Qué concepto permite defender

Luego responde:

1. En `demo_stack_queue.cpp`, ¿qué parte de la salida deja más clara la diferencia entre tope y frente?
2. En `demo_base_conversion.cpp`, ¿qué observable permite afirmar que las versiones recursiva e iterativa producen la misma representación?
3. En `demo_paren_rpn.cpp`, ¿qué relación observas entre paréntesis balanceados, RPN y valor final?
4. En `demo_nqueens.cpp`, ¿qué significan `solutions` y `checks`, y por qué no miden lo mismo?
5. En `demo_maze.cpp`, ¿qué muestra la secuencia de coordenadas sobre el camino encontrado?
6. En `demo_bank.cpp`, ¿qué representa cada lista impresa en cada instante `t`?
7. En `demo_capitulo4_panorama.cpp`, ¿qué salida resume mejor la idea de que una misma semana reúne estructuras y aplicaciones?

#### Bloque 3 - Pruebas públicas, pruebas internas y correctitud

Revisa:

- `Semana4/pruebas_publicas/test_public_week4.cpp`
- `Semana4/pruebas_internas/test_internal_week4.cpp`

Responde:

1. ¿Qué operaciones mínimas valida la prueba pública para `Stack`?
2. ¿Qué operaciones mínimas valida la prueba pública para `Queue`?
3. ¿Qué valida la prueba pública sobre conversión de base?
4. ¿Qué valida la prueba pública sobre paréntesis balanceados?
5. ¿Qué valida la prueba pública sobre evaluación de expresiones y RPN?
6. ¿Qué valida la prueba pública sobre `NQueens`?
7. ¿Qué valida la prueba pública sobre `Maze`?
8. ¿Qué valida la prueba pública sobre `bestWindow` en la simulación bancaria?
9. ¿Qué casos adicionales cubre la prueba interna y no aparecen de forma explícita en la pública?
10. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes, estado y complejidad?
11. Da un ejemplo de un error conceptual que podría sobrevivir si solo se ejecutaran los casos mínimos.

#### Bloque 4 - Comparación recursivo vs iterativo

Revisa:

- `Semana4/include/BaseConversion.h`
- `Semana4/include/Parentheses.h`
- `Semana4/demos/demo_base_conversion.cpp`
- `Semana4/demos/demo_paren_rpn.cpp`

Responde:

1. En conversión de base, ¿qué papel juegan el cociente, el residuo y la pila?
2. ¿Por qué los residuos se apilan antes de formar la cadena final?
3. ¿Qué cambia entre dejar que el call stack haga el trabajo y manejar una pila explícita?
4. En `parenRecursive`, ¿qué idea intenta capturar `divideParentheses`?
5. ¿Qué limitación conceptual tiene la versión recursiva mostrada frente a la iterativa cuando aparecen `[]` y `{}`?
6. En `parenIterative`, ¿por qué un cierre incorrecto puede detectarse apenas aparece?
7. Compara ambas parejas de funciones: ¿en cuál caso la versión iterativa te parece más natural y en cuál la recursiva resulta más expresiva?

##### Experimento 1

Ejecuta pruebas propias con al menos cinco números y cuatro bases distintas para `toBaseRecursive` y `toBaseIterative`.

Registra en una tabla:

- Número
- Base
- Salida recursiva
- Salida iterativa
- ¿Coinciden?
- Comentario

##### Experimento 2

Construye una batería de al menos ocho expresiones para paréntesis, incluyendo:

- una vacía,
- una sin paréntesis,
- una correctamente anidada,
- una con desbalance,
- una con cruce incorrecto,
- una con varios tipos de delimitadores,
- una larga,
- una inventada por ti.

Para cada caso indica:

- resultado recursivo,
- resultado iterativo,
- si ambos coinciden,
- qué explica el caso.

#### Bloque 5 - Evaluación de expresiones y prioridad de operadores

Revisa:

- `Semana4/include/OperatorPriority.h`
- `Semana4/include/ExpressionEvaluator.h`
- `Semana4/demos/demo_paren_rpn.cpp`
- `Semana4/pruebas_publicas/test_public_week4.cpp`
- `Semana4/pruebas_internas/test_internal_week4.cpp`

Responde:

1. Explica qué información guarda `EvaluationResult`.
2. Explica por qué primero se eliminan espacios.
3. Explica cómo se detecta el signo menos unario.
4. Explica por qué el factorial se trata como operador unario y qué restricción impone el código.
5. Explica cómo la RPN se va construyendo durante la evaluación y no al final.
6. Explica qué significa la relación entre operador del tope y símbolo actual.
7. Explica por qué una expresión mal formada debe terminar en error y no en un valor arbitrario.
8. ¿Qué ventaja conceptual tiene obtener a la vez el valor y la RPN?

##### Experimento 3

Propón y ejecuta al menos seis expresiones nuevas:

- dos válidas sin paréntesis,
- dos válidas con anidamiento,
- una con menos unario,
- una inválida.

Para cada una registra:

- expresión,
- RPN esperada,
- RPN obtenida,
- valor esperado u error esperado,
- valor obtenido o error observado,
- explicación breve.

##### Extensión opcional

Extiende el evaluador con un operador adicional elegido por ti.

La defensa debe incluir obligatoriamente:

- qué símbolo agregaste,
- su aridad,
- su prioridad,
- qué casos válidos probaste,
- qué caso inválido probaste,
- qué parte del código tuviste que modificar.

#### Bloque 6 - Backtracking explícito: N-Reinas y laberinto

Revisa:

- `Semana4/include/Queen.h`
- `Semana4/include/NQueens.h`
- `Semana4/include/Maze.h`
- `Semana4/demos/demo_nqueens.cpp`
- `Semana4/demos/demo_maze.cpp`
- `Semana4/pruebas_publicas/test_public_week4.cpp`
- `Semana4/pruebas_internas/test_internal_week4.cpp`

Responde:

1. En `Queen`, ¿qué significa que dos reinas entren en conflicto?
2. En `NQueens`, ¿qué representa exactamente la pila `solution`?
3. ¿Qué significa avanzar en columna dentro de una fila y cuándo toca retroceder?
4. ¿Por qué `checks` es una métrica útil para analizar la búsqueda?
5. ¿Qué cambia cuando `collectPlacements` vale `false`?
6. En `Maze`, ¿qué representa el estado `AVAILABLE`, `ROUTE`, `BACKTRACKED` y `WALL`?
7. ¿Qué información codifican `incoming` y `outgoing`?
8. ¿Por qué el algoritmo del laberinto marca y desmarca estado en lugar de solo "moverse"?
9. Compara N-Reinas y laberinto: ¿qué comparten como problemas de búsqueda y qué cambia en la representación del estado?

##### Experimento 4

Ejecuta `placeQueens(n)` para al menos cuatro valores de `n`.

Registra en una tabla:

- `n`
- número de soluciones
- número de `checks`
- ¿crece rápido o lento?
- comentario

Luego responde:

1. ¿Qué patrón observas en el crecimiento de `checks`?
2. ¿Por qué contar verificaciones no es lo mismo que contar soluciones?
3. ¿Dónde aparece la "poda" en este código, aunque no haya una estructura formal con ese nombre?

##### Experimento 5

Diseña al menos tres laberintos propios:

- uno con camino claro,
- uno sin salida,
- uno donde el algoritmo deba retroceder varias veces.

Para cada laberinto registra:

- grilla usada,
- coordenadas de inicio y destino,
- longitud del camino o ausencia de camino,
- evidencia de retroceso,
- interpretación.

#### Bloque 7 - Simulación bancaria y experimentación con colas

Revisa:

- `Semana4/include/Queue.h`
- `Semana4/include/BankSimulation.h`
- `Semana4/demos/demo_bank.cpp`
- `Semana4/pruebas_publicas/test_public_week4.cpp`
- `Semana4/pruebas_internas/test_internal_week4.cpp`

Responde:

1. ¿Qué representa cada `Queue<Customer>` dentro del vector `windows`?
2. ¿Qué criterio usa `bestWindow` y qué decisión toma cuando hay empate?
3. ¿Qué significa que la simulación use una semilla (`seed`)?
4. ¿Qué relación debe cumplirse entre `totalArrivals` y `totalServed`, y por qué?
5. ¿Qué representa la línea de tiempo (`timeline`) en el resultado?
6. ¿Por qué esta aplicación necesita colas y no pilas?
7. ¿Qué simplificación del mundo real introduce este simulador?
8. ¿Qué cambiaría si la política ya no fuera "cola más corta" sino otra?

##### Experimento 6

Ejecuta la simulación variando al menos tres parámetros:

- número de ventanillas,
- duración total,
- semilla.

Construye una tabla con:

- `nWin`
- `servTime`
- `seed`
- `totalArrivals`
- `totalServed`
- tamaño final de cada cola
- observación

Luego responde:

1. ¿Qué parámetro parece influir más en la congestión observable?
2. ¿Qué cambia cuando repites exactamente la misma semilla?
3. ¿Qué cambia cuando mantienes `nWin` y `servTime`, pero alteras la semilla?
4. ¿Qué evidencia usarías para defender que la cola más corta es una política razonable, aunque no necesariamente óptima?

#### Bloque 8 - Cierre comparativo y preparación de sustentación

Responde esta pregunta final:

**¿Qué cambia cuando pasamos de "usar pilas y colas como ADTs básicos" a "usarlas como mecanismos de control para resolver problemas"?**

La respuesta debe incluir obligatoriamente:

- una afirmación sobre `LIFO` y `FIFO`,
- una afirmación sobre recursión implícita frente a estructura explícita,
- una afirmación sobre evaluación de expresiones,
- una afirmación sobre backtracking,
- una afirmación sobre simulación,
- una afirmación sobre correctitud experimental,
- una comparación entre conversión de base, paréntesis, N-Reinas, laberinto y banco.

#### Formato sugerido de entrega

```md
## Actividad 4-CC232

### Estudiante
- Nombre completo

#### Bloque 1 (respuestas)
#### Bloque 2 (tabla y respuestas)
#### Bloque 3 (respuestas)
#### Bloque 4 (respuestas y experimentos 1-2)
#### Bloque 5 (respuestas y experimento 3)
#### Bloque 6 (respuestas y experimentos 4-5)
#### Bloque 7 (respuestas y experimento 6)
#### Bloque 8 (respuesta final)

#### Autoevaluación breve
- Qué puedo defender con seguridad:
- Qué todavía confundo:
- Qué experimento me dio mejor evidencia:
- Qué evidencia usaría en una sustentación:
```

#### Criterio general de trabajo

Se espera lectura real de los archivos, respuestas breves pero justificadas, y conexión explícita entre código, correctitud, estado, estructuras auxiliares, recursión, backtracking, simulación y evidencia experimental.

No basta con ejecutar el programa: debes poder explicar por qué funciona, qué información mantiene cada estructura, qué decisión toma el algoritmo en cada paso y qué evidencia experimental respalda tu defensa.

---
---

## Actividad 4-CC232

### Estudiante
- Nombre completo: Paul Flores Enrique Alejandro

#### Bloque 1 (respuestas)

1. La diferencia es el orden en que salen los elementos. LIFO quiere decir last in first out, o sea lo ultimo que entra es lo primero que sale, como una pila de platos donde sacas el de arriba. FIFO quiere decir first in first out, lo primero que entra es lo primero que sale, como una fila en el banco donde te atienden por orden de llegada.

2. Porque la pila siempre te da acceso directo al ultimo elemento que metiste, que es el tope. Cuando un problema necesita atender primero lo mas reciente que quedo pendiente, como la ultima llamada en una recursion o el ultimo parentesis que se abrio, la pila te entrega justo eso sin tener que buscar.

3. Porque en una cola se atiende en el mismo orden en que llegan, el primero que llego es el primero en salir. Eso es exactamente lo que pasa cuando hay gente esperando su turno, asi que modela natural los procesos de espera y atencion.

4. La recursion usa por dentro la pila de llamadas del sistema sin que tu la veas, ahi se guarda en que punto quedo cada llamada. Reemplazar eso por una estructura explicita significa que tu mismo creas un Stack y guardas ahi el estado que el sistema guardaria solo, decidiendo a mano cuando apilas y cuando desapilas.

5. Hay que guardar las decisiones que se tomaron hasta el momento, en orden, de manera que se pueda deshacer la ultima y conservar las demas. Por ejemplo en N-Reinas se guarda la columna elegida en cada fila, asi se puede retroceder quitando la ultima reina y seguir probando.

6. Comparten la misma idea matematica, que es dividir el numero entre la base e ir guardando los residuos, y que esos residuos salen en orden inverso al de la respuesta final. Lo que cambia es el control del proceso: en la version recursiva el orden inverso lo arma sola la pila de llamadas, y en la iterativa lo armas tu con una pila explicita.

7. Porque cuando aparece un cierre necesitas saber cual fue la ultima apertura que todavia no se ha cerrado, para revisar si corresponden. Esa apertura pendiente se guarda en la pila, y al llegar el cierre se desapila y se compara.

8. Porque necesita separar dos cosas distintas: los operandos, que son los numeros, y los operadores. Mientras lees la expresion a veces no puedes aplicar un operador todavia porque puede venir otro de mayor prioridad, asi que los operadores quedan en su propia pila esperando. Con una sola pila no podrias distinguir valores de operaciones pendientes.

9. Porque los dos prueban una opcion y, si esa opcion lleva a un callejon sin salida, retroceden y prueban otra. Esa idea de avanzar tentativamente y deshacer cuando no funciona es justamente el backtracking.

10. Porque en el banco se atiende por orden de llegada, que es FIFO, y eso es lo que hace una cola. Una pila atenderia primero al ultimo que llego, que es LIFO, lo cual seria injusto y no representa como funciona realmente la atencion.

11. La estructura auxiliar guarda el estado parcial del proceso en cada paso. Si ese estado se mantiene consistente todo el tiempo, es decir si se respeta el invariante, entonces el resultado final sale correcto. La correctitud depende de que la estructura siempre refleje bien lo que se lleva hecho.

12. Resolver un problema es buscar una respuesta concreta, como un camino, un valor o el conjunto de soluciones. Simular un proceso es reproducir como evoluciona un sistema en el tiempo, como el banco paso a paso, para observar su comportamiento, sin que necesariamente haya una unica respuesta final.

#### Bloque 2 (tabla y respuestas)

| Archivo | Salida u observable importante | Estructura o tecnica central | Que concepto permite defender |
|---|---|---|---|
| demo_stack_queue.cpp | Tope de la pila = 9 y desapila 9; frente de la cola = 10 y desencola 10 | Stack y Queue | La diferencia entre LIFO y FIFO |
| demo_base_conversion.cpp | 12345 en base 8 da 30071 en recursivo y en iterativo | Pila explicita y pila de llamadas | Recursivo vs iterativo dan el mismo resultado |
| demo_paren_rpn.cpp | Balanceados = true, RPN = 0 ! 1 + ... , valor = 2012 | Pila para parentesis y dos pilas para evaluar | Verificacion de balance y evaluacion de expresiones |
| demo_nqueens.cpp | N = 4, soluciones = 2, verificaciones = 84 | Backtracking con pila de solucion | Busqueda con retroceso y costo de exploracion |
| demo_maze.cpp | Medida del camino = 5, coordenadas (1,1) ... (3,3) | Backtracking sobre una grilla | Reconstruccion de un camino con marca y desmarca |
| demo_bank.cpp | Llegadas = 7, atendidos = 0, listas por ventanilla en cada t | Colas, una por ventanilla | Simulacion de un proceso de espera con FIFO |
| demo_capitulo4_panorama.cpp | Resumen con una linea por cada tema de la semana | Todas las anteriores juntas | Que una semana reune estructuras y aplicaciones |

1. La parte mas clara es que la pila muestra tope = 9 y al desapilar devuelve 9, que fue lo ultimo que se metio, mientras que la cola muestra frente = 10 y al desencolar devuelve 10, que fue lo primero que se metio. Comparar esos dos numeros deja ver que la pila saca por el ultimo y la cola por el primero.

2. El observable es que las dos lineas dan exactamente el mismo numero, 12345 en base 8 da 30071 tanto en la version recursiva como en la iterativa. Que coincidan letra por letra permite afirmar que producen la misma representacion.

3. Se ve que solo porque los parentesis estan balanceados, que sale true, la expresion esta bien formada y se puede pasar a RPN, y que evaluando esa RPN se obtiene un valor concreto, 2012. Si no estuviera balanceada no habria RPN valida ni valor final, asi que las tres cosas estan encadenadas.

4. Soluciones es la cantidad de tableros completos validos que se encontraron, en este caso 2. Verificaciones es cuantas veces se reviso si habia conflicto durante la busqueda, en este caso 84. No miden lo mismo porque soluciones cuenta respuestas finales y verificaciones cuenta el esfuerzo total para encontrarlas, incluyendo los intentos que se descartaron. Por eso hay solo 2 soluciones pero 84 verificaciones.

5. La secuencia de coordenadas muestra el camino real que encontro el algoritmo desde el inicio (1,1) hasta el destino (3,3), celda por celda, y que ese camino tiene longitud 5. O sea no solo dice que hay salida, sino por donde pasa.

6. Cada lista representa el contenido de la cola de una ventanilla en ese instante t, o sea los clientes que estan esperando en cada ventanilla. Como hay tres listas, hay tres ventanillas, y los numeros son los identificadores de los clientes. Al avanzar el tiempo se ve como van llegando clientes y se ponen en la cola mas corta.

7. La salida que mejor lo resume es el bloque completo del panorama, donde aparece una linea por cada tema: tope de pila, frente de cola, conversion de base, parentesis, RPN, valor, N-Reinas, laberinto y banco. Verlos todos juntos en una sola corrida muestra que la misma semana reune las estructuras basicas, que son pila y cola, y sus aplicaciones.

#### Bloque 3 (respuestas)

1. Valida lo basico de la pila: que empieza vacia, que con push se agregan elementos, que top devuelve 9 que fue el ultimo metido, que pop devuelve primero 9 y despues 5 respetando el orden LIFO, y que al final vuelve a quedar vacia.

2. Valida lo basico de la cola: que empieza vacia, que con enqueue se agregan 1, 2 y 3, que front devuelve 1 que fue el primero, que dequeue devuelve 1, despues 2 y despues 3 respetando el orden FIFO, y que al final queda vacia.

3. Valida que toBaseRecursive y toBaseIterative, con 12345 en base 8, dan ambas la cadena 30071. O sea comprueba que la representacion es la correcta y que las dos versiones coinciden.

4. Valida tres casos: una expresion bien anidada con parentesis normales da true, una con varios tipos de delimitadores como corchetes y llaves tambien da true, y una con cruce incorrecto como ([)] da false. Asi cubre balance correcto y un mal anidamiento que debe rechazarse.

5. Valida que para la expresion (0!+1)*2^(3!+4)-(5!-67-(8+9)) se obtiene la RPN exacta esperada y el valor 2012. Comprueba que arma bien la notacion postfija y que el resultado numerico es correcto, incluyendo factorial y potencia.

6. Valida que placeQueens(4) encuentra exactamente 2 soluciones y que efectivamente guarda esas 2 ubicaciones. Comprueba tanto el conteo como que las soluciones quedan almacenadas.

7. Valida que en un laberinto que si tiene camino, findPath de (1,1) a (3,3) devuelve una ruta no vacia que empieza en (1,1) y termina en (3,3). Comprueba que encuentra el camino y que arranca y termina donde se pide.

8. Valida que bestWindow elige la cola mas corta. Con la ventanilla 0 con dos clientes, la ventanilla 1 con uno y la ventanilla 2 vacia, devuelve 2, que es la mas corta.

9. La prueba interna agrega casos borde y de error que no estan explicitos en la publica: la conversion del cero que debe dar 0 y la base 16 con letras que da FF; una cadena sin parentesis que es valida, un caso )()( mal ordenado y un cruce {[(])} que deben dar false; expresiones con prioridad como 3+4*2 igual a 11, con factorial y potencia 5!+2^3 igual a 128, y con menos unario -3+5 igual a 2; N-Reinas con n=1 que da una solucion con la reina en la columna 0; un laberinto sin salida cuyo camino queda vacio; la simulacion del banco con semilla fija que revisa ventanillas, tiempo de servicio, que las llegadas sean mayores o iguales a los atendidos y el tamaño de la linea de tiempo; y que toBaseIterative con base 1 lance una excepcion de argumento invalido.

10. Porque las pruebas solo confirman que en los casos elegidos la salida es la esperada, pero no explican por que funciona ni cubren todos los casos posibles. Un codigo puede pasar los ejemplos y aun asi fallar en uno no probado o ser ineficiente. Explicar el invariante, el estado que se mantiene y la complejidad demuestra que la solucion es correcta en general y que entiendes el porque, no solo que coincide en unos ejemplos.

11. Un ejemplo es la verificacion de parentesis: si el codigo solo contara que haya la misma cantidad de aperturas y cierres sin revisar el anidamiento, pasaria casos como () y (()) pero estaria mal, y el error sobreviviria si el caso minimo no incluye un cruce como ([)]. Otro ejemplo es la conversion de base que no maneje el cero: daria una cadena vacia en vez de 0, y eso solo se nota si se prueba justo el caso del numero 0.

#### Bloque 4 (respuestas y experimentos 1-2)

1. El residuo, que es el resto de dividir n entre la base, es cada digito de la representacion empezando por el menos significativo. El cociente, que es n dividido por la base, es lo que queda por convertir, y se sigue dividiendo hasta llegar a 0. La pila guarda esos residuos en el orden en que salen, para luego sacarlos al reves y formar la cadena en el orden correcto.

2. Porque los residuos salen del menos significativo al mas significativo, es decir al reves de como va escrita la respuesta. Al apilarlos y despues sacarlos uno por uno, como la pila es LIFO se invierte ese orden y la cadena queda bien.

3. En la version recursiva el orden inverso lo arma sola la pila de llamadas del sistema, donde cada llamada apila su digito y al regresar se acomodan. En la iterativa lo haces tu con un Stack explicito y un while. El resultado termina siendo el mismo, como lo vi en el experimento donde todas las filas coinciden, y lo que cambia es quien controla el apilado.

4. divideParentheses busca donde termina el primer bloque de parentesis, es decir cual cierre corresponde a la apertura inicial. Va contando aperturas y cierres con el contador crc y se detiene cuando vuelve a 0. Ese punto parte la expresion en el bloque de adentro y lo que queda a la derecha, para revisar cada parte por separado.

5. La version recursiva solo mira los parentesis ( ) y deja de lado los corchetes y las llaves. Por eso no detecta un cruce como ([)]: en el experimento dio recursivo=true pero iterativo=false. La iterativa si distingue los tres tipos y los empareja con la pila, asi que alcanza a detectar el cruce. Esa es la limitacion, la recursiva no valida [] ni {}.

6. Porque cada vez que llega un cierre se compara contra el tope de la pila, que es la ultima apertura que sigue sin cerrar. Si no corresponden, o si la pila esta vacia, queda claro de una vez que esta mal y se devuelve false sin seguir leyendo el resto.

7. En parentesis la iterativa se siente mas natural y mas segura, porque maneja los tres tipos de delimitadores y detecta el error apenas aparece, mientras que la recursiva queda limitada a solo parentesis. En cambio en conversion de base la recursiva resulta mas expresiva, porque la inversion del orden sale sola con las llamadas, aunque la iterativa con pila explicita deja mas claro el mecanismo. Resumiendo, para parentesis prefiero la iterativa y para conversion la recursiva.

##### Experimento 1

| Numero | Base | Salida recursiva | Salida iterativa | Coinciden | Comentario |
|---|---|---|---|---|---|
| 10 | 2 | 1010 | 1010 | si | binario de 10 |
| 255 | 16 | FF | FF | si | hexadecimal, usa letras |
| 100 | 8 | 144 | 144 | si | octal |
| 31 | 2 | 11111 | 11111 | si | sale todo unos |
| 12345 | 10 | 12345 | 12345 | si | en base 10 queda igual |
| 0 | 16 | 0 | 0 | si | caso borde del cero |

##### Experimento 2

| Expresion | Recursivo | Iterativo | Coinciden | Que explica |
|---|---|---|---|---|
| (vacia) | true | true | si | una cadena vacia se considera balanceada |
| abc | true | true | si | no hay delimitadores, no hay nada que cerrar |
| (a+(b*c)) | true | true | si | parentesis bien anidados |
| (a+b | false | false | si | falta cerrar un parentesis, hay desbalance |
| ([)] | true | false | NO | la recursiva ignora [], no detecta el cruce; la iterativa si lo detecta |
| {[()]} | true | true | si | la recursiva solo ve (), pero el () interno esta balanceado; la iterativa empareja los tres tipos |
| ((a+b)*(c-d))/((e+f)*(g-h)) | true | true | si | parentesis balanceados aunque la cadena sea larga |
| a*(b+[c-d]) | true | true | si | parentesis y corchete cerrados correctamente |

#### Bloque 5 (respuestas y experimento 3)

1. EvaluationResult guarda dos cosas: value, que es el valor numerico final de la expresion como un double, y rpn, que es la cadena con la expresion en notacion postfija. Asi una sola llamada devuelve a la vez el resultado y la forma en que se reordeno la expresion.

2. Para que los espacios no estorben al recorrer la expresion caracter por caracter. removeSpaces deja la cadena limpia, de modo que 3 + 4 y 3+4 se tratan igual y el lector no tiene que andar saltando espacios en cada paso.

3. La funcion isUnaryMinus revisa que el caracter sea un menos, que despues venga un digito o un punto, y que antes haya un inicio de expresion o un operador o un parentesis que abre. Si esta al comienzo, o justo despues de ( + - * / ^, entonces ese menos es unario y forma parte del numero, no es una resta. Por eso en -3+5 se lee -3 como un solo numero.

4. Porque el factorial actua sobre un solo operando, que es el numero a su izquierda, a diferencia de la suma o la multiplicacion que necesitan dos. La restriccion es que ese operando debe ser un entero no negativo: el codigo redondea y si el numero no es entero lanza error, y factorialInt tambien falla si el numero es negativo.

5. Cada vez que se lee un numero se agrega a la rpn con appendRpn, y cada vez que un operador se saca de la pila para aplicarse tambien se agrega. Es decir la cadena rpn se va armando en el mismo recorrido en el que se calcula el valor, no en una segunda pasada al final.

6. orderBetween compara la prioridad del operador que esta en el tope de la pila con el simbolo que se esta leyendo y devuelve menor, igual o mayor. Menor quiere decir que el actual tiene mas prioridad y se apila; igual quiere decir que se cierra un par, como ( con ); mayor quiere decir que el del tope ya debe aplicarse antes de seguir. Esa relacion es la que decide la accion en cada paso.

7. Porque si la expresion no tiene sentido, devolver un numero cualquiera engañaria al usuario haciendole creer que el resultado es valido. Es preferible lanzar un error claro, como paso con 3+*4 que dio faltan operandos para el operador binario, para que quede claro que la entrada estaba mal en lugar de confiar en un valor inventado.

8. Que en una sola pasada obtienes el resultado y ademas una forma de revisar como se interpreto la expresion. La RPN sirve de evidencia del orden en que se aplicaron los operadores, asi se puede comprobar que la prioridad se respeto sin tener que volver a procesar toda la expresion.

##### Experimento 3

| Expresion | RPN esperada | RPN obtenida | Valor esperado o error | Valor obtenido o error | Explicacion |
|---|---|---|---|---|---|
| 3+4*2 | 3 4 2 * + | 3 4 2 * + | 11 | 11 | la multiplicacion se aplica antes que la suma |
| 5!+2^3 | 5 ! 2 3 ^ + | 5 ! 2 3 ^ + | 128 | 128 | el factorial y la potencia tienen mas prioridad |
| (1+2)*(3+4) | 1 2 + 3 4 + * | 1 2 + 3 4 + * | 21 | 21 | los parentesis cambian el orden natural |
| 2^(1+2) | 2 1 2 + ^ | 2 1 2 + ^ | 8 | 8 | primero se resuelve lo que esta entre parentesis |
| -3+5 | -3 5 + | -3 5 + | 2 | 2 | el menos se toma como unario, parte del numero |
| 3+*4 | error | (no aplica) | error | ERROR: faltan operandos para el operador binario | dos operadores seguidos dejan al + sin operandos |

#### Bloque 6 (respuestas y experimentos 4-5)

1. Significa que comparten fila, columna o alguna de las dos diagonales. En el codigo el operator== devuelve true si x es igual (misma fila), si y es igual (misma columna), si x+y coincide (una diagonal) o si x-y coincide (la otra diagonal). Con que se cumpla cualquiera de esas, ya hay conflicto.

2. Representa las reinas que ya estan colocadas, una por fila, en el orden en que se fueron poniendo. El tope es la reina de la fila mas reciente. Esa pila es el estado parcial de la solucion que se va armando y deshaciendo conforme avanza la busqueda.

3. Avanzar en columna, que es ++q.y, es probar la siguiente posicion dentro de la misma fila buscando una columna sin conflicto. Toca retroceder cuando ya no queda columna valida en esa fila, es decir cuando q.y llega a n, o cuando se completo el tablero: ahi se saca la ultima reina de la pila y se sigue probando desde su siguiente columna.

4. Porque mide cuanto trabajo real hizo el algoritmo, contando cada vez que se compara una reina candidata con las que ya estan puestas. No cuenta cuantas soluciones hay, sino cuanto costo tuvo llegar a ellas, asi se aprecia que tan dura se vuelve la busqueda a medida que crece n.

5. Que el algoritmo sigue contando soluciones y checks, pero ya no guarda las ubicaciones en placements. Sirve cuando solo interesa cuantas soluciones existen o medir el costo, sin gastar memoria almacenando cada tablero completo.

6. AVAILABLE es una celda libre por la que todavia no se ha pasado. ROUTE es una celda que forma parte del camino que se esta probando ahora. BACKTRACKED es una celda por la que se paso pero que resulto un callejon sin salida y se abandono. WALL es un muro, no se puede pisar.

7. incoming es la direccion por la que se entro a la celda y outgoing es la direccion hacia la que se esta intentando salir. outgoing va rotando entre Este, Sur, Oeste y Norte para ir probando los vecinos, mientras que incoming sirve para recordar de donde se vino.

8. Porque necesita recordar por donde ya paso para no repetir celdas y para poder deshacer cuando se atora. Al entrar marca la celda como ROUTE, y si esa celda no lleva a ningun lado la marca como BACKTRACKED y la saca de la pila. Sin marcar y desmarcar el algoritmo daria vueltas en circulo o no sabria que ese camino ya lo intento.

9. Comparten que los dos son backtracking: prueban una opcion y, si no lleva a la meta, retroceden y prueban otra, usando una pila para el estado parcial. Lo que cambia es como se representa ese estado: en N-Reinas la pila guarda las columnas de las reinas fila por fila, mientras que en el laberinto la pila guarda celdas y ademas cada celda lleva su propio estado y sus direcciones de entrada y salida.

##### Experimento 4

| n | Soluciones | Checks | Crece rapido o lento | Comentario |
|---|---|---|---|---|
| 4 | 2 | 84 | (base) | tablero chico, pocas soluciones |
| 5 | 10 | 405 | rapido | los checks suben casi 5 veces |
| 6 | 4 | 2016 | rapido | mas checks que n=5 pero menos soluciones |
| 7 | 40 | 9297 | rapido | el costo se sigue multiplicando |
| 8 | 92 | 46752 | rapido | crece muchisimo respecto a n=4 |

1. Que los checks crecen muy rapido, mucho mas que las soluciones. Cada vez que subo n en uno, los checks se multiplican mas o menos por 5 (84, 405, 2016, 9297, 46752). Es un crecimiento cercano a exponencial.

2. Porque una verificacion es un intento de revisar si una reina choca con las que ya estan, y la mayoria de esos intentos terminan en posiciones que se descartan. Las soluciones son solo los tableros completos validos. Por eso n=6 tiene mas checks que n=5 (2016 contra 405) pero menos soluciones (4 contra 10): mas trabajo no significa mas respuestas.

3. Aparece en conflictsWithAny: apenas una reina candidata choca con alguna ya colocada, se descarta esa columna y se avanza, sin seguir armando ese tablero. Cortar ahi los caminos que ya no pueden llevar a una solucion es justamente la poda, aunque en el codigo no tenga ese nombre.

##### Experimento 5

| Laberinto | Grilla | Inicio y destino | Longitud o ausencia | Evidencia de retroceso | Interpretacion |
|---|---|---|---|---|---|
| A camino claro | #####, #...#, #.#.#, #...#, ##### | (1,1) a (3,3) | camino de 5 celdas | 0 celdas con retroceso | el algoritmo fue directo, no se atoro en ningun punto |
| B sin salida | #####, #.#.#, #.#.#, #.#.#, ##### | (1,1) a (3,3) | sin camino | 3 celdas con retroceso | el inicio y el destino quedan en corredores separados por muros, explora y termina retrocediendo todo |
| C con retroceso | #####, #..##, #.###, #...#, ##### | (1,1) a (3,3) | camino de 5 celdas: (1,1)(2,1)(3,1)(3,2)(3,3) | 1 celda con retroceso en (1,2) | probo primero el callejon hacia el Este, retrocedio y tomo el camino correcto por el Sur |

#### Bloque 7 (respuestas y experimento 6)

1. Cada Queue<Customer> representa la fila de una ventanilla, es decir los clientes que estan esperando a ser atendidos en esa ventanilla, en orden de llegada. El vector windows junta todas las ventanillas, una cola por cada una.

2. bestWindow elige la ventanilla con la cola mas corta, recorriendo todas y quedandose con la de menor tamaño. Cuando hay empate se queda con la primera que encontro, porque solo cambia de opcion cuando aparece una estrictamente menor, ya que usa < y no <=.

3. Que el generador de numeros aleatorios parte de un valor fijo, asi que produce siempre la misma secuencia de llegadas y de tiempos. Eso hace la simulacion reproducible: con la misma semilla sale exactamente el mismo resultado, como se vio al repetir seed=42 y obtener de nuevo [3,2,2].

4. totalArrivals siempre debe ser mayor o igual que totalServed, porque nadie puede ser atendido sin haber llegado antes. Los que llegaron y no alcanzaron a ser atendidos se quedan esperando en las colas. En los datos se nota, por ejemplo 18 llegadas y solo 1 atendido, el resto sigue en fila.

5. Representa una foto del estado de las colas en cada instante now, guardando los tiempos restantes de los clientes en cada ventanilla. Sirve para ver como evoluciona la atencion paso a paso, no solamente el resultado final.

6. Porque a los clientes se les atiende en el orden en que llegaron, que es FIFO, y eso es justo lo que hace una cola. Una pila atenderia primero al ultimo que llego, lo cual seria injusto y no representaria una fila de banco real.

7. Introduce varias: un cliente, una vez puesto en una ventanilla, no se cambia de cola; los tiempos de atencion son aleatorios uniformes; a lo mas llega un cliente por instante; y no modela cosas como que alguien se canse y se vaya o que una ventanilla cierre. Es un modelo simplificado del mundo real.

8. Cambiaria a que ventanilla va cada cliente y, por lo tanto, como se reparten las colas. Por ejemplo una politica de turno rotativo o de asignacion al azar podria dejar unas ventanillas mas cargadas que otras. La cola mas corta en cambio tiende a equilibrar las filas, como se ve en que quedan parecidas, por ejemplo [6,6,5].

##### Experimento 6

| nWin | servTime | seed | totalArrivals | totalServed | Tamaño final de cada cola | Observacion |
|---|---|---|---|---|---|---|
| 3 | 10 | 42 | 7 | 0 | 3,2,2 | colas parejas, nadie alcanzo a ser atendido en 10 instantes |
| 5 | 10 | 42 | 7 | 0 | 2,2,1,1,1 | con mas ventanillas las mismas llegadas se reparten mas |
| 3 | 30 | 42 | 18 | 1 | 6,6,5 | mas duracion acumula mas llegadas y ya alcanza a atender a uno |
| 3 | 10 | 99 | 7 | 0 | 3,2,2 | con otra semilla el total coincidio en esta corrida corta |
| 3 | 10 | 42 (repetida) | 7 | 0 | 3,2,2 | misma semilla, mismo resultado exacto, es determinista |
| 3 | 30 | 99 | 26 | 0 | 9,9,8 | con duracion larga la semilla si cambia la congestion |
| 3 | 30 | 7 | 23 | 0 | 8,8,7 | otra semilla, otra cantidad de llegadas y otras colas |

1. La duracion, servTime, es la que mas influye en la congestion: al pasar de 10 a 30 instantes las llegadas y los tamaños de cola crecen bastante, de [3,2,2] hasta [6,6,5] o mas. Aumentar las ventanillas, en cambio, reparte las llegadas y baja el tamaño por cola.

2. No cambia nada, sale identico. Con nWin=3, servTime=10 y seed=42 dio [3,2,2] las dos veces. Eso confirma que la simulacion es determinista para una semilla dada.

3. Cambia la secuencia de llegadas y de tiempos de atencion, de modo que cambia la congestion. En las corridas de servTime=30 se ve claro: seed=42 dio 18 llegadas y colas [6,6,5], seed=99 dio 26 y [9,9,8], y seed=7 dio 23 y [8,8,7]. En la corrida corta de 10 instantes seed=42 y seed=99 coincidieron por casualidad, pero al alargar la simulacion las diferencias aparecen.

4. Que las colas quedan equilibradas entre si: en todos los casos los tamaños finales salen casi iguales, como [6,6,5] o [9,9,8], en vez de tener una ventanilla saturada y otras vacias. Ese balance es lo que se espera de mandar cada cliente a la fila mas corta. No garantiza el optimo global, pero reparte la carga de forma pareja.

#### Bloque 8 (respuesta final)

Cuando las pilas y las colas se usan solo como ADTs basicos, lo unico que importa es meter y sacar elementos: una pila apila y desapila, una cola encola y desencola. El cambio aparece cuando dejan de ser un simple almacen y se convierten en el mecanismo que controla como avanza un algoritmo, es decir cuando el orden en que los datos entran y salen es lo que dirige la solucion.

Sobre LIFO y FIFO, la pila trabaja en LIFO atendiendo siempre lo ultimo pendiente, y la cola en FIFO atendiendo por orden de llegada; esa diferencia de orden es justo lo que hace que cada una sirva para problemas distintos, no es un detalle menor sino la razon de elegir una u otra.

Sobre la recursion implicita frente a la estructura explicita, muchas soluciones recursivas usan sin que se vea la pila de llamadas del sistema, y reemplazarla por una pila explicita significa tomar el control de ese estado a mano; lo comprobe en la conversion de base, donde la version recursiva y la iterativa con Stack dieron exactamente el mismo resultado.

Sobre la evaluacion de expresiones, ahi una sola pila no alcanza, se necesitan dos, una para los operandos y otra para los operadores, y la pila de operadores es la que decide cuando aplicar cada operacion segun la prioridad; sin ese control ni la RPN ni el valor saldrian bien.

Sobre el backtracking, en N-Reinas y en el laberinto la pila guarda el estado parcial y permite deshacer cuando un camino no lleva a la meta; gracias a eso el algoritmo prueba, retrocede y vuelve a intentar, que es la esencia de la busqueda con retroceso.

Sobre la simulacion, en el banco las colas no resuelven un problema con una respuesta unica, sino que reproducen como evoluciona la atencion en el tiempo, respetando el orden de llegada de los clientes.

Sobre la correctitud experimental, no me quedo en que el programa corra, sino que lo respaldo con evidencia, como comparar la version recursiva contra la iterativa, contar los checks de N-Reinas o mirar las celdas de retroceso en el laberinto; esa evidencia es la que sostiene que la solucion de verdad funciona.

Comparando los cinco, la conversion de base usa una pila para invertir los digitos, los parentesis usan una pila para recordar las aperturas pendientes, N-Reinas y el laberinto usan una pila para el backtracking, y el banco usa colas para simular la espera. En conversion, parentesis, N-Reinas y laberinto la estructura controla como se resuelve un problema concreto, mientras que en el banco la estructura controla como se simula un proceso; en todos los casos, lo que cambia respecto a un ADT basico es que el orden de entrada y salida deja de ser un detalle y pasa a ser el motor de la solucion.

#### Autoevaluacion breve

- Que puedo defender con seguridad: la diferencia entre LIFO y FIFO y cuando conviene cada una, como la pila invierte el orden en la conversion de base, por que los parentesis necesitan guardar las aperturas pendientes, y como N-Reinas y el laberinto usan backtracking con una pila para probar y retroceder.

- Que todavia confundo: a veces me cuesta seguir al detalle como el evaluador decide con la tabla de precedencias cuando aplicar un operador, sobre todo en expresiones largas que mezclan factorial y potencia. Tambien me cuesta un poco rastrear a mano el orden exacto de los retrocesos en laberintos grandes.

- Que experimento me dio mejor evidencia: el de N-Reinas, porque ver como los checks crecen muchisimo (84, 405, 2016, 9297, 46752) mientras las soluciones no siguen ese ritmo deja muy clara la diferencia entre el trabajo hecho y las respuestas encontradas. El de laberintos, con el conteo de celdas de retroceso, tambien ayudo a ver el backtracking de forma concreta.

- Que evidencia usaria en una sustentacion: las tablas con datos reales, sobre todo que la conversion recursiva e iterativa coinciden en todos los casos, que ([)] da distinto entre recursivo e iterativo por la limitacion de la version recursiva, el crecimiento de los checks de N-Reinas, y que la simulacion del banco es determinista con la misma semilla pero cambia su congestion al cambiarla.
