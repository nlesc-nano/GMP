dnl  AMD64 mpn_addmul_1 and mpn_submul_1.

dnl  Copyright 2003, 2004, 2005, 2007, 2008 Free Software Foundation, Inc.

dnl  This file is part of the GNU MP Library.

dnl  The GNU MP Library is free software; you can redistribute it and/or modify
dnl  it under the terms of the GNU Lesser General Public License as published
dnl  by the Free Software Foundation; either version 3 of the License, or (at
dnl  your option) any later version.

dnl  The GNU MP Library is distributed in the hope that it will be useful, but
dnl  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
dnl  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
dnl  License for more details.

dnl  You should have received a copy of the GNU Lesser General Public License
dnl  along with the GNU MP Library.  If not, see http://www.gnu.org/licenses/.

include(`../config.m4')

C	     cycles/limb
C K8,K9:	 2.5
C K10:		 2.5
C P4:		14.9
C P6-15 (Core2): 5.09
C P6-28 (Atom):	21.3

C The inner loop of this code is the result of running a code generation and
C permutation tool suite written by David Harvey and Torbjorn Granlund.

C TODO:
C  * The inner loop is great, but the prologue and epilogue code was
C    quickly written.  Tune it!

C INPUT PARAMETERS
define(`rp',	 `%rdi')
define(`up',	 `%rsi')
define(`n_param',`%rdx')
define(`vl',	 `%rcx')

define(`n',	`%r11')

ifdef(`OPERATION_addmul_1',`
      define(`ADDSUB',        `add')
      define(`func',  `mpn_addmul_1')
')
ifdef(`OPERATION_submul_1',`
      define(`ADDSUB',        `sub')
      define(`func',  `mpn_submul_1')
')

MULFUNC_PROLOGUE(mpn_addmul_1 mpn_submul_1)

ASM_START()
	TEXT
	ALIGN(16)
PROLOGUE(func)
	mov	(up), %rax		C read first u limb early
	push	%rbx
	mov	n_param, %rbx		C move away n from rdx, mul uses it
	mul	vl
	mov	%rbx, %r11

	and	$3, R32(%rbx)
	jz	L(b0)
	cmp	$2, R32(%rbx)
	jz	L(b2)
	jg	L(b3)

L(b1):	dec	n
	jne	L(gt1)
	ADDSUB	%rax, (rp)
	jmp	L(ret)
L(gt1):	lea	8(up,n,8), up
	lea	-8(rp,n,8), rp
	neg	n
	xor	%r10, %r10
	xor	R32(%rbx), R32(%rbx)
	mov	%rax, %r9
	mov	(up,n,8), %rax
	mov	%rdx, %r8
	jmp	L(L1)

L(b0):	lea	(up,n,8), up
	lea	-16(rp,n,8), rp
	neg	n
	xor	%r10, %r10
	mov	%rax, %r8
	mov	%rdx, %rbx
	jmp	 L(L0)

L(b3):	lea	-8(up,n,8), up
	lea	-24(rp,n,8), rp
	neg	n
	mov	%rax, %rbx
	mov	%rdx, %r10
	jmp	L(L3)

L(b2):	lea	-16(up,n,8), up
	lea	-32(rp,n,8), rp
	neg	n
	xor	%r8, %r8
	xor	R32(%rbx), R32(%rbx)
	mov	%rax, %r10
	mov	24(up,n,8), %rax
	mov	%rdx, %r9
	jmp	L(L2)

	ALIGN(16)
L(top):	ADDSUB	%r10, (rp,n,8)
	adc	%rax, %r9
	mov	(up,n,8), %rax
	adc	%rdx, %r8
	mov	$0, %r10d
L(L1):	mul	vl
	ADDSUB	%r9, 8(rp,n,8)
	adc	%rax, %r8
	adc	%rdx, %rbx
L(L0):	mov	8(up,n,8), %rax
	mul	vl
	ADDSUB	%r8, 16(rp,n,8)
	adc	%rax, %rbx
	adc	%rdx, %r10
L(L3):	mov	16(up,n,8), %rax
	mul	vl
	ADDSUB	%rbx, 24(rp,n,8)
	mov	$0, %r8d		# zero
	mov	%r8, %rbx		# zero
	adc	%rax, %r10
	mov	24(up,n,8), %rax
	mov	%r8, %r9		# zero
	adc	%rdx, %r9
L(L2):	mul	vl
	add	$4, n
	js	 L(top)

	ADDSUB	%r10, (rp,n,8)
	adc	%rax, %r9
	adc	%r8, %rdx
	ADDSUB	%r9, 8(rp,n,8)
L(ret):	adc	$0, %rdx
	mov	%rdx, %rax

	pop	%rbx
	ret
EPILOGUE()
