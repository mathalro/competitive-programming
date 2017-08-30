	.file	"f.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.globl	X
	.bss
	.align 4
	.type	X, @object
	.size	X, 4
X:
	.zero	4
	.globl	Y
	.align 4
	.type	Y, @object
	.size	Y, 4
Y:
	.zero	4
	.globl	p
	.align 4
	.type	p, @object
	.size	p, 4
p:
	.zero	4
	.globl	st
	.align 32
	.type	st, @object
	.size	st, 65157184
st:
	.zero	65157184
	.text
	.globl	_Z7updateYiiiiiiiii
	.type	_Z7updateYiiiiiiiii, @function
_Z7updateYiiiiiiiii:
.LFB3536:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	%ecx, -32(%rbp)
	movl	%r8d, -36(%rbp)
	movl	%r9d, -40(%rbp)
	movl	-36(%rbp), %eax
	cmpl	-40(%rbp), %eax
	jne	.L2
	movl	-24(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jne	.L3
	movl	-32(%rbp), %eax
	cltq
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	imulq	$4036, %rdx, %rdx
	addq	%rdx, %rax
	movl	st(,%rax,4), %edx
	movl	32(%rbp), %eax
	addl	%eax, %edx
	movl	-32(%rbp), %eax
	cltq
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	imulq	$4036, %rcx, %rcx
	addq	%rcx, %rax
	movl	%edx, st(,%rax,4)
	jmp	.L1
.L3:
	movl	-20(%rbp), %eax
	leal	(%rax,%rax), %edx
	movl	-32(%rbp), %eax
	cltq
	movslq	%edx, %rdx
	imulq	$4036, %rdx, %rdx
	addq	%rdx, %rax
	movl	st(,%rax,4), %edx
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	leal	1(%rax), %ecx
	movl	-32(%rbp), %eax
	cltq
	movslq	%ecx, %rcx
	imulq	$4036, %rcx, %rcx
	addq	%rcx, %rax
	movl	st(,%rax,4), %eax
	addl	%eax, %edx
	movl	-32(%rbp), %eax
	cltq
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	imulq	$4036, %rcx, %rcx
	addq	%rcx, %rax
	movl	%edx, st(,%rax,4)
	jmp	.L1
.L2:
	movl	-40(%rbp), %eax
	movl	-36(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -4(%rbp)
	movl	24(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jg	.L6
	movl	-32(%rbp), %eax
	leal	(%rax,%rax), %edi
	movl	-4(%rbp), %r9d
	movl	-36(%rbp), %r8d
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %esi
	movl	-20(%rbp), %eax
	movl	32(%rbp), %ecx
	movl	%ecx, 16(%rsp)
	movl	24(%rbp), %ecx
	movl	%ecx, 8(%rsp)
	movl	16(%rbp), %ecx
	movl	%ecx, (%rsp)
	movl	%edi, %ecx
	movl	%eax, %edi
	call	_Z7updateYiiiiiiiii
	jmp	.L7
.L6:
	movl	-4(%rbp), %eax
	leal	1(%rax), %r10d
	movl	-32(%rbp), %eax
	addl	%eax, %eax
	leal	1(%rax), %edi
	movl	-40(%rbp), %r8d
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %esi
	movl	-20(%rbp), %eax
	movl	32(%rbp), %ecx
	movl	%ecx, 16(%rsp)
	movl	24(%rbp), %ecx
	movl	%ecx, 8(%rsp)
	movl	16(%rbp), %ecx
	movl	%ecx, (%rsp)
	movl	%r8d, %r9d
	movl	%r10d, %r8d
	movl	%edi, %ecx
	movl	%eax, %edi
	call	_Z7updateYiiiiiiiii
.L7:
	movl	-32(%rbp), %eax
	addl	%eax, %eax
	cltq
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	imulq	$4036, %rdx, %rdx
	addq	%rdx, %rax
	movl	st(,%rax,4), %edx
	movl	-32(%rbp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	cltq
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	imulq	$4036, %rcx, %rcx
	addq	%rcx, %rax
	movl	st(,%rax,4), %eax
	addl	%eax, %edx
	movl	-32(%rbp), %eax
	cltq
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	imulq	$4036, %rcx, %rcx
	addq	%rcx, %rax
	movl	%edx, st(,%rax,4)
.L1:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3536:
	.size	_Z7updateYiiiiiiiii, .-_Z7updateYiiiiiiiii
	.globl	_Z7updateXiiiiii
	.type	_Z7updateXiiiiii, @function
_Z7updateXiiiiii:
.LFB3537:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	%ecx, -32(%rbp)
	movl	%r8d, -36(%rbp)
	movl	%r9d, -40(%rbp)
	movl	-24(%rbp), %eax
	cmpl	-28(%rbp), %eax
	je	.L9
	movl	-28(%rbp), %eax
	movl	-24(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -4(%rbp)
	movl	-32(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jg	.L10
	movl	-20(%rbp), %eax
	leal	(%rax,%rax), %edi
	movl	-40(%rbp), %r8d
	movl	-36(%rbp), %esi
	movl	-32(%rbp), %ecx
	movl	-4(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%r8d, %r9d
	movl	%esi, %r8d
	movl	%eax, %esi
	call	_Z7updateXiiiiii
	jmp	.L9
.L10:
	movl	-4(%rbp), %eax
	leal	1(%rax), %esi
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	leal	1(%rax), %edi
	movl	-40(%rbp), %r8d
	movl	-36(%rbp), %ecx
	movl	-32(%rbp), %edx
	movl	-28(%rbp), %eax
	movl	%r8d, %r9d
	movl	%ecx, %r8d
	movl	%edx, %ecx
	movl	%eax, %edx
	call	_Z7updateXiiiiii
.L9:
	movl	Y(%rip), %edi
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %esi
	movl	-20(%rbp), %eax
	movl	-40(%rbp), %ecx
	movl	%ecx, 16(%rsp)
	movl	-36(%rbp), %ecx
	movl	%ecx, 8(%rsp)
	movl	-32(%rbp), %ecx
	movl	%ecx, (%rsp)
	movl	%edi, %r9d
	movl	$1, %r8d
	movl	$1, %ecx
	movl	%eax, %edi
	call	_Z7updateYiiiiiiiii
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3537:
	.size	_Z7updateXiiiiii, .-_Z7updateXiiiiii
	.globl	_Z6queryYiiiiii
	.type	_Z6queryYiiiiii, @function
_Z6queryYiiiiii:
.LFB3538:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movl	%edi, -36(%rbp)
	movl	%esi, -40(%rbp)
	movl	%edx, -44(%rbp)
	movl	%ecx, -48(%rbp)
	movl	%r8d, -52(%rbp)
	movl	%r9d, -56(%rbp)
	movl	-44(%rbp), %eax
	cmpl	-56(%rbp), %eax
	jg	.L13
	movl	-48(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jge	.L14
.L13:
	movl	$0, %eax
	jmp	.L15
.L14:
	movl	-44(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jl	.L16
	movl	-48(%rbp), %eax
	cmpl	-56(%rbp), %eax
	jg	.L16
	movl	-40(%rbp), %eax
	cltq
	movl	-36(%rbp), %edx
	movslq	%edx, %rdx
	imulq	$4036, %rdx, %rdx
	addq	%rdx, %rax
	movl	st(,%rax,4), %eax
	jmp	.L15
.L16:
	movl	-48(%rbp), %eax
	movl	-44(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -20(%rbp)
	movl	-40(%rbp), %eax
	leal	(%rax,%rax), %esi
	movl	-56(%rbp), %r8d
	movl	-52(%rbp), %edi
	movl	-20(%rbp), %ecx
	movl	-44(%rbp), %edx
	movl	-36(%rbp), %eax
	movl	%r8d, %r9d
	movl	%edi, %r8d
	movl	%eax, %edi
	call	_Z6queryYiiiiii
	movl	%eax, %ebx
	movl	-20(%rbp), %eax
	leal	1(%rax), %edi
	movl	-40(%rbp), %eax
	addl	%eax, %eax
	leal	1(%rax), %esi
	movl	-56(%rbp), %r8d
	movl	-52(%rbp), %ecx
	movl	-48(%rbp), %edx
	movl	-36(%rbp), %eax
	movl	%r8d, %r9d
	movl	%ecx, %r8d
	movl	%edx, %ecx
	movl	%edi, %edx
	movl	%eax, %edi
	call	_Z6queryYiiiiii
	addl	%ebx, %eax
.L15:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3538:
	.size	_Z6queryYiiiiii, .-_Z6queryYiiiiii
	.globl	_Z6queryXiiiiiii
	.type	_Z6queryXiiiiiii, @function
_Z6queryXiiiiiii:
.LFB3539:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movl	%edi, -36(%rbp)
	movl	%esi, -40(%rbp)
	movl	%edx, -44(%rbp)
	movl	%ecx, -48(%rbp)
	movl	%r8d, -52(%rbp)
	movl	%r9d, -56(%rbp)
	movl	-40(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jg	.L18
	movl	-44(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jge	.L19
.L18:
	movl	$0, %eax
	jmp	.L20
.L19:
	movl	-40(%rbp), %eax
	cmpl	-48(%rbp), %eax
	jl	.L21
	movl	-44(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jg	.L21
	movl	Y(%rip), %edx
	movl	-56(%rbp), %ecx
	movl	-36(%rbp), %eax
	movl	16(%rbp), %r9d
	movl	%ecx, %r8d
	movl	%edx, %ecx
	movl	$1, %edx
	movl	$1, %esi
	movl	%eax, %edi
	call	_Z6queryYiiiiii
	jmp	.L20
.L21:
	movl	-44(%rbp), %eax
	movl	-40(%rbp), %edx
	addl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -20(%rbp)
	movl	-36(%rbp), %eax
	leal	(%rax,%rax), %edi
	movl	-56(%rbp), %r9d
	movl	-52(%rbp), %r8d
	movl	-48(%rbp), %ecx
	movl	-20(%rbp), %edx
	movl	-40(%rbp), %eax
	movl	16(%rbp), %esi
	movl	%esi, (%rsp)
	movl	%eax, %esi
	call	_Z6queryXiiiiiii
	movl	%eax, %ebx
	movl	-20(%rbp), %eax
	leal	1(%rax), %esi
	movl	-36(%rbp), %eax
	addl	%eax, %eax
	leal	1(%rax), %edi
	movl	-56(%rbp), %r9d
	movl	-52(%rbp), %r8d
	movl	-48(%rbp), %edx
	movl	-44(%rbp), %eax
	movl	16(%rbp), %ecx
	movl	%ecx, (%rsp)
	movl	%edx, %ecx
	movl	%eax, %edx
	call	_Z6queryXiiiiiii
	addl	%ebx, %eax
.L20:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3539:
	.size	_Z6queryXiiiiiii, .-_Z6queryXiiiiiii
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	" %c"
.LC2:
	.string	"%d %d %d"
.LC3:
	.string	"%d %d %d %d"
.LC4:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3540:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	jmp	.L23
.L32:
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	scanf
	movl	$0, -4(%rbp)
	jmp	.L24
.L29:
	leaq	-25(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	scanf
	movzbl	-25(%rbp), %eax
	cmpb	$65, %al
	jne	.L25
	leaq	-8(%rbp), %rcx
	leaq	-12(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	scanf
	movl	-16(%rbp), %esi
	movl	-8(%rbp), %ecx
	movl	-12(%rbp), %edx
	movl	X(%rip), %eax
	movl	%esi, %r9d
	movl	%ecx, %r8d
	movl	%edx, %ecx
	movl	%eax, %edx
	movl	$1, %esi
	movl	$1, %edi
	call	_Z7updateXiiiiii
	jmp	.L26
.L25:
	leaq	-8(%rbp), %rsi
	leaq	-12(%rbp), %rcx
	leaq	-16(%rbp), %rdx
	leaq	-20(%rbp), %rax
	movq	%rsi, %r8
	movq	%rax, %rsi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	scanf
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	movl	-20(%rbp), %edx
	movl	-12(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L27
	leaq	-12(%rbp), %rdx
	leaq	-20(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt4swapIiEvRT_S1_
.L27:
	movl	-16(%rbp), %edx
	movl	-8(%rbp), %eax
	cmpl	%eax, %edx
	jle	.L28
	leaq	-8(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt4swapIiEvRT_S1_
.L28:
	movl	-8(%rbp), %ecx
	movl	-16(%rbp), %edi
	movl	-12(%rbp), %esi
	movl	-20(%rbp), %edx
	movl	X(%rip), %eax
	movl	%ecx, (%rsp)
	movl	%edi, %r9d
	movl	%esi, %r8d
	movl	%edx, %ecx
	movl	%eax, %edx
	movl	$1, %esi
	movl	$1, %edi
	call	_Z6queryXiiiiiii
	movl	p(%rip), %edx
	imull	%edx, %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
.L26:
	addl	$1, -4(%rbp)
.L24:
	movl	-24(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L29
.L23:
	movl	$p, %ecx
	movl	$Y, %edx
	movl	$X, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	scanf
	testl	%eax, %eax
	je	.L30
	movl	X(%rip), %eax
	testl	%eax, %eax
	je	.L30
	movl	$1, %eax
	jmp	.L31
.L30:
	movl	$0, %eax
.L31:
	testb	%al, %al
	jne	.L32
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3540:
	.size	main, .-main
	.section	.text._ZSt4swapIiEvRT_S1_,"axG",@progbits,_ZSt4swapIiEvRT_S1_,comdat
	.weak	_ZSt4swapIiEvRT_S1_
	.type	_ZSt4swapIiEvRT_S1_, @function
_ZSt4swapIiEvRT_S1_:
.LFB3551:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	movq	-32(%rbp), %rax
	movl	-4(%rbp), %edx
	movl	%edx, (%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3551:
	.size	_ZSt4swapIiEvRT_S1_, .-_ZSt4swapIiEvRT_S1_
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB3559:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L35
	cmpl	$65535, -8(%rbp)
	jne	.L35
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L35:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3559:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_X, @function
_GLOBAL__sub_I_X:
.LFB3560:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3560:
	.size	_GLOBAL__sub_I_X, .-_GLOBAL__sub_I_X
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_X
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
