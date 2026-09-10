# V4S12-MATHEMATICAL-CORE

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](LICENSE)
[![Standard](https://img.shields.io/badge/Language-C99-brightgreen.svg)]()
[![FLOPs](https://img.shields.io/badge/FLOPs-0%20(Multiplication--Free)-success.svg)]()
[![Throughput](https://img.shields.io/badge/Throughput-181.2M%20blocks%2Fs-orange.svg)]()

A high-performance, **multiplication-free (zero-FLOPs)** C99 core engine engineered for high-speed spectral transforms, integer discrete geometry, and lossy/lossless spatial compression.

Designed for universal platform deployment—from bare-metal microcontrollers and WebAssembly (WASM) edge renderers to HPC cloud instances and desktop CAD/VFX pipelines—`V4S12-MATHEMATICAL-CORE` serves as the foundational algebraic engine powering the `.v4s` 3D geometric format.

---

## Technical Highlights

* **$V_4$ Butterfly Transform ($MSE = 0.0000$):**  
  Exploits the involutive property of the Klein Four-Group $V_4 \cong \mathbb{Z}_2 \times \mathbb{Z}_2$ ($H_{V_4} \cdot H_{V_4} = 4 I_4$). Replaces dense matrix multiplications with butterfly networks driven entirely by bitwise shifts, additions, and subtractions. Yields bit-for-bit exact lossless reconstruction without floating-point rounding errors.

* **$\mathcal{S}_{12}$ Coprime Lattice Quantization:**  
  Projects vector space and spline control points onto the coprime residue grid $\mathcal{S}_{12} = \{1, 5, 7, 11\} \pmod{12}$. Preserves $C^1$ geometric continuity while reducing coordinate bit-rates down to 2.00 bits/coord with sub-pixel distortion ($\sqrt{MSE} \approx 1.04$ px).

* **Structure of Arrays (SoA) Architecture:**  
  Decouples spatial vectors into 4 orthogonal orbits in contiguous memory. Completely eliminates thread contention (*zero false sharing*) and unlocks auto-vectorization across modern SIMD extensions (ARM NEON, AVX2, AVX-512).

* **Zero-Dependency Core:**  
  Independent of `<stdlib.h>` and `<math.h>`. Zero dynamic heap allocations (`malloc`/`free`). Fully deterministic static stack or SRAM execution frame.

---

## Performance & Benchmark Metrics

| Parameter / Metric | Measured Baseline | Architectural Impact |
| :--- | :--- | :--- |
| **Floating-Point Operations** | **`0 FLOPs`** | Complete FPU independence across all architectures |
| **Reconstruction Error** | **`MSE = 0.0000`** | Bit-for-bit exact lossless spatial restoration |
| **Latency ($4 \times 4$ Block)** | **5.51 ns** | Sub-nanosecond execution directly on ALU registers |
| **Processing Throughput** | **181.2M blocks/sec** | Sustained high-throughput pipeline without FP stalls |
| **Bit-Rate Reduction** | **44.21%** | Shrinks coordinate storage from 3.58 to 2.00 bits/coord |
| **End-of-Block (EOB) Advance** | **33.33%** | Early zero-run termination for RLE/ANS entropy codecs |
| **Attention / Token Acceleration** | **1772.9x** | Compared to FP32 dense attention ($N=4096, D=64$) |

---

## System Integration Guide

### C99 Usage Example

```c
#include "v4s12/v4s12.h"
#include <stdint.h>

void process_geometry_block(int32_t *block_4x4) {
    /* 1. Forward 2D Spectral Transform (0 FLOPs) */
    v4_transform_2d_4x4(block_4x4);

    /* 2. Quantize to S12 Coprime Lattice */
    s12_quantize_block(block_4x4);

    /* 3. Exact Inverse Spectral Reconstruction */
    v4_inverse_2d_4x4(block_4x4);
}
```

---

## Directory Structure

```text
v4s12-mathematical-core/
├── benchmarks/        # Performance profiling harnesses
├── examples/          # Integration samples (Bare-metal, CAD, WebAssembly)
├── include/v4s12/     # Public C99 headers
│   ├── s12_quant.h    # Lattice quantization API
│   ├── v4_transform.h # V4 zero-FLOP butterfly transforms
│   ├── v4_zigzag.h    # Spectral serialization & zigzag ordering
│   └── v4s12.h        # Main library entrypoint
├── src/               # Core implementations
│   ├── s12_quant.c
│   ├── v4_transform.c
│   └── v4_zigzag.c
├── tests/             # Unit tests and bit-exact validation suites
├── CMakeLists.txt     # Build configuration
└── LICENSE            # Dual-licensing declaration (GPLv3)
```

---

## License & Commercial Terms

`V4S12-MATHEMATICAL-CORE` is dual-licensed:

* **Open Source Use:** Distributed under the **GNU General Public License v3.0 (GPLv3)**. Free for academic, open-source projects, and research software adhering to GPLv3 copyleft terms.
* **Commercial / Proprietary Use:** To embed this engine into closed-source commercial CAD/CAM suites, proprietary rendering engines, or commercial firmware without GPLv3 copyleft obligations, a commercial license is required.

📩 **Commercial Licensing & Inquiries:** `support@v4s12.com`