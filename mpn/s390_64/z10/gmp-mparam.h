/* S/390-64 gmp-mparam.h -- Compiler/machine parameter header file.

Copyright 1991, 1993, 1994, 2000-2011, 2014 Free Software Foundation, Inc.

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

/* 4400 MHz IBM z10 */
/* FFT tuning limit = 5000000 */
/* Generated by tuneup.c, 2014-03-12, gcc 4.7 */

#define DIVREM_1_NORM_THRESHOLD              0  /* always */
#define DIVREM_1_UNNORM_THRESHOLD            4
#define MOD_1_1P_METHOD                      2
#define MOD_1_NORM_THRESHOLD                 0  /* always */
#define MOD_1_UNNORM_THRESHOLD               0  /* always */
#define MOD_1N_TO_MOD_1_1_THRESHOLD          7
#define MOD_1U_TO_MOD_1_1_THRESHOLD          8
#define MOD_1_1_TO_MOD_1_2_THRESHOLD        14
#define MOD_1_2_TO_MOD_1_4_THRESHOLD        23
#define PREINV_MOD_1_TO_MOD_1_THRESHOLD     29
#define USE_PREINV_DIVREM_1                  1
#define DIV_QR_1N_PI1_METHOD                 1
#define DIV_QR_1_NORM_THRESHOLD              2
#define DIV_QR_1_UNNORM_THRESHOLD        MP_SIZE_T_MAX  /* never */
#define DIV_QR_2_PI2_THRESHOLD           MP_SIZE_T_MAX  /* never */
#define DIVEXACT_1_THRESHOLD                 0  /* always */
#define BMOD_1_TO_MOD_1_THRESHOLD           56

#define MUL_TOOM22_THRESHOLD                 8
#define MUL_TOOM33_THRESHOLD                65
#define MUL_TOOM44_THRESHOLD                88
#define MUL_TOOM6H_THRESHOLD               125
#define MUL_TOOM8H_THRESHOLD               163

#define MUL_TOOM32_TO_TOOM43_THRESHOLD      58
#define MUL_TOOM32_TO_TOOM53_THRESHOLD      61
#define MUL_TOOM42_TO_TOOM53_THRESHOLD      57
#define MUL_TOOM42_TO_TOOM63_THRESHOLD      62
#define MUL_TOOM43_TO_TOOM54_THRESHOLD      82

#define SQR_BASECASE_THRESHOLD               0  /* always (native) */
#define SQR_TOOM2_THRESHOLD                 12
#define SQR_TOOM3_THRESHOLD                 89
#define SQR_TOOM4_THRESHOLD                130
#define SQR_TOOM6_THRESHOLD                189
#define SQR_TOOM8_THRESHOLD                260

#define MULMID_TOOM42_THRESHOLD             24

#define MULMOD_BNM1_THRESHOLD                9
#define SQRMOD_BNM1_THRESHOLD                9

