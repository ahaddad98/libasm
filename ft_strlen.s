		global _ft_strlen

		section .text

_ft_strlen:
		mov rax , 0
		cmp rdi , 0
		je _ret
		cmp [rdi]  ,byte 0
		jne _ft_loop
		ret

_ft_loop:
		inc rdi
		inc rax
		cmp byte [rdi] , 0
		jne _ft_loop
		ret
_ret:
		ret
