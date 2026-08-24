/*
 * v4s12.h - Master Unified Header for sdk-v4s12
 * Copyright (C) 2026 ANTONIO GARCÍA LEAL
 */

#ifndef V4S12_H
#define V4S12_H

#include <stdint.h>
#include <stddef.h>

#ifdef V4S12_HIGH_PRECISION
    typedef int64_t v4s12_int_t;
#else
    typedef int32_t v4s12_int_t;
#endif

#include "v4s12/v4_transform.h"
#include "v4s12/v4_zigzag.h"
#include "v4s12/s12_quant.h"

#endif /* V4S12_H */