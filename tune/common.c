/* Shared speed subroutines.  */

/*
Copyright (C) 1999, 2000 Free Software Foundation, Inc.

This file is part of the GNU MP Library.

The GNU MP Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Library General Public License as published by
the Free Software Foundation; either version 2 of the License, or (at your
option) any later version.

The GNU MP Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
License for more details.

You should have received a copy of the GNU Library General Public License
along with the GNU MP Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
MA 02111-1307, USA.
*/

#include <errno.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> /* for qsort */
#include <string.h>
#include <unistd.h>
#if 0
#include <sys/ioctl.h>
#endif

#include "gmp.h"
#include "gmp-impl.h"

#include "speed.h"

/* Change this to "#define TRACE(x) x" to get traces. */
#define TRACE(x)

#define numberof(x)   (sizeof (x) / sizeof ((x)[0]))
typedef int (*qsort_function_t) _PROTO ((const void *, const void *));

void
pentium_wbinvd(void)
{
#if 0
  {
    static int  fd = -2;

    if (fd == -2)
      {
        fd = open ("/dev/wbinvd", O_RDWR);
        if (fd == -1)
          perror ("open /dev/wbinvd");
      }

    if (fd != -1)
      ioctl (fd, 0, 0);
  }
#endif

#if 0
#define WBINVDSIZE  1024*1024*2
  {
    static char  *p = NULL;
    int   i, sum;

    if (p == NULL)
      p = malloc (WBINVDSIZE);

#if 0
    for (i = 0; i < WBINVDSIZE; i++)
      p[i] = i & 0xFF;
#endif

    sum = 0;
    for (i = 0; i < WBINVDSIZE; i++)
      sum += p[i];

    mpn_cache_fill_dummy (sum);
  }
#endif
}

static int
double_cmp_ptr (const double *p, const double *q)
{
  if (*p > *q)  return 1;
  if (*p < *q)  return -1;
  return 0;
}


/* Measure the speed of a given routine.

   The routine is run with enough repetitions to make it take at least
   speed_precision * speed_unittime.  This aims to minimize the effects of a
   limited accuracy time base and the overhead of the measuring itself.

   Measurements are made looking for 3 results within TOLERANCE of each
   other (or 2 for routines taking longer than 2 seconds).  This aims to get
   an accurate reading even if some runs are bloated by interrupts or task
   switches or whatever.

   The given (*fun)() is expected to run its function "s->reps" many times
   and return the total elapsed time measured using speed_starttime() and
   speed_endtime().  If the function doesn't support the given s->size or
   s->r, -1.0 should be returned.  See the various base routines below.  */

double
speed_measure (double (*fun) _PROTO ((struct speed_params *s)),
               struct speed_params *s)
{
#define TOLERANCE    1.005  /* 0.5% */

  struct speed_params  s_dummy;
  int     i, j, e;
  double  t[20];

  /* Use dummy parameters if caller doesn't provide any.  Only a few special
     "fun"s will cope with this, speed_noop() is one.  */
  if (s == NULL)
    {
      memset (&s_dummy, '\0', sizeof (s_dummy));
      s = &s_dummy;
    }
    
  s->reps = 1;
  for (i = 0; i < numberof (t); i++)
    {
      for (;;)
        {
          s->src_num = 0;
          s->dst_num = 0;

          t[i] = (*fun) (s);

          TRACE (printf("size=%ld reps=%u r=%d attempt=%d  %.9f\n", 
                        s->size, s->reps, s->r, i, t[i]));

          if (t[i] == -1.0)
            return -1.0;

          if (t[i] >= speed_unittime * speed_precision)
            break;

          /* go to a value of reps to make t[i] >= precision */
          s->reps = (unsigned) ceil (1.1 * s->reps
                                     * speed_unittime * speed_precision
                                     / MAX (t[i], speed_unittime));
        }
      t[i] /= s->reps;

      if (speed_precision == 0)
        return t[i];

      /* require 2 values within TOLERANCE when >= 2 secs, 3 when below */
      if (t[0] >= 2.0)
        e = 2;
      else
        e = 3;

      /* Look for e many t[]'s within TOLERANCE of each other to consider a
         valid measurement.  Return smallest among them.  */
      if (i >= e)
        {
          qsort (t, i, sizeof(t[0]), (qsort_function_t) double_cmp_ptr);
          for (j = e-1; j < i; j++)
            if (t[j] <= t[j-e+1] * TOLERANCE)
              return t[j-e+1];
        }
    } 

