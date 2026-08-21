/*
 * v4_zigzag.c - Implementation of V4-ZigZag Energy Reordering
 * Copyright (C) 2026 ANTONIO GARCÍA LEAL
 */

#include "v4s12/v4_zigzag.h"

void v4_zigzag_reorder(const int32_t in_block[16], int32_t out_vector[16]) {
    for (size_t i = 0; i < 16; ++i) {
        out_vector[i] = in_block[V4_ZIGZAG_MAP[i]];
    }
}