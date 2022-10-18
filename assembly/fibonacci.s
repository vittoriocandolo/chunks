	.data
input:		
	.word 45		; 2 is min input, 2^30 < f(46) < 2^31 is max output	
	.text			; f(1) works but it is not proper execution of the algorithm
main:	
	ldr r0, =input		; memory addr in r0
	ldr r0, [r0]		; input in r0
	bl fibonacci
	swi 0x11		; exit
fibonacci:
	mov r3, #0		; f(n - 2)
	mov r2, #1		; f(n - 1)
loop:	
	mov r3, r2		; update f(n - 2)
	mov r2, r1		; update f(n - 1)
	add r1, r2, r3		; compute f(n)
	subs r0, r0, #1		; decrement r1
	bne loop		; if zero loop again
	mov pc, lr		; return
	.end

; ARM Assembly
