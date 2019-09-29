/* AMD Zen gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 2019 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of either:

  * the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.

or

  * the GNU General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any
    later version.

or both in parallel, as here.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received copies of the GNU General Public License and the
GNU Lesser General Public License along with the GNU MP Library.  If not,
see https://www.gnu.org/licenses/.  */

#define GMP_LIMB_BITS 64
#define GMP_LIMB_BYTES 8

/* Disable use of slow functions.  FIXME: We should disable lib inclusion.  */
#undef HAVE_NATIVE_mpn_mul_2
#undef HAVE_NATIVE_mpn_addmul_2

/* 3700-4300 MHz Pinnacle Ridge */
/* FFT tuning limit = 0.5 M */
/* Generated by tuneup.c, 2019-09-24, gcc 8.3 */

#define MOD_1_NORM_THRESHOLD                 0  /* always */
#define MOD_1_UNNORM_THRESHOLD               0  /* always */
#define MOD_1N_TO_MOD_1_1_THRESHOLD          4
#define MOD_1U_TO_MOD_1_1_THRESHOLD          3
#define MOD_1_1_TO_MOD_1_2_THRESHOLD        13
#define MOD_1_2_TO_MOD_1_4_THRESHOLD        20
#define PREINV_MOD_1_TO_MOD_1_THRESHOLD      9
#define USE_PREINV_DIVREM_1                  1  /* native */
#define DIV_QR_1_NORM_THRESHOLD              1
#define DIV_QR_1_UNNORM_THRESHOLD        MP_SIZE_T_MAX  /* never */
#define DIV_QR_2_PI2_THRESHOLD              33
#define DIVEXACT_1_THRESHOLD                 0  /* always (native) */
#define BMOD_1_TO_MOD_1_THRESHOLD           22

#define DIV_1_VS_MUL_1_PERCENT             339

#define MUL_TOOM22_THRESHOLD                16
#define MUL_TOOM33_THRESHOLD                90
#define MUL_TOOM44_THRESHOLD               193
#define MUL_TOOM6H_THRESHOLD               232
#define MUL_TOOM8H_THRESHOLD               309

#define MUL_TOOM32_TO_TOOM43_THRESHOLD     107
#define MUL_TOOM32_TO_TOOM53_THRESHOLD     110
#define MUL_TOOM42_TO_TOOM53_THRESHOLD     109
#define MUL_TOOM42_TO_TOOM63_THRESHOLD     117
#define MUL_TOOM43_TO_TOOM54_THRESHOLD     160

#define SQR_BASECASE_THRESHOLD               0  /* always (native) */
#define SQR_TOOM2_THRESHOLD                 32
#define SQR_TOOM3_THRESHOLD                113
#define SQR_TOOM4_THRESHOLD                450
#define SQR_TOOM6_THRESHOLD                  0  /* always */
#define SQR_TOOM8_THRESHOLD                478

#define MULMID_TOOM42_THRESHOLD             44

#define MULMOD_BNM1_THRESHOLD               14
#define SQRMOD_BNM1_THRESHOLD               15

#define MUL_FFT_MODF_THRESHOLD             505  /* k = 5 */
#define MUL_FFT_TABLE3                                      \
  { {    505, 5}, {     21, 6}, {     12, 5}, {     25, 6}, \
    {     21, 7}, {     11, 6}, {     23, 7}, {     12, 6}, \
    {     25, 7}, {     13, 6}, {     28, 7}, {     15, 6}, \
    {     31, 7}, {     21, 8}, {     11, 7}, {     25, 8}, \
    {     13, 7}, {     29, 8}, {     15, 7}, {     31, 8}, \
    {     17, 7}, {     35, 8}, {     19, 7}, {     39, 8}, \
    {     21, 9}, {     11, 8}, {     29, 9}, {     15, 8}, \
    {     35, 9}, {     19, 8}, {     43, 9}, {     23, 8}, \
    {     47, 9}, {     27,10}, {     15, 9}, {     31, 8}, \
    {     63, 9}, {     43,10}, {     23, 9}, {     51,11}, \
    {     15,10}, {     31, 9}, {     67,10}, {     39, 9}, \
    {     83,10}, {     47, 9}, {     99,10}, {     55,11}, \
    {     31,10}, {     79,11}, {     47,10}, {    103,12}, \
    {     31,11}, {     63,10}, {    135,11}, {     79,10}, \
    {    167,11}, {     95,10}, {    191,12}, {     63,11}, \
    {    127,10}, {    255,11}, {    143,10}, {    287,11}, \
    {    159,12}, {     95,11}, {    191,10}, {    383,13}, \
    {   8192,14}, {  16384,15}, {  32768,16}, {  65536,17}, \
    { 131072,18}, { 262144,19}, { 524288,20}, {1048576,21}, \
    {2097152,22}, {4194304,23}, {8388608,24} }
#define MUL_FFT_TABLE3_SIZE 79
#define MUL_FFT_THRESHOLD                 5760

#define SQR_FFT_MODF_THRESHOLD             404  /* k = 5 */
#define SQR_FFT_TABLE3                                      \
  { {    404, 5}, {     21, 6}, {     11, 5}, {     23, 6}, \
    {     12, 5}, {     25, 6}, {     13, 5}, {     27, 6}, \
    {     25, 7}, {     13, 6}, {     29, 7}, {     15, 6}, \
    {     32, 7}, {     21, 8}, {     11, 7}, {     25, 8}, \
    {     13, 7}, {     28, 8}, {     15, 7}, {     32, 8}, \
    {     17, 7}, {     35, 8}, {     19, 7}, {     39, 8}, \
    {     21, 9}, {     11, 8}, {     23, 7}, {     47, 8}, \
    {     29, 9}, {     15, 8}, {     35, 9}, {     19, 8}, \
    {     41, 9}, {     23, 8}, {     47, 9}, {     27,10}, \
    {     15, 9}, {     31, 8}, {     63, 9}, {     43,10}, \
    {     23, 9}, {     51,11}, {     15,10}, {     31, 9}, \
    {     67,10}, {     39, 9}, {     79,10}, {     47, 9}, \
    {     95,10}, {     55,11}, {     31,10}, {     79,11}, \
    {     47,10}, {     95,12}, {     31,11}, {     63,10}, \
    {    135,11}, {     79,10}, {    159,11}, {     95,12}, \
    {     63,11}, {    127,10}, {    255, 9}, {    511,11}, \
    {    143,10}, {    287, 9}, {    575,11}, {    159,12}, \
    {     95,11}, {    191,10}, {    383,13}, {   8192,14}, \
    {  16384,15}, {  32768,16}, {  65536,17}, { 131072,18}, \
    { 262144,19}, { 524288,20}, {1048576,21}, {2097152,22}, \
    {4194304,23}, {8388608,24} }
#define SQR_FFT_TABLE3_SIZE 82
#define SQR_FFT_THRESHOLD                 4544

#define MULLO_BASECASE_THRESHOLD             0  /* always */
#define MULLO_DC_THRESHOLD                  71
#define MULLO_MUL_N_THRESHOLD            11278
#define SQRLO_BASECASE_THRESHOLD             8
#define SQRLO_DC_THRESHOLD                   0  /* never mpn_sqrlo_basecase */
#define SQRLO_SQR_THRESHOLD               8907

#define DC_DIV_QR_THRESHOLD                 80
#define DC_DIVAPPR_Q_THRESHOLD             236
#define DC_BDIV_QR_THRESHOLD                73
#define DC_BDIV_Q_THRESHOLD                 94

#define INV_MULMOD_BNM1_THRESHOLD           50
#define INV_NEWTON_THRESHOLD               276
#define INV_APPR_THRESHOLD                 238

#define BINV_NEWTON_THRESHOLD              303
#define REDC_1_TO_REDC_N_THRESHOLD          69

#define MU_DIV_QR_THRESHOLD               1499
#define MU_DIVAPPR_Q_THRESHOLD            1858
#define MUPI_DIV_QR_THRESHOLD              114
#define MU_BDIV_QR_THRESHOLD              1470
#define MU_BDIV_Q_THRESHOLD               1895

#define POWM_SEC_TABLE  5,29,78,257

#define GET_STR_DC_THRESHOLD                13
#define GET_STR_PRECOMPUTE_THRESHOLD        21
#define SET_STR_DC_THRESHOLD               608
#define SET_STR_PRECOMPUTE_THRESHOLD      1365

#define FAC_DSC_THRESHOLD                  224
#define FAC_ODD_THRESHOLD                    0  /* always */

#define MATRIX22_STRASSEN_THRESHOLD         23
#define HGCD2_DIV1_METHOD                    1  /* 8.93% faster than 3 */
#define HGCD_THRESHOLD                     109
#define HGCD_APPR_THRESHOLD                113
#define HGCD_REDUCE_THRESHOLD             3014
#define GCD_DC_THRESHOLD                   577
#define GCDEXT_DC_THRESHOLD                389
#define JACOBI_BASE_METHOD                   1  /* 15.00% faster than 3 */
