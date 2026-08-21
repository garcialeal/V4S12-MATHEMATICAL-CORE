/*
 * s12_quant.c - Implementation of S12 Lattice Quantization
 * Copyright (C) 2026 ANTONIO GARCÍA LEAL
 */

#include "v4s12/s12_quant.h"

int32_t s12_quantize_spline(int32_t coord) {
    int32_t base_block = coord / 12;
    int32_t rem = coord % 12;

    /* Handle negative modulo in standard C integer arithmetic */
    if (rem < 0) {
        rem += 12;
        base_block -= 1;
    }

    /* Find nearest coprime residue in S12 = {1, 5, 7, 11} */
    int32_t best_s = S12_RESIDUES[0];
    int32_t min_dist = (rem - best_s < 0) ? (best_s - rem) : (rem - best_s);

    for (size_t i = 1; i < 4; ++i) {
        int32_t s = S12_RESIDUES[i];
        int32_t dist = (rem - s < 0) ? (s - rem) : (rem - s);
        if (dist < min_dist) {
            min_dist = dist;
            best_s = s;
        }
    }

    return (base_block * 12) + best_s;
}