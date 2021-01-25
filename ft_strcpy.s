		global _ft_strcpy

		section .text

_ft_strcpy:

		mov rax , 0
		mov r13 , 0
		mov r14 , 0
		mov r14b , [rsi]
		cmp	r14b , 0
		je _ft_copy_end
		jne _ft_copy

_ft_copy :
		mov [rdi] , r14b
		inc rdi
		inc rsi
		inc r13
		mov r14b , [rsi]
		cmp r14b , 0
		jne _ft_copy

_ft_copy_end :
		mov [rdi] , r14b
		sub rdi,r13
		mov rax, rdi
		ret
						
