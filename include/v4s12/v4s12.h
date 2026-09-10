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