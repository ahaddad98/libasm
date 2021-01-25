		global _ft_read
		extern ___error
		section .text

_ft_read:
	mov rax , 0x02000003
	syscall
	jc _ft_error
	syscall
	ret

_ft_error:
		push rax
		call ___error
		pop r10
		mov [rax], r10
		mov rax, -1
		ret

