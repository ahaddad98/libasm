		global _ft_strdup
		extern _malloc
		extern _ft_strlen
		extern 	_ft_strcpy
		section .text

_ft_strdup:
			mov rax,0
			push rdi
			call _ft_strlen
			mov 	rdi,rax
			call  _malloc
			mov rdi,rax
			pop	rsi
			call _ft_strcpy
			ret