#define MUL_FFT_MODF_THRESHOLD             252  /* k = 5 */
#define MUL_FFT_TABLE3                                      \
  { {    252, 5}, {      9, 6}, {      5, 5}, {     11, 6}, \
    {      6, 5}, {     13, 6}, {      7, 5}, {     15, 6}, \
    {     11, 7}, {      6, 6}, {     13, 7}, {      7, 6}, \
    {     15, 7}, {      9, 8}, {      5, 7}, {     13, 8}, \
    {      7, 7}, {     15, 8}, {      9, 7}, {     19, 8}, \
    {     11, 7}, {     23, 8}, {     13, 9}, {      7, 8}, \
    {     15, 7}, {     31, 8}, {     19, 9}, {     11, 8}, \
    {     23,10}, {      7, 9}, {     15, 8}, {     33, 9}, \
    {     27,10}, {     15, 9}, {     39,10}, {     23,11}, \
    {     15,10}, {     31, 9}, {     67,10}, {     39, 9}, \
    {     79, 8}, {    159,10}, {     47,11}, {     31,10}, \
    {     63, 9}, {    127, 8}, {    255,10}, {     71, 9}, \
    {    143, 8}, {    287, 7}, {    575,10}, {     79, 9}, \
    {    159,11}, {     47,12}, {     31,11}, {     63,10}, \
    {    127, 9}, {    255, 8}, {    511,10}, {    143, 9}, \
    {    287, 8}, {    575,11}, {     79,10}, {    159, 9}, \
    {    319,10}, {    175, 9}, {    351, 8}, {    703, 7}, \
    {   1407, 6}, {   2815,10}, {    191, 9}, {    383, 8}, \
    {    767, 9}, {    415,10}, {    223, 9}, {    447, 8}, \
    {    895,12}, {     63,11}, {    127,10}, {    255, 9}, \
    {    511,11}, {    143,10}, {    287, 9}, {    575, 8}, \
    {   1151,11}, {    159,10}, {    319, 9}, {    639,11}, \
    {    175,10}, {    351, 9}, {    703, 8}, {   1407, 7}, \
    {   2815,11}, {    191,10}, {    383, 9}, {    767,10}, \
    {    415,11}, {    223,10}, {    447, 9}, {    895, 8}, \
    {   1791,11}, {    239,13}, {     63,12}, {    127,11}, \
    {    255,10}, {    511,11}, {    287,10}, {    575, 9}, \
    {   1151,12}, {    159,11}, {    319,10}, {    703, 9}, \
    {   1407, 8}, {   2815,12}, {    191,11}, {    383,10}, \
    {    767,11}, {    415,10}, {    831,12}, {    223,11}, \
    {    447,10}, {    895, 9}, {   1791, 8}, {   3583,11}, \
    {    479,10}, {    959, 9}, {   1919,13}, {    127,12}, \
    {    255,11}, {    511,12}, {    287,11}, {    575,10}, \
    {   1151,12}, {    319,11}, {    639,12}, {    351,11}, \
    {    703,10}, {   1407, 9}, {   2815,13}, {    191,12}, \
    {    383,11}, {    767,12}, {    415,11}, {    831,10}, \
    {   1663,12}, {    447,11}, {    895,10}, {   1791, 9}, \
    {   3583,12}, {    479,11}, {    959,10}, {   1919,14}, \
    {    127,13}, {    255,12}, {    511,11}, {   1023,12}, \
    {    575,11}, {   1151,13}, {    319,12}, {    639,11}, \
    {   1279,12}, {    703,11}, {   1407,10}, {   2815,13}, \
    {    383,12}, {    767,11}, {   1535,12}, {    831,11}, \
    {   1663,13}, {    447,12}, {    895,11}, {   1791,10}, \
    {   3583,12}, {    959,11}, {   1919,14}, {    255,13}, \
    {    511,12}, {   1023,13}, {    575,12}, {   1151,13}, \
    {   8192,14}, {  16384,15}, {  32768,16}, {  65536,17}, \
    { 131072,18}, { 262144,19}, { 524288,20}, {1048576,21}, \
    {2097152,22}, {4194304,23}, {8388608,24} }
#define MUL_FFT_TABLE3_SIZE 191
#define MUL_FFT_THRESHOLD                 1728

