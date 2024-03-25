	.cpu cortex-m0
	.arch armv6s-m
    .text
	.align	1
	.global	main
	.syntax unified
	.code	16
	.thumb_func
	.type	main, %function
main:
    # Prologue
    push    {r7, lr}
    sub	    sp, sp, #16
	add	    r7, sp, #0
init:
    bl stdio_init_all           // Jump to SDK STDIO initialisation routine
    movs r0, #0x80              // Set the delay period
    lsls r0, #4
    bl sleep_ms                 // Delay to allow the STDIO-over-USB to ready
    # a = 0
    movs    r3, #0
    str     r3, [r7, #12]
    # b = 1
    movs    r3, #1
    str     r3, [r7, #8]
    # i = 0
    movs    r3, #0
    str     r3, [r7]
loop:
    # temp = a
    ldr     r3, [r7, #12]
    str     r3, [r7, #4]
    # a = b
    ldr     r3, [r7, #8]
    str     r3, [r7, #12]
    # b = temp + b;
    ldr     r3, [r7, #4]
    ldr     r4, [r7, #8]
    adds    r3, r3, r4
    str     r3, [r7, #8]
    # i++
    ldr     r3, [r7]
    adds    r3, r3, #1
    str     r3, [r7]
    # printf fibonacci
    ldr     r2, [r7, #12]
    ldr     r1, [r7]
    ldr     r0, =STR
    bl      printf
    # delay
    ldr     r0, DELAY_TIME_MS
    bl      sleep_ms
    b       loop

.align 4
DELAY_TIME_MS:  .word           5000
STR:            .ascii	"Fib(%i)=%i\012\000"
