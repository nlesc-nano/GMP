! SuperSPARC __udiv_qrnnd division support, used from longlong.h.
! This is for SuperSPARC only, to compensate for its semi-functional
! udiv instruction.

! Copyright (C) 1993, 1994, 1996 Free Software Foundation, Inc.

! This file is part of the GNU MP Library.

! The GNU MP Library is free software; you can redistribute it and/or modify
! it under the terms of the GNU Library General Public License as published by
! the Free Software Foundation; either version 2 of the License, or (at your
! option) any later version.

! The GNU MP Library is distributed in the hope that it will be useful, but
! WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
! or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
! License for more details.

! You should have received a copy of the GNU Library General Public License
! along with the GNU MP Library; see the file COPYING.LIB.  If not, write to
! the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston,
! MA 02111-1307, USA.


! INPUT PARAMETERS
! rem_ptr	i0
! n1		i1
! n0		i2
! d		i3

include(`../config.m4')

ASM_START()
	RODATA
	ALIGN(8)
L(C0):	.double	0r4294967296
L(C1):	.double	0r2147483648

PROLOGUE(__udiv_qrnnd)
	save	%sp,-104,%sp
	st	%i1,[%fp-8]
	ld	[%fp-8],%f10
	sethi	%hi(L(C0)),%o7
	fitod	%f10,%f4
	ldd	[%o7+%lo(L(C0))],%f8
	cmp	%i1,0
	bge	L(248)
	mov	%i0,%i5
	faddd	%f4,%f8,%f4
L(248):
	st	%i2,[%fp-8]
	ld	[%fp-8],%f10
	fmuld	%f4,%f8,%f6
	cmp	%i2,0
	bge	L(249)
	fitod	%f10,%f2
	faddd	%f2,%f8,%f2
L(249):
	st	%i3,[%fp-8]
	faddd	%f6,%f2,%f2
	ld	[%fp-8],%f10
	cmp	%i3,0
	bge	L(250)
	fitod	%f10,%f4
	faddd	%f4,%f8,%f4
L(250):
	fdivd	%f2,%f4,%f2
	sethi	%hi(L(C1)),%o7
	ldd	[%o7+%lo(L(C1))],%f4
	fcmped	%f2,%f4
	nop
	fbge,a	L(251)
	fsubd	%f2,%f4,%f2
	fdtoi	%f2,%f2
	st	%f2,[%fp-8]
	b	L(252)
	ld	[%fp-8],%i4
L(251):
	fdtoi	%f2,%f2
	st	%f2,[%fp-8]
	ld	[%fp-8],%i4
	sethi	%hi(-2147483648),%g2
	xor	%i4,%g2,%i4
L(252):
	umul	%i3,%i4,%g3
	rd	%y,%i0
	subcc	%i2,%g3,%o7
	subxcc	%i1,%i0,%g0
	be	L(253)
	cmp	%o7,%i3

	add	%i4,-1,%i0
	add	%o7,%i3,%o7
	st	%o7,[%i5]
	ret
	restore
L(253):
	blu	L(246)
	mov	%i4,%i0
	add	%i4,1,%i0
	sub	%o7,%i3,%o7
L(246):
	st	%o7,[%i5]
	ret
	restore
EPILOGUE(__udiv_qrnnd)