#define SQR_FFT_MODF_THRESHOLD             212  /* k = 5 */
#define SQR_FFT_TABLE3                                      \
  { {    212, 5}, {      7, 4}, {     15, 5}, {     11, 6}, \
    {      6, 5}, {     13, 6}, {      7, 5}, {     15, 6}, \
    {     13, 7}, {      7, 6}, {     15, 7}, {     13, 8}, \
    {      7, 7}, {     16, 8}, {      9, 7}, {     19, 8}, \
    {     11, 7}, {     23, 8}, {     13, 9}, {      7, 8}, \
    {     19, 9}, {     11, 8}, {     23,10}, {      7, 9}, \
    {     15, 8}, {     31, 9}, {     19, 8}, {     39, 9}, \
    {     23,10}, {     15, 9}, {     39,10}, {     23,11}, \
    {     15,10}, {     31, 9}, {     63,10}, {     39, 9}, \
    {     79,10}, {     47,11}, {     31,10}, {     63, 9}, \
    {    127, 8}, {    255,10}, {     71, 9}, {    143, 8}, \
    {    287, 7}, {    575,10}, {     79,11}, {     47,12}, \
    {     31,11}, {     63,10}, {    127, 9}, {    255, 8}, \
    {    511,10}, {    143, 9}, {    287, 8}, {    575,11}, \
    {     79,10}, {    159, 9}, {    319, 8}, {    639,10}, \
    {    175, 9}, {    351, 8}, {    703, 7}, {   1407,11}, \
    {     95,10}, {    191, 9}, {    383, 8}, {    767,10}, \
    {    207,11}, {    111,12}, {     63,11}, {    127,10}, \
    {    255, 9}, {    511,11}, {    143,10}, {    287, 9}, \
    {    575, 8}, {   1151,11}, {    159,10}, {    319, 9}, \
    {    639,11}, {    175,10}, {    351, 9}, {    703, 8}, \
    {   1407,11}, {    191,10}, {    383, 9}, {    767,11}, \
    {    223,13}, {     63,12}, {    127,11}, {    255,10}, \
    {    511,11}, {    287,10}, {    575, 9}, {   1151,12}, \
    {    159,11}, {    319,10}, {    639,11}, {    351,10}, \
    {    703, 9}, {   1407, 8}, {   2815,12}, {    191,11}, \
    {    383,10}, {    767,11}, {    415,12}, {    223,11}, \
    {    447,10}, {    895, 9}, {   1791,11}, {    479,13}, \
    {    127,12}, {    255,11}, {    511,12}, {    287,11}, \
    {    575,10}, {   1151,12}, {    319,11}, {    639,12}, \
    {    351,11}, {    703,10}, {   1407, 9}, {   2815,13}, \
    {    191,12}, {    383,11}, {    767,12}, {    415,11}, \
    {    831,10}, {   1663,12}, {    447,11}, {    895,10}, \
    {   1791,12}, {    479,11}, {    959,14}, {    127,13}, \
    {    255,12}, {    511,11}, {   1023,12}, {    575,11}, \
    {   1151,13}, {    319,12}, {    639,11}, {   1279,12}, \
    {    703,11}, {   1407,10}, {   2815,13}, {    383,12}, \
    {    767,11}, {   1535,12}, {    831,11}, {   1663,13}, \
    {    447,12}, {    895,11}, {   1791,10}, {   3583,12}, \
    {    959,11}, {   1919,14}, {    255,13}, {    511,12}, \
    {   1023,13}, {    575,12}, {   1151,13}, {   8192,14}, \
    {  16384,15}, {  32768,16}, {  65536,17}, { 131072,18}, \
    { 262144,19}, { 524288,20}, {1048576,21}, {2097152,22}, \
    {4194304,23}, {8388608,24} }
#define SQR_FFT_TABLE3_SIZE 174
#define SQR_FFT_THRESHOLD                 1728

#define MULLO_BASECASE_THRESHOLD             0  /* always */
#define MULLO_DC_THRESHOLD                  34
#define MULLO_MUL_N_THRESHOLD             3176

#define DC_DIV_QR_THRESHOLD                 39
#define DC_DIVAPPR_Q_THRESHOLD             151
#define DC_BDIV_QR_THRESHOLD                44
#define DC_BDIV_Q_THRESHOLD                107

#define INV_MULMOD_BNM1_THRESHOLD           14
#define INV_NEWTON_THRESHOLD               163
#define INV_APPR_THRESHOLD                 154

#define BINV_NEWTON_THRESHOLD              171
#define REDC_1_TO_REDC_N_THRESHOLD          46

#define MU_DIV_QR_THRESHOLD                792
#define MU_DIVAPPR_Q_THRESHOLD             807
#define MUPI_DIV_QR_THRESHOLD               81
#define MU_BDIV_QR_THRESHOLD               654
#define MU_BDIV_Q_THRESHOLD                792

#define POWM_SEC_TABLE  3,19,194,946,2424

#define MATRIX22_STRASSEN_THRESHOLD         17
#define HGCD_THRESHOLD                     117
#define HGCD_APPR_THRESHOLD                145
#define HGCD_REDUCE_THRESHOLD             1329
#define GCD_DC_THRESHOLD                   318
#define GCDEXT_DC_THRESHOLD                265
#define JACOBI_BASE_METHOD                   4

#define GET_STR_DC_THRESHOLD                17
#define GET_STR_PRECOMPUTE_THRESHOLD        35
#define SET_STR_DC_THRESHOLD              1015
#define SET_STR_PRECOMPUTE_THRESHOLD      2047

#define FAC_DSC_THRESHOLD                  330
#define FAC_ODD_THRESHOLD                   23
