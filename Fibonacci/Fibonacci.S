    .text
	.align	1
	.global	main
	.syntax unified
	.thumb_func
main:
    @ Prologue
    push    {r7, lr}
    sub	    sp, sp, 8
	add	    r7, sp, 0
init:
    bl stdio_init_all@ Backs r7 and lr up
    @ i = 0
    movs    r3, 0
    str     r3, [r7, 4]
while_loop:
    @ fib_num = fibonacci_generator();
    bl      fibonacci_gen
    str     r0, [r7]
    @ printf fibonacci
    ldr     r2, [r7]
    ldr     r1, [r7, 4]
    ldr     r0, =STR1
    bl      printf
    @ i++
    ldr     r3, [r7, 4]
    adds    r3, 1
    str     r3, [r7, 4]
    @ If i == 47
    ldr     r3, [r7, 4]
    cmp     r3, 47
    bne     .L1
    ldr     r0, =STR2
    bl      printf
    b       .EXIT
.L1:
    @ delay
    ldr     r0, DELAY_TIME_MS
    bl      sleep_ms
    b       while_loop
.EXIT:
    nop

.align 4
DELAY_TIME_MS:  .word       1000
STR1:           .ascii      "Fib(%u)=%u\012\000"
STR2:           .ascii      "Program stops\012\000"
