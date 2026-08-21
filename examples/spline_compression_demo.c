/*
 * spline_compression_demo.c - Demo for S12 Lattice Vector Spline Quantization
 * Copyright (C) 2026 ANTONIO GARCÍA LEAL
 */

#include <stdio.h>
#include <stdint.h>
#include "v4s12/v4s12.h"

int main(void) {
    /* Control points of a vector curve / spline */
    int32_t spline_coords[8] = {2, 8, 14, 21, 33, 40, 52, 65};

    printf("Compressing spline control points onto S12 lattice...\n");
    printf("Original -> S12 Quantized (State Space Reduced to S12 Residues)\n");

    for (int i = 0; i < 8; ++i) {
        int32_t original = spline_coords[i];
        int32_t quantized = s12_quantize_spline(original);
        printf("Coord [%d]: %2d -> %2d (Residue mod 12: %d)\n", 
               i, original, quantized, quantized % 12);
    }

    return 0;
}