/* AMD K6 gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 1991, 1993, 1994, 2000, 2001, 2002 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the GNU MP Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
MA 02111-1307, USA. */

#define BITS_PER_MP_LIMB 32
#define BYTES_PER_MP_LIMB 4


/* bsfl takes 12-27 cycles, put an average for uniform random numbers */
#ifndef COUNT_TRAILING_ZEROS_TIME
#define COUNT_TRAILING_ZEROS_TIME   14  /* cycles */
#endif


/* 333MHz K6-2, gcc 2.95.3 */

/* Generated by tuneup.c, 2001-11-29, gcc 3.0 */

#define KARATSUBA_MUL_THRESHOLD       20
#define TOOM3_MUL_THRESHOLD          129

#define BASECASE_SQR_THRESHOLD         0
#define KARATSUBA_SQR_THRESHOLD       30
#define TOOM3_SQR_THRESHOLD          186

#define SB_PREINV_THRESHOLD        MP_SIZE_T_MAX
#define DC_THRESHOLD                  69
#define POWM_THRESHOLD                91

#define GCD_ACCEL_THRESHOLD            3
#define GCDEXT_THRESHOLD              51

#define USE_PREINV_MOD_1               1  /* (native) */
#define DIVREM_2_THRESHOLD         MP_SIZE_T_MAX
#define DIVEXACT_1_THRESHOLD           0
#define MODEXACT_1_ODD_THRESHOLD       0

#define FFT_MUL_TABLE  { 496, 1184, 1920, 4608, 14336, 40960, 0 }
#define FFT_MODF_MUL_THRESHOLD       440
#define FFT_MUL_THRESHOLD           3840

#define FFT_SQR_TABLE  { 528, 1184, 2176, 5632, 14336, 40960, 0 }
#define FFT_MODF_SQR_THRESHOLD       472
#define FFT_SQR_THRESHOLD           3840
