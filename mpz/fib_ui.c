/* mpz_fib_ui(result, n) -- Set RESULT to the Nth Fibonacci number.

Copyright (C) 1998 Free Software Foundation, Inc.

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
MA 02111-1307, USA. */

#include "gmp.h"
#include "gmp-impl.h"

/* This is fast, but could be made somewhat faster and neater.
   The timing is somewhat fluctuating for even/odd sizes because
   of the extra hair used to save variables and operations.  Here
   are a few things one might want to address:
     1. Avoid using 4 intermediate variables in mpz_fib_bigcase.
     2. Call mpn functions directly.  Straightforward for these functions.
     3. Merge the three functions into one.
*/

/* Determine the needed storage for Fib(n).  */
#define FIB_SIZE(n) (((mp_size_t) ((n)*0.695)) / BITS_PER_MP_LIMB + 2)

static void mpz_fib_bigcase (mpz_t, mpz_t, unsigned long int);
static void mpz_fib_basecase (mpz_t, mpz_t, unsigned long int);

#define FIB_THRES 60

void
mpz_fib_ui (mpz_t r, unsigned long int n)
{
  if (n == 0)
    mpz_set_ui (r, 0);
  else
    {
      mpz_t t1;
      mpz_init (t1);
      if (n < FIB_THRES)
	mpz_fib_basecase (t1, r, n);
      else
	mpz_fib_bigcase (t1, r, n);
      mpz_clear (t1);
    }
}

static void
mpz_fib_basecase (mpz_t t1, mpz_t t2, unsigned long int n)
{
  unsigned long int m, i;

  mpz_set_ui (t1, 0);
  mpz_set_ui (t2, 1);
  m = n/2;
  for (i = 0; i < m; i++)
    {
      mpz_add (t1, t1, t2);
      mpz_add (t2, t1, t2);
    }
  if ((n & 1) == 0)
    {
      mpz_sub (t1, t2, t1);
      mpz_sub (t2, t2, t1);	/* trick: recover t1 value just overwritten */
    }
}

static void
mpz_fib_bigcase (mpz_t t1, mpz_t t2, unsigned long int n)
{
  unsigned long int n2;
  int ni, i;
  mpz_t x1, x2, u1, u2;

  ni = 0;
  for (n2 = n; n2 > FIB_THRES; n2 /= 2)
    ni++;

  mpz_fib_basecase (t1, t2, n2);

  mpz_init (x1);
  mpz_init (x2);
  mpz_init (u1);
  mpz_init (u2);

  for (i = ni - 1; i >= 0; i--)
    {
      mpz_mul_2exp (x1, t1, 1);
      mpz_mul_2exp (x2, t2, 1);

      mpz_add (x1, x1, t2);
      mpz_sub (x2, x2, t1);

      mpz_mul (u1, t2, x1);
      mpz_mul (u2, t1, x2);

      if (((n >> i) & 1) == 0)
	{
	  mpz_sub (t1, u1, u2);
	  mpz_set (t2, u1);
	}
      else
	{
	  mpz_set (t1, u1);
	  mpz_mul_2exp (t2, u1, 1);
	  mpz_sub (t2, t2, u2);
	}
    }

  mpz_clear (x1);
  mpz_clear (x2);
  mpz_clear (u1);
  mpz_clear (u2);
}
