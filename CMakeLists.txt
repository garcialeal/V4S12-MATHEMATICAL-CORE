cmake_minimum_required(VERSION 3.15)
project(v4s12-embedded VERSION 1.0.0 LANGUAGES C)

# Estándar C99 estricto
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Opciones de compilación
option(V4S12_BUILD_TESTS "Compilar la suite de pruebas unitarias" ON)
option(V4S12_BUILD_EXAMPLES "Compilar ejemplos de referencia" ON)
option(V4S12_BAREMETAL_MODE "Desactivar flags de entorno alojado (nostdlib/ffreestanding)" OFF)

# Configuración de Flags de Compilación
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -O3)
    if(V4S12_BAREMETAL_MODE)
        add_compile_options(-ffreestanding -nostdlib)
    endif()
endif()

# Librería Principal (v4s12)
add_library(v4s12 STATIC
    src/v4_transform.c
    src/v4_zigzag.c
    src/s12_quant.c
)

target_include_directories(v4s12 PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Pruebas Unitarias
if(V4S12_BUILD_TESTS)
    enable_testing()
    add_executable(test_exact_reconstruction tests/test_exact_reconstruction.c)
    target_link_libraries(test_exact_reconstruction PRIVATE v4s12)
    add_test(NAME ExactReconstruction COMMAND test_exact_reconstruction)
endif()

# Ejemplos de Referencia
if(V4S12_BUILD_EXAMPLES)
    add_executable(demo_baremetal examples/baremetal_arm_cortex_m.c)
    target_link_libraries(demo_baremetal PRIVATE v4s12)

    add_executable(demo_lidar_3d examples/lidar_3d_soa_demo.c)
    target_link_libraries(demo_lidar_3d PRIVATE v4s12)

    add_executable(demo_spline examples/spline_compression_demo.c)
    target_link_libraries(demo_spline PRIVATE v4s12)
endif()