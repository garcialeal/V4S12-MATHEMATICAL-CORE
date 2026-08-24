/*
 * lidar_3d_soa_demo.c - Demo for 3D LiDAR Point Cloud V4 Spectral Transform
 * Copyright (C) 2026 ANTONIO GARCÍA LEAL
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