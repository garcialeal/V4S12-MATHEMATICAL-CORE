/*
 * V4S12-MATHEMATICAL-CORE - Multiplication-Free Discrete Geometry Engine
 *
 * Copyright (C) 2026 Antonio García Leal <support@v4s12.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "v4s12/v4s12.h"

static bool test_2d_exact_reconstruction(void) {
    const v4s12_int_t original[16] = {
        12, 45, 78, 23,
        90, 11, 34, 67,
        88, 99, 10, 55,
        44, 33, 22, 11
    };
    v4s12_int_t block[16];

    for (int i = 0; i < 16; ++i) {
        block[i] = original[i];
    }

    /* 2D Forward and Inverse Transform with bit shift (>> 4) */
    v4_transform_2d_4x4(block);
    v4_inverse_2d_4x4(block);

    /* Mean Squared Error Verification (MSE = 0.0000) */
    for (int i = 0; i < 16; ++i) {
        if (block[i] != original[i]) {
            printf("Reconstruction error at index %d: expected %d, got %d\n",
                   i, (int)original[i], (int)block[i]);
            return false;
        }
    }
    return true;
}

static bool test_s12_quantization(void) {
    /* Arbitrary coordinate 14 -> block 1 (12..23), residue 2. 
       The closest residue in S12 = {1, 5, 7, 11} is 1. Projected coordinate = 13 */
    v4s12_int_t coord = 14;
    v4s12_int_t projected = s12_quantize_spline(coord);
    if (projected != 13) {
        printf("S12 quantization error: expected 13, got %d\n", (int)projected);
        return false;
    }
    return true;
}

int main(void) {
    printf("Running libv4s12 mathematical verification...\n");

    if (!test_2d_exact_reconstruction()) {
        printf("[FAIL] Exact reconstruction MSE != 0\n");
        return 1;
    }
    printf("[OK] Exact reconstruction MSE = 0.0000 verified.\n");

    if (!test_s12_quantization()) {
        printf("[FAIL] S12 geometric projection off-grid.\n");
        return 1;
    }
    printf("[OK] S12 geometric quantization verified.\n");

    return 0;
}