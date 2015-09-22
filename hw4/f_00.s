	.file	"f_00.cc"
	.section	.rodata
.LC0:
	.string	"Hello World"
.LC1:
	.string	"x =: "
.LC2:
	.string	"%f"
.LC3:
	.string	"y = : "
.LC4:
	.string	"sin(%f) + sin(%f) = %f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$.LC0, %edi
	call	puts
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	leaq	-8(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	scanf
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	leaq	-12(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	scanf
	movss	-12(%rbp), %xmm0
	movl	-8(%rbp), %eax
	movaps	%xmm0, %xmm1
	movl	%eax, -20(%rbp)
	movss	-20(%rbp), %xmm0
	call	_Z16ece_3822_add_sinff
	movd	%xmm0, %eax
	movl	%eax, -4(%rbp)
	cvtss2sd	-4(%rbp), %xmm2
	movss	-12(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm1
	movss	-8(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movl	$.LC4, %edi
	movl	$3, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 5.2.0"
	.section	.note.GNU-stack,"",@progbits
