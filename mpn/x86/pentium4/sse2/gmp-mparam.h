/* Intel Pentium-4 gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 1991, 1993, 1994, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

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


/* 1700 MHz Pentium 4 (socket 423) */

/* Generated by tuneup.c, 2003-02-12, gcc 2.95 */

#define MUL_KARATSUBA_THRESHOLD          27
#define MUL_TOOM3_THRESHOLD             290

#define SQR_BASECASE_THRESHOLD            0  /* always */
#define SQR_KARATSUBA_THRESHOLD          65
#define SQR_TOOM3_THRESHOLD             262

#define DIV_SB_PREINV_THRESHOLD       MP_SIZE_T_MAX  /* never */
#define DIV_DC_THRESHOLD                 44
#define POWM_THRESHOLD                  110

#define GCD_ACCEL_THRESHOLD               5
#define GCDEXT_THRESHOLD                 64
#define JACOBI_BASE_METHOD                1

#define USE_PREINV_DIVREM_1               0
#define USE_PREINV_MOD_1                  0
#define DIVREM_2_THRESHOLD            MP_SIZE_T_MAX  /* never */
#define DIVEXACT_1_THRESHOLD              0  /* always */
#define MODEXACT_1_ODD_THRESHOLD          0  /* always */

#define GET_STR_DC_THRESHOLD             13
#define GET_STR_PRECOMPUTE_THRESHOLD     14
#define SET_STR_THRESHOLD              2040

#define MUL_FFT_TABLE  { 656, 928, 2432, 5632, 14336, 40960, 0 }
#define MUL_FFT_MODF_THRESHOLD          488
#define MUL_FFT_THRESHOLD              3840

#define SQR_FFT_TABLE  { 752, 1440, 2432, 6656, 18432, 40960, 0 }
#define SQR_FFT_MODF_THRESHOLD          648
#define SQR_FFT_THRESHOLD              4864
