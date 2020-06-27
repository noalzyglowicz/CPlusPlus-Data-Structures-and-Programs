; mathlib.s
;
; Purpose : This file contains the implementation of the function product, which multiplies two integers using iterative addition and power, which recursively calculates a given integer base raised to a given integer power
	
; Parameter 1 (in rdi) first positive integer
; Parameter 2 (in rsi) second positive integer
; Return value is a long that is the multiplication of the two integers in the sequence
;

	global product
	global power

	section .text

product:	
	; Standard prologue: we do not have to create any local
	; variables (those values will be kept in registers), and 
	; we are not using any callee-saved registers.

	; Subroutine body:
	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out the counter i
start_product:	
	cmp	r10, rsi	 ; does i == n?
	je	done		 ; if so, we are done with the loop
	add	rax, rdi         ; add Parameter 1 to rax
	inc	r10		 ; increment our counter i
	jmp	start_product		 ; we are done with this loop iteration
done:	

	; Standard epilogue: the return value is already in rax, we
	; do not have any callee-saved registers to restore, and we do not
	; have any local variables to deallocate, so all we do is return
	ret

power:	

	;Subroutine body:
        xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out the counter i
	xor     r11, r11

start_power:	
	cmp	r10, rsi
	je      done2
	dec     rsi
	call	start_power
	mov     rsi, rax
	call    product
	ret

done2:
	mov     rax, 1
	ret


	
