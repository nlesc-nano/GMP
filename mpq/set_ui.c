/* mpq_set_ui(dest,ulong_num,ulong_den) -- Set DEST to the rational number
   ULONG_NUM/ULONG_DEN.

Copyright 1991, 1994, 1995, 2001, 2002 Free Software Foundation, Inc.

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

#include "gmp.h"
#include "gmp-impl.h"

void
mpq_set_ui (MP_RAT *dest, unsigned long int num, unsigned long int den)
{
  if (num == 0)
    {
      /* Canonicalize 0/n to 0/1.  */
      den = 1;
      dest->_mp_num._mp_size = 0;
    }
  else
    {
      dest->_mp_num._mp_d[0] = num;
      dest->_mp_num._mp_size = 1;
    }

  dest->_mp_den._mp_d[0] = den;
  dest->_mp_den._mp_size = (den != 0);
}