  fprintf (stderr, "speed_measure() could not get %d results within %.1f%%\n",
           e, (TOLERANCE-1.0)*100.0);
  return -1.0;
}


/* Read all of ptr,size to get it into the CPU memory cache.
  
   A call to mpn_cache_fill_dummy() is used to make sure the compiler
   doesn't optimize away the whole loop.  Using "volatile mp_limb_t sum"
   would work too, but the function call means we don't rely on every
   compiler actually implementing volatile properly.

   mpn_cache_fill_dummy() is in a separate source file to stop gcc thinking
   it can inline it.  */

void
mpn_cache_fill (mp_srcptr ptr, mp_size_t size)
{
  mp_limb_t  sum = 0;
  mp_size_t  i;

  for (i = 0; i < size; i++)
    sum += ptr[i];

  mpn_cache_fill_dummy(sum);
}


void
mpn_cache_fill_write (mp_ptr ptr, mp_size_t size)
{
  mpn_cache_fill (ptr, size);

#if 0
  mpn_random (ptr, size);
#endif

#if 0
  mp_size_t  i;

  for (i = 0; i < size; i++)
    ptr[i] = i;
#endif
}


void
speed_cache_fill (struct speed_params *s)
{
  int  i;

#if 0
  for (i = 0; i < s->dst_num; i++)
    printf ("dst %p  %ld\n", s->dst[i].ptr, s->dst[i].size);
  for (i = 0; i < s->src_num; i++)
    printf ("src %p  %ld\n", s->src[i].ptr, s->src[i].size);
#endif

  switch (s->cache) {
  case 0:
    for (i = 0; i < s->dst_num; i++)
      mpn_cache_fill_write (s->dst[i].ptr, s->dst[i].size);
    for (i = 0; i < s->src_num; i++)
      mpn_cache_fill (s->src[i].ptr, s->src[i].size);
    break;
  case 1:
    pentium_wbinvd();
    break;
  }
}


/* Return p advanced to the next multiple of "align" bytes.  "align" must be
   a power of 2.  Care is taken not to assume sizeof(int)==sizeof(pointer).  */
void *
align_pointer (void *p, size_t align)
{
  unsigned  d;
  d = ((unsigned) p) & (align-1);
  d = (d != 0 ? align-d : 0);
  p = (void *) (((char *) p) + d);
  return p;
}

/* Note that memory allocated with this function can never be freed, because
   the start address of the block allocated is discarded. */
void *
_mp_allocate_func_aligned (size_t bytes, size_t align)
{
  return align_pointer ((*_mp_allocate_func) (bytes + align-1), align);
}


void *
_mp_allocate_or_reallocate (void *ptr, size_t oldsize, size_t newsize)
{
  if (ptr == NULL)
    return (*_mp_allocate_func) (newsize);
  else
    return (*_mp_reallocate_func) (ptr, oldsize, newsize);
}


/* Adjust ptr to align to CACHE_LINE_SIZE plus "align".  ptr needs to have
   room for up to CACHE_LINE_SIZE-4 extra bytes.  */

mp_ptr
speed_tmp_alloc_adjust (void *ptr, mp_size_t align)
{
  /*
  printf("%p %ld -> %p %X %X\n", ptr, align,
         (mp_ptr) ptr 
         + ((align - ((mp_size_t) ptr >> 2)) &
            SPEED_TMP_ALLOC_ADJUST_MASK),
         ((mp_size_t) ptr >> 2) & SPEED_TMP_ALLOC_ADJUST_MASK,
         SPEED_TMP_ALLOC_ADJUST_MASK);
  */

  return (mp_ptr) ptr 
    + ((align - ((mp_size_t) ptr >> 2)) & SPEED_TMP_ALLOC_ADJUST_MASK);
}


/* The following are basic speed running routines for various gmp functions.
   Many are very similar and use speed.h macros.

   Each routine allocates it's own destination space for the result of the
   function, because only it can know what the function needs.

   speed_starttime() and speed_endtime() are put tight around the code to be
   measured.  Any setups are done outside the timed portion.

   Each routine is responsible for its own cache priming.
   speed_cache_fill() is a good way to do this, see examples in speed.h.
   One cache priming possibility, for CPUs with write-allocate cache, and
   functions that don't take too long, is to do one dummy call before timing
   so as to cache everything that gets used.  But speed_measure() runs a
   routine at least twice and will take the smaller time, so this might not
   be necessary.

   Data alignment will be important, for source, destination and temporary
   workspace.  A routine can align its destination and workspace.  Programs
   using the routines will ensure s->xp and s->yp are aligned.  Aligning
   onto a CACHE_LINE_SIZE boundary is suggested.  s->align_wp and
   s->align_wp2 should be respected where it makes sense to do so.
   SPEED_TMP_ALLOC is a good way to do this.

   A loop of the following form can be expected to turn into good assembler
   code on most CPUs, thereby minimizing overhead in the measurement.  It
   can always be assumed s->reps >= 1.

          i = s->reps
          do
            foo();
          while (--i != 0);

   Additional parameters might be added to "struct speed_params" in the
   future.  Routines should ignore anything they don't use.

   s->size can be used creatively, and s->xp and s->yp can be ignored.  For
   example, speed_mpz_fac_ui() uses s->size as n for the factorial.  s->r is
   just a user-supplied parameter.  speed_mpn_lshift() uses it as a shift,
   speed_mpn_mul_1() uses it as a multiplier.

*/


/* MPN_COPY etc can be macros, so the _CALL forms are necessary */
double
speed_MPN_COPY (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_COPY_CALL (MPN_COPY (wp, s->xp, s->size));
}
double
speed_MPN_COPY_INCR (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_COPY_CALL (MPN_COPY_INCR (wp, s->xp, s->size));
}
double
speed_MPN_COPY_DECR (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_COPY_CALL (MPN_COPY_DECR (wp, s->xp, s->size));
}
double
speed_memcpy (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_COPY_CALL
    (memcpy (wp, s->xp, s->size * BYTES_PER_MP_LIMB));
}


double
speed_mpn_addmul_1 (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_UNARY_1 (mpn_addmul_1);
}
double
speed_mpn_submul_1 (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_UNARY_1 (mpn_submul_1);
}


double
speed_mpn_mul_1 (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_UNARY_1 (mpn_mul_1);
}


double
speed_mpn_lshift (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_UNARY_1 (mpn_lshift);
}
double
speed_mpn_rshift (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_UNARY_1 (mpn_rshift);
}


double
speed_mpn_divmod_1 (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_UNARY_1_CALL (mpn_divmod_1 (wp, s->xp, s->size, s->r));
}
double
speed_mpn_divrem_1 (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_DIVREM_1 (mpn_divrem_1);
}
double
speed_mpn_mod_1 (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_MOD_1 (mpn_mod_1);
}


#if 0
double
speed_mpn_divexact_by3c (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_COPYC (mpn_divexact_by3c);
}
#endif
double
speed_mpn_divexact_by3 (struct speed_params *s)
{
  /* mpn_divexact_by3 is a macro, so the _CALL form is necessary */
  SPEED_ROUTINE_MPN_COPY_CALL(mpn_divexact_by3 (wp, s->xp, s->size));
}


double
speed_mpn_bz_divrem_n (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_BZ_DIVREM_N (mpn_bz_divrem_n);
}
double
speed_mpn_bz_divrem_sb (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_BZ_DIVREM_SB (mpn_sb_divrem_mn);
}
double
speed_mpn_bz_tdiv_qr (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_BZ_TDIV_QR (mpn_tdiv_qr);
}



double
speed_mpn_popcount (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_POPCOUNT (mpn_popcount);
}



double
speed_mpn_add_n (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_BINARY_N (mpn_add_n);
}
double
speed_mpn_sub_n (struct speed_params *s)
{
SPEED_ROUTINE_MPN_BINARY_N (mpn_sub_n);
}
double
speed_mpn_add_n_self (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_BINARY_N_SELF (mpn_add_n);
}
double
speed_mpn_add_n_inplace (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_BINARY_N_INPLACE (mpn_add_n);
}


/* mpn_and_n etc can be macros and so have to be handled with
   SPEED_ROUTINE_MPN_BINARY_N_CALL forms */
