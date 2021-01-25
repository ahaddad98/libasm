		global _ft_strcmp

		section .text
_ft_strcmp:
		mov r13,	0
		mov	r14,	0
		mov	r13b,	[rdi]
		mov	r14b,	[rsi]
		cmp r13b,  r14b
		jne _ft_compare
		cmp	r13b, 0
		je _ft_compare
		cmp r14b, 0
		je _ft_compare
		inc rdi
		inc	rsi
		jmp _ft_strcmp
		ret
		
_ft_compare:
		sub r13, r14
		mov rax , r13
		ret

