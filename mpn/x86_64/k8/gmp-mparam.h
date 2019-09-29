/* AMD K8 gmp-mparam.h -- Compiler/machine parameter header file.

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

#if 0
#undef mpn_sublsh_n
#define mpn_sublsh_n(rp,up,vp,n,c)					\
  (((rp) == (up)) ? mpn_submul_1 (rp, vp, n, CNST_LIMB(1) << (c))	\
   : MPN(mpn_sublsh_n)(rp,up,vp,n,c))
#endif

/* 2500 MHz K8 Brisbane */
/* FFT tuning limit = 0.5 M */
/* Generated by tuneup.c, 2019-09-28, gcc 8.3 */

#define MOD_1_NORM_THRESHOLD                 0  /* always */
#define MOD_1_UNNORM_THRESHOLD               0  /* always */
#define MOD_1N_TO_MOD_1_1_THRESHOLD          5
#define MOD_1U_TO_MOD_1_1_THRESHOLD          2
#define MOD_1_1_TO_MOD_1_2_THRESHOLD        14
#define MOD_1_2_TO_MOD_1_4_THRESHOLD        25
#define PREINV_MOD_1_TO_MOD_1_THRESHOLD      9
#define USE_PREINV_DIVREM_1                  1  /* native */
#define DIV_QR_1_NORM_THRESHOLD              1
#define DIV_QR_1_UNNORM_THRESHOLD        MP_SIZE_T_MAX  /* never */
#define DIV_QR_2_PI2_THRESHOLD           MP_SIZE_T_MAX  /* never */
#define DIVEXACT_1_THRESHOLD                 0  /* always (native) */
#define BMOD_1_TO_MOD_1_THRESHOLD           16

#define DIV_1_VS_MUL_1_PERCENT             309

#define MUL_TOOM22_THRESHOLD                32
#define MUL_TOOM33_THRESHOLD                97
#define MUL_TOOM44_THRESHOLD               166
#define MUL_TOOM6H_THRESHOLD               366
#define MUL_TOOM8H_THRESHOLD               478

#define MUL_TOOM32_TO_TOOM43_THRESHOLD      97
#define MUL_TOOM32_TO_TOOM53_THRESHOLD     153
#define MUL_TOOM42_TO_TOOM53_THRESHOLD     113
#define MUL_TOOM42_TO_TOOM63_THRESHOLD     184
#define MUL_TOOM43_TO_TOOM54_THRESHOLD     238

#define SQR_BASECASE_THRESHOLD               0  /* always (native) */
#define SQR_TOOM2_THRESHOLD                 40
#define SQR_TOOM3_THRESHOLD                 81
#define SQR_TOOM4_THRESHOLD                351
#define SQR_TOOM6_THRESHOLD                454
#define SQR_TOOM8_THRESHOLD                  0  /* always */

#define MULMID_TOOM42_THRESHOLD             36

#define MULMOD_BNM1_THRESHOLD               17
#define SQRMOD_BNM1_THRESHOLD               22

#define MUL_FFT_MODF_THRESHOLD             666  /* k = 5 */
#define MUL_FFT_TABLE3                                      \
  { {    666, 5}, {     21, 6}, {     11, 5}, {     23, 6}, \
    {     12, 5}, {     25, 6}, {     27, 7}, {     15, 6}, \
    {     31, 7}, {     18, 6}, {     37, 7}, {     29, 8}, \
    {     15, 7}, {     32, 8}, {     17, 7}, {     37, 8}, \
    {     19, 7}, {     40, 8}, {     21, 7}, {     43, 8}, \
    {     23, 7}, {     47, 8}, {     25, 7}, {     51, 8}, \
    {     31, 7}, {     63, 8}, {     37, 9}, {     19, 8}, \
    {     43, 9}, {     23, 8}, {     49, 7}, {    100, 8}, \
    {     51, 9}, {     27, 8}, {     57, 9}, {     31, 8}, \
    {     67, 9}, {     35, 8}, {     71, 9}, {     39, 8}, \
    {     81, 9}, {     43,10}, {     23, 9}, {     55, 8}, \
    {    113, 9}, {     59,10}, {     31, 9}, {     71, 8}, \
    {    145,10}, {     39, 9}, {     87,10}, {     47, 9}, \
    {     99,10}, {     55, 9}, {    119,11}, {     31,10}, \
    {     63, 9}, {    127,10}, {     71, 9}, {    143,10}, \
    {     87,11}, {     47,10}, {    111,12}, {     31,11}, \
    {     63,10}, {    143,11}, {     79,10}, {    167,11}, \
    {     95,10}, {    199,11}, {    111,12}, {     63,11}, \
    {    127,10}, {    255,11}, {    143,10}, {    287,11}, \
    {    175,12}, {     95,11}, {    191,10}, {    383,11}, \
    {    207,13}, {   8192,14}, {  16384,15}, {  32768,16}, \
    {  65536,17}, { 131072,18}, { 262144,19}, { 524288,20}, \
    {1048576,21}, {2097152,22}, {4194304,23}, {8388608,24} }
