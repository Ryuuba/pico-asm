@ Directivas mínimas
.arch armv6-m
.text @ Guardar las instrucciones en la sección de código
.align 1 @ Indica que el código ocupa direcciones de 2^1 Byte
.global main @ Permite que el procedimiento pueda llamarse
.syntax unified @ Usa la sintaxis nueva de ARM thumb
.thumb_func @ Indica que las instrucciones de la función son 2 B
.equ FIRST_GPIO, 2
.equ BUTTON_GPIO, FIRST_GPIO+7

main:
    @ prologue
    push    {r7, lr}
    sub     sp, 56
    mov     r7, sp
    @ initializes array
    mov     r0, r7      @ Gets address of bits[0]
    ldr     r1, =ARRAY  @ Gets address of first initial value
    ldmia   r1!, {r2, r3, r4, r5, r6}
    stmia   r0!, {r2, r3, r4, r5, r6}
    ldmia   r1!, {r2, r3, r4, r5, r6}
    stmia   r0!, {r2, r3, r4, r5, r6}
    @ stdio_init_all()
    bl      stdio_init_all
    @ printf("Hello, 7segment - press button to count down!\n")
    ldr     r0, =STR0
    bl      printf
    

.align 4
STR0    .ascii  "Hello, 7segment - press button to count down!\012\000"

.rodata
    .align 2
ARRAY: 
    .word   0x3f
    .word   0x06
    .word   0x5b
    .word   0x4f
    .word   0x66
    .word   0x6d
    .word   0x7d
    .word   0x07
    .word   0x7f
    .word   0x67

/* STACK
 ***********
 * bits[0] * <- sp, r7
 ***********
 * bits[1] *
 ***********
 * bits[2] *
 ***********
 * bits[3] *
 ***********
 * bits[4] *
 ***********
 * bits[5] *
 ***********
 * bits[6] *
 ***********
 * bits[7] *
 ***********
 * bits[8] *
 ***********
 * bits[9] *
 ***********
 * gpio    *
 ***********
 * val     *
 ***********
 * mask    *
 ***********
 * ------- *
 ***********
 * r7      *
 ***********
 * lr      *
 ***********
 *
 * */

@  https://developer.arm.com/documentation/ddi0419/c/Application-Level-Architecture/Thumb-Instruction-Details/Alphabetical-list-of-ARMv6-M-Thumb-instructions/LDM--LDMIA--LDMFD