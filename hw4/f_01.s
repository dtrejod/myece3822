	.file	"f_01.cc"
	.text
	.globl	_Z16ece_3822_add_sinff
	.type	_Z16ece_3822_add_sinff, @function
_Z16ece_3822_add_sinff:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movss	%xmm0, -20(%rbp)
	movss	%xmm1, -24(%rbp)
	cvtss2sd	-20(%rbp), %xmm0
	call	sin
	cvtsd2ss	%xmm0, %xmm2
	movss	%xmm2, -4(%rbp)
	cvtss2sd	-24(%rbp), %xmm0
	call	sin
	cvtsd2ss	%xmm0, %xmm3
	movss	%xmm3, -8(%rbp)
	movss	-4(%rbp), %xmm0
	addss	-8(%rbp), %xmm0
	movss	%xmm0, -12(%rbp)
	movss	-12(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_Z16ece_3822_add_sinff, .-_Z16ece_3822_add_sinff
	.ident	"GCC: (GNU) 5.2.0"
	.section	.note.GNU-stack,"",@progbits
