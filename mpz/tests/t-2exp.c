/* Test mpz_ui_pow_ui, mpz_fdiv_q, mpz_fdiv_q_2exp, mpz_fdiv_r,
   mpz_fdiv_r_2exp, and mpz_mul_2exp.

Copyright 1997, 1999, 2000, 2001 Free Software Foundation, Inc.

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

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "gmp.h"
#include "gmp-impl.h"

main (int argc, char **argv)
{
  mpz_t x, r1, r2, q1, q2, d, t;
  unsigned long n;
  unsigned long int c;
  int test;
  int ntests = 50000;
  gmp_randstate_t rands;
  mpz_t bs;
  unsigned long bsi, size_range;
  char *perform_seed;

  gmp_randinit (rands, GMP_RAND_ALG_LC, 64);

  perform_seed = getenv ("GMP_CHECK_RANDOMIZE");
  if (perform_seed != 0)
    {
      struct timeval tv;
      gettimeofday (&tv, NULL);
      gmp_randseed_ui (rands, tv.tv_sec + tv.tv_usec);
      printf ("PLEASE INCLUDE THIS SEED NUMBER IN ALL BUG REPORTS:\n");
      printf ("GMP_CHECK_RANDOMIZE is set--seeding with %ld\n",
	      tv.tv_sec + tv.tv_usec);
    }

  mpz_init (bs);

  if (argc == 2)
     ntests = atoi (argv[1]);

  mpz_init (x);
  mpz_init (q1);
  mpz_init (q2);
  mpz_init (r1);
  mpz_init (r2);
  mpz_init (d);
  mpz_init (t);

  for (test = 1; test <= ntests; test++)
    {
      mpz_urandomb (bs, rands, 32);
      size_range = mpz_get_ui (bs) % 8 + 2;

      mpz_urandomb (bs, rands, size_range);
      n = mpz_get_ui (bs);
      mpz_rrandomb (x, rands, n);
      mpz_urandomb (bs, rands, 1);
      bsi = mpz_get_ui (bs);
      if ((bsi & 1) != 0)
	mpz_neg (x, x);

      mpz_urandomb (bs, rands, 8);
      c = mpz_get_ui (bs);
      mpz_ui_pow_ui (d, (unsigned long) 2, c);

      mpz_fdiv_q (q1, x, d);
      mpz_fdiv_q_2exp (q2, x, c);
      mpz_fdiv_r (r1, x, d);
      mpz_fdiv_r_2exp (r2, x, c);

      if (mpz_cmp (q1, q2) != 0 || mpz_cmp (r1, r2) != 0)
	abort ();

      mpz_mul_2exp (t, q1, c);
      mpz_add (t, t, r1);
      if (mpz_cmp (t, x) != 0)
	abort ();

      if (mpz_cmp (r1, d) >= 0)
	abort ();
    }

  exit (0);
}
