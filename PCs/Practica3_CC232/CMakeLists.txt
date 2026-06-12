cmake_minimum_required(VERSION 3.20)
project(Practica3_CC232 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

# Headers propios + reuso de la libreria del curso (Semana 5: BinaryHeap).
set(PC3_INCLUDES
  "${CMAKE_CURRENT_SOURCE_DIR}/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/../../Libreria_cc232/Semana5/include"
)

# Programa principal (lee de stdin, formato CSES).
add_executable(pc3_main src/main.cpp)
target_include_directories(pc3_main PRIVATE ${PC3_INCLUDES})

# Demo ilustrativo (solucion ingenua, ejemplo fijo).
add_executable(demo_sliding_window_first demos/demo_sliding_window_first.cpp)

# Demo del reto: que mediana se usa con k par e impar.
add_executable(demo_par_impar demos/demo_par_impar.cpp)
target_include_directories(demo_par_impar PRIVATE ${PC3_INCLUDES})

# Pruebas: comparan la version eficiente contra la fuerza bruta.
add_executable(pc3_test tests/test_median.cpp)
target_include_directories(pc3_test PRIVATE ${PC3_INCLUDES})
add_test(NAME pc3_test COMMAND pc3_test)

# Pruebas de casos borde (k=1, k=n, todos iguales, k par, lazy deletion).
add_executable(pc3_test_borde tests/test_casos_borde.cpp)
target_include_directories(pc3_test_borde PRIVATE ${PC3_INCLUDES})
add_test(NAME pc3_test_borde COMMAND pc3_test_borde)

# Prueba del invariante (usa cumpleInvariante despues de cada ventana).
add_executable(pc3_test_invariante tests/test_invariante.cpp)
target_include_directories(pc3_test_invariante PRIVATE ${PC3_INCLUDES})
add_test(NAME pc3_test_invariante COMMAND pc3_test_invariante)

# Benchmark de tiempos (no es prueba de ctest: solo mide rendimiento).
add_executable(pc3_benchmark benchmark/benchmark_median.cpp)
target_include_directories(pc3_benchmark PRIVATE ${PC3_INCLUDES})
target_compile_options(pc3_benchmark PRIVATE -O2)
