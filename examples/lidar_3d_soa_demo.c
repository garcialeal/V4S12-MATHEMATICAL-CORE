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
    /* 4x4x4 voxel block in Structure of Arrays (SoA) format */
    v4s12_int_t voxel_block_soa[64] __attribute__((aligned(64)));

    /* Initialize mock 3D LiDAR intensity/distance voxel data */
    for (int i = 0; i < 64; ++i) {
        voxel_block_soa[i] = 100 + (i % 15);
    }

    printf("Executing 3D V4 spectral transform on 64-voxel SoA block...\n");

    /* Execute 3D Butterfly Kernel (X, Y, Z axes, 0 FLOPs) */
    v4_kernel_3d_soa(voxel_block_soa);

    printf("DC Component (Voxel 0): %d\n", (int)voxel_block_soa[0]);
    printf("High-frequency spectral voxel (Voxel 63): %d\n", (int)voxel_block_soa[63]);
    printf("3D LiDAR SoA processing complete.\n");

    return 0;
}