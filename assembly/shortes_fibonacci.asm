mov rax, 0
mov rdx, 1

mov rcx, 8		; example with 8

loop:
	xadd rax, rdx
	loop .loop