double
speed_mpn_and_n (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_BINARY_N_CALL (mpn_and_n (wp, s->xp, s->yp, s->size));
}
double
speed_mpn_andn_n (struct speed_params *s)
{
SPEED_ROUTINE_MPN_BINARY_N_CALL (mpn_andn_n (wp, s->xp, s->yp, s->size));
}
double
speed_mpn_nand_n (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_BINARY_N_CALL (mpn_nand_n (wp, s->xp, s->yp, s->size));
}
double
speed_mpn_ior_n (struct speed_params *s)
{
SPEED_ROUTINE_MPN_BINARY_N_CALL (mpn_ior_n (wp, s->xp, s->yp, s->size));
}
double
speed_mpn_iorn_n (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_BINARY_N_CALL (mpn_iorn_n (wp, s->xp, s->yp, s->size));
}
double
speed_mpn_nior_n (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_BINARY_N_CALL (mpn_nior_n (wp, s->xp, s->yp, s->size));
}
double
speed_mpn_xor_n (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_BINARY_N_CALL (mpn_xor_n (wp, s->xp, s->yp, s->size));
}
double
speed_mpn_xnor_n (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_BINARY_N_CALL (mpn_xnor_n (wp, s->xp, s->yp, s->size));
}


double
speed_mpz_fac_ui (struct speed_params *s)
{
  SPEED_ROUTINE_MPZ_UI (mpz_fac_ui);
}
double
speed_mpz_fib_ui (struct speed_params *s)
{
  SPEED_ROUTINE_MPZ_UI (mpz_fib_ui);
}


double
speed_mpn_mul_n (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_MUL_N (mpn_mul_n);
}
double
speed_mpn_sqr_n (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_SQR (mpn_sqr_n);
}
double
speed_mpn_mul_n_sqr (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_SQR_CALL (mpn_mul_n (wp, s->xp, s->xp, s->size), 1);
}

double
speed_mpn_mul_basecase (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_MUL_BASECASE(mpn_mul_basecase);
}
double
speed_mpn_sqr_basecase (struct speed_params *s)
{
  /* FIXME: size restrictions on some versions of sqr_basecase */
  SPEED_ROUTINE_MPN_SQR (mpn_sqr_basecase);
}

/* FIXME: size restrictions on kara */
double
speed_mpn_kara_mul_n (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_MUL_N_CALL
    (mpn_kara_mul_n (wp, s->xp, s->xp, s->size, tspace),
     MPN_KARA_MUL_N_TSIZE (s->size));
}
double
speed_mpn_kara_sqr_n (struct speed_params *s)
{
  SPEED_ROUTINE_MPN_SQR_CALL
    (mpn_kara_sqr_n (wp, s->xp, s->size, tspace),
     MPN_KARA_SQR_N_TSIZE (s->size));
}

/* FIXME: size restrictions on toom3 */
double
speed_mpn_toom3_mul_n (struct speed_params *s)
{
  SPEED_ROUTINE_GMPN_TOOM3_MUL_N (mpn_toom3_mul_n);
}
double
speed_mpn_toom3_sqr_n (struct speed_params *s)
{
  SPEED_ROUTINE_GMPN_TOOM3_SQR_N (mpn_toom3_sqr_n);
}


double
speed_noop (struct speed_params *s)
{
  unsigned  i;
  
  speed_starttime ();
  i = s->reps;
  do 
    noop ();
  while (--i != 0);
  return speed_endtime ();
}  

double
speed_noop_wxs (struct speed_params *s)
{
  mp_ptr   wp;
  unsigned i;
  double   t;
  TMP_DECL (marker);

  TMP_MARK (marker);
  wp = TMP_ALLOC_LIMBS (1);

  speed_starttime ();
  i = s->reps;
  do
    noop_wxs (wp, s->xp, s->size);
  while (--i != 0);
  t = speed_endtime ();

  TMP_FREE (marker);
  return t;
}  

double
speed_noop_wxys (struct speed_params *s)
{
  mp_ptr   wp;
  unsigned i;
  double   t;
  TMP_DECL (marker);

  TMP_MARK (marker);
  wp = TMP_ALLOC_LIMBS (1);

  speed_starttime ();
  i = s->reps;
  do
    noop_wxys (wp, s->xp, s->yp, s->size);
  while (--i != 0);
  t = speed_endtime ();

  TMP_FREE (marker);
  return t;
}  

