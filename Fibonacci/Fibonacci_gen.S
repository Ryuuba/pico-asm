    .text
	.align	1
	.global	fibonacci_gen
	.syntax unified
	.thumb_func
fibonacci_gen:
    @ Prologue
    push    {r7}
    sub	    sp, sp, 4
	add	    r7, sp, 0
    @ temp = a;
    ldr     r3, =a_var
    ldr     r3, [r3]
	str	    r3, [r7]
    @ a = b;
    ldr     r3, =b_var
    ldr     r3, [r3]
    ldr     r4, =a_var
    str     r3, [r4]
    @ b = b + temp;
    ldr     r3, =b_var
    ldr     r3, [r3]
    ldr     r4, [r7]
    adds    r3, r3, r4
    ldr     r4, =b_var
    str     r3, [r4]
    @ return a
    ldr     r3, =a_var
    ldr     r0, [r3]
    @ epilogue
    adds    r7, 4
    mov     sp, r7
    pop     {r7}
    bx      lr

.data
	.align	4
a_var:
	.word	0
b_var:  
    .word   1