#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "v4s12/v4s12.h"

static bool test_2d_exact_reconstruction(void) {
    int32_t original[16] = {
        12, 45, 78, 23,
        90, 11, 34, 67,
        88, 99, 10, 55,
        44, 33, 22, 11
    };
    int32_t block[16];

    for (int i = 0; i < 16; ++i) {
        block[i] = original[i];
    }

    /* Transformada Directa 2D e Inversa con desplazamiento de bits (>> 4) */
    v4_transform_2d_4x4(block);
    v4_inverse_2d_4x4(block);

    /* Verificación de Mean Squared Error (MSE = 0.0000) */
    for (int i = 0; i < 16; ++i) {
        if (block[i] != original[i]) {
            printf("Error en reconstruccion: indice %d (esperado %d, obtenido %d)\n",
                   i, original[i], block[i]);
            return false;
        }
    }
    return true;
}

static bool test_s12_quantization(void) {
    /* Coordenada arbitraria 14 -> bloque 1 (12..23), residuo 2. 
       El residuo mas cercano en S12 = {1, 5, 7, 11} es 1. Coordenada proyectada = 13 */
    int32_t coord = 14;
    int32_t projected = s12_quantize_spline(coord);
    if (projected != 13) {
        printf("Error en cuantización S12: esperado 13, obtenido %d\n", projected);
        return false;
    }
    return true;
}

int main(void) {
    printf("Ejecutando verificacion matematica libv4s12...\n");

    if (!test_2d_exact_reconstruction()) {
        printf("[FALLO] Reconstruccion exacta MSE != 0\n");
        return 1;
    }
    printf("[OK] Reconstruccion exacta MSE = 0.0000 verificada.\n");

    if (!test_s12_quantization()) {
        printf("[FALLO] Proyeccion geométrica S12 fuera de rejilla.\n");
        return 1;
    }
    printf("[OK] Cuantizacion geométrica S12 verificada.\n");

    return 0;
}