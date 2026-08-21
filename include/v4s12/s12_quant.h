/*
 * s12_quant.h - Geometric Spline & Vector Quantization over S12 Lattice
 * Copyright (C) 2026 ANTONIO GARCÍA LEAL
 */

#ifndef V4S12_S12_QUANT_H
#define V4S12_S12_QUANT_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Base-12 coprime residue table S12 = {1, 5, 7, 11} (mod 12) */
static const uint8_t S12_RESIDUES[4] = {1, 5, 7, 11};

/**
 * @brief Geometric projection of spline coordinates onto the S12 grid.
 * Reduces state space from 12 to 4 states (44.21% bit-rate savings).
 * @param coord Original integer coordinate.
 * @return Projected coordinate matching closest S12 node (preserves C1 continuity).
 */
int32_t s12_quantize_spline(int32_t coord);

#ifdef __cplusplus
}
#endif

#endif /* V4S12_S12_QUANT_H */