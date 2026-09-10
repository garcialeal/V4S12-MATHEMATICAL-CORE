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
#include "v4s12/v4s12.h"

int main(void) {
    /* Control points of a vector curve / spline */
    const v4s12_int_t spline_coords[8] = {2, 8, 14, 21, 33, 40, 52, 65};

    printf("Compressing spline control points onto S12 lattice...\n");
    printf("Original -> S12 Quantized (State Space Reduced to S12 Residues)\n");

    for (int i = 0; i < 8; ++i) {
        v4s12_int_t original = spline_coords[i];
        v4s12_int_t quantized = s12_quantize_spline(original);
        printf("Coord [%d]: %2d -> %2d (Residue mod 12: %d)\n", 
               i, (int)original, (int)quantized, (int)(quantized % 12));
    }

    return 0;
}