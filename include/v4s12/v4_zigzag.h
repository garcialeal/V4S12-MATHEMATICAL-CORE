/*
 * v4_zigzag.h - Topo-entropic V4-ZigZag Permutation Mapping
 * Copyright (C) 2026 ANTONIO GARCÍA LEAL
 */

#ifndef V4S12_V4_ZIGZAG_H
#define V4S12_V4_ZIGZAG_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Klein orbit energy mapping array */
static const uint8_t V4_ZIGZAG_MAP[16] = {
    0,  1,  4,  5,   /* DC & Primary Klein orbit 'e' */
    2,  3,  6,  7,   /* Klein orbit 'a' */
    8,  9,  12, 13,  /* Klein orbit 'b' */
    10, 11, 14, 15   /* Klein orbit 'ab' (high frequency) */
};

/**
 * @brief Entropic V4-ZigZag reordering to maximize EOB truncation.
 * @param in_block Quantized 4x4 matrix (16 elements).
 * @param out_vector Output array sorted by Klein orbit variance (16 elements).
 */
void v4_zigzag_reorder(const int32_t in_block[16], int32_t out_vector[16]);

#ifdef __cplusplus
}
#endif

#endif /* V4S12_V4_ZIGZAG_H */