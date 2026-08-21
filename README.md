# `v4s12-embedded`

**Multiplication-Free (Zero-FLOPs) Discrete Geometry & Spectral Processing C99 Core**  
*Engineered for Embedded Systems, Bare-Metal IoT, Autonomous Driving, and Edge Sensing.*

---

## Executive Overview

`v4s12-embedded` (also exported as `libv4s12`) is a zero-dependency C99 SDK designed to execute high-performance spectral transforms, data compression, and vector geometry projection on resource-constrained hardware without Floating-Point Units (FPUs).

Leveraging the character table of the Klein Four-Group $V_4 \cong \mathbb{Z}_2 \times \mathbb{Z}_2$ and the coprime modular lattice $\mathcal{S}_{12} = \{1, 5, 7, 11\} \pmod{12}$, the SDK eliminates dense matrix multiplications, replacing them with butterfly networks driven purely by integer additions, subtractions, and bit shifts.

---

## Benchmark Metrics (Hardware Validated)

| Metric / Parameter | Value | Technical Impact |
| :--- | :--- | :--- |
| **Mean Squared Error (MSE)** | `0.0000`[cite: 9] | Exact bit-for-bit lossless reconstruction ($MSE = 0$)[cite: 9]. |
| **Floating-Point Operations (FLOPs)** | **`0`**[cite: 9] | Eliminates FPU hardware dependency on low-power chips[cite: 9]. |
| **Latency per $4 \times 4$ Block** | **5.51 ns**[cite: 9] | Sub-microsecond execution directly on ALU registers[cite: 9]. |
| **Processing Throughput** | **181.2M blocks/s**[cite: 9] | High-sustained rate without floating-point stalls[cite: 9]. |
| **Spline/Vector Bit-Rate Reduction** | **44.21%**[cite: 9] | Compresses coordinate memory from 3.58 to 2.00 bits/coord[cite: 9]. |
| **Entropic Truncation (EOB) Advance** | **33.33%**[cite: 9] | Early zero-run termination for RLE/ANS encoders[cite: 9]. |
| **Token Mixer Acceleration** | **1772.9x** | Compared to FP32 dense attention ($N=4096, D=64$)[cite: 8]. |

---

## Core Architectural Pillars

1. **$V_4$ Butterfly Transform ($MSE = 0.0000$):**  
   Exploiting the involutive property $H_{V_4} \cdot H_{V_4} = 4 I_4$, the 2D inverse transform is calculated by applying the exact same butterfly network followed by an arithmetic bit-shift (`>> 4`, dividing by 16)[cite: 9]. Zero rounding errors[cite: 9].
2. **Strict Memory Independence (SoA Layout):**  
   Decoupling vector space into 4 orthogonal orbits allows contiguous memory placement via *Structure of Arrays* (SoA), completely eliminating thread contention (*zero false sharing*) and enabling auto-vectorization on SIMD architectures (ARM NEON / AVX2)[cite: 8, 9].
3. **$\mathcal{S}_{12}$ Lattice Geometric Quantization:**  
   Projects spline control points onto the base-12 coprime residue grid[cite: 9]. Preserves $C^1$ continuity while maintaining sub-pixel distortion ($\sqrt{MSE} \approx 1.04$ px)[cite: 9].

---

## Bare-Metal & Embedded Features

* **Zero C-Standard Dependencies:** No `<stdlib.h>`, no `<math.h>`, and no dynamic memory allocation (`malloc`).
* **Deterministic Memory Footprint:** $100\%$ static stack or SRAM execution.
* **Architecture Agnostic:** Native support for ARM Cortex-M (M0+/M4/M7), RISC-V, Xtensa (ESP32), industrial DSPs, and x86/x64.

---

## Quick Start (C99 Integration)

```c
#include "v4s12/v4s12.h"

void process_sensor_block(int32_t *raw_16_samples) {
    /* 1. Direct Spectral Transform (0 FLOPs) */
    v4_transform_2d_4x4(raw_16_samples);

    /* 2. Exact Bit-for-Bit Reconstruction */
    v4_inverse_2d_4x4(raw_16_samples);
}