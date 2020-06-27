;Noal Zyglowicz (ntz3sw) 11/17/19

;Optimizations:
	
;use less registers
;use fewer commands
;use shifts instead of division and multiplication
;use the lea command to perform multiplication and addition in one command
;reduce number of registers pushed onto stack
;look at only last 8 bits when checking for parity rather than entire register 

	global collatz

	section .text

collatz:
	xor     rax, rax
	cmp	dil, 1		 ;check to see if result is 1 and function should end
	je	done
	test	dil, 1		 ;check rightmost bit parity
	je	loop_even	 ;if even, jump to loop_even
	jne	loop_odd	 ;if odd, jump to loop_odd
loop_even:	
	shr	rdi, 1		 ;for even case, x/2
	call	collatz
	inc     rax
	ret
loop_odd:
	lea     rdi, [rdi*3 + 1]
	call    collatz
	inc     rax
	ret
done:
	ret


	