#define MUL_FFT_TABLE3_SIZE 92
#define MUL_FFT_THRESHOLD                10624

#define SQR_FFT_MODF_THRESHOLD             555  /* k = 5 */
#define SQR_FFT_TABLE3                                      \
  { {    555, 5}, {     21, 6}, {     11, 5}, {     23, 6}, \
    {     12, 5}, {     25, 6}, {     13, 5}, {     27, 6}, \
    {     14, 5}, {     29, 6}, {     29, 7}, {     15, 6}, \
    {     31, 7}, {     16, 6}, {     33, 7}, {     33, 8}, \
    {     17, 7}, {     37, 8}, {     19, 7}, {     40, 8}, \
    {     21, 7}, {     43, 8}, {     23, 7}, {     47, 8}, \
    {     25, 7}, {     51, 8}, {     29, 9}, {     15, 8}, \
    {     37, 9}, {     19, 8}, {     43, 9}, {     23, 8}, \
    {     51, 9}, {     27, 8}, {     55, 9}, {     31, 8}, \
    {     65, 9}, {     35, 8}, {     71, 9}, {     39, 8}, \
    {     79, 9}, {     43,10}, {     23, 9}, {     55,10}, \
    {     31, 9}, {     71,10}, {     39, 9}, {     83,10}, \
    {     47, 9}, {     99,10}, {     55,11}, {     31,10}, \
    {     87,11}, {     47,10}, {    111,12}, {     31,11}, \
    {     63,10}, {    143,11}, {     79,10}, {    167,11}, \
    {     95,10}, {    199,11}, {    111,12}, {     63,11}, \
    {    127, 9}, {    511,11}, {    143,10}, {    287, 9}, \
    {    575,11}, {    159,12}, {     95,11}, {    191,10}, \
    {    383, 9}, {    767,11}, {    207,10}, {    415,13}, \
    {   8192,14}, {  16384,15}, {  32768,16}, {  65536,17}, \
    { 131072,18}, { 262144,19}, { 524288,20}, {1048576,21}, \
    {2097152,22}, {4194304,23}, {8388608,24} }
#define SQR_FFT_TABLE3_SIZE 87
#define SQR_FFT_THRESHOLD                 7296

#define MULLO_BASECASE_THRESHOLD             0  /* always */
#define MULLO_DC_THRESHOLD                  85
#define MULLO_MUL_N_THRESHOLD            20964
#define SQRLO_BASECASE_THRESHOLD             9
#define SQRLO_DC_THRESHOLD                   0  /* never mpn_sqrlo_basecase */
#define SQRLO_SQR_THRESHOLD              14281

#define DC_DIV_QR_THRESHOLD                 96
#define DC_DIVAPPR_Q_THRESHOLD             294
#define DC_BDIV_QR_THRESHOLD                38
#define DC_BDIV_Q_THRESHOLD                176

#define INV_MULMOD_BNM1_THRESHOLD           62
#define INV_NEWTON_THRESHOLD               262
#define INV_APPR_THRESHOLD                 262

#define BINV_NEWTON_THRESHOLD              270
#define REDC_1_TO_REDC_2_THRESHOLD          35
#define REDC_2_TO_REDC_N_THRESHOLD          86

#define MU_DIV_QR_THRESHOLD               2089
#define MU_DIVAPPR_Q_THRESHOLD            1752
#define MUPI_DIV_QR_THRESHOLD              108
#define MU_BDIV_QR_THRESHOLD              1528
#define MU_BDIV_Q_THRESHOLD               1852

#define POWM_SEC_TABLE  1,22,194,827,2499

#define GET_STR_DC_THRESHOLD                17
#define GET_STR_PRECOMPUTE_THRESHOLD        30
#define SET_STR_DC_THRESHOLD               268
#define SET_STR_PRECOMPUTE_THRESHOLD      2259

#define FAC_DSC_THRESHOLD                 1240
#define FAC_ODD_THRESHOLD                   27

#define MATRIX22_STRASSEN_THRESHOLD         25
#define HGCD2_DIV1_METHOD                    3  /* 4.08% faster than 5 */
#define HGCD_THRESHOLD                     141
#define HGCD_APPR_THRESHOLD                181
#define HGCD_REDUCE_THRESHOLD             5010
#define GCD_DC_THRESHOLD                   566
#define GCDEXT_DC_THRESHOLD                487
#define JACOBI_BASE_METHOD                   1  /* 0.86% faster than 3 */
