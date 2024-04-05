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
    @ for loop
L2:
    movs    r3, FIRST_GPIO  @ gpio = FIRST_GPIO
    str     r3, [r7, 40]
    b       L1
    ldr     r0, [r7, 40]    @ gpio_init(gpio)
    bl      gpio_init
    movs    r1, 1           @ gpio_set_dir
    ldr     r0, [r7, 40]
    bl      gpio_set_dir_wrapper
    ldr     r3, [r7, 40]    @ gpio++
    adds    r3, 1
    str     r3, [r7, 40]
L1:
    ldr     r3, [r7, 40]    @ gpio < FIRST_GPIO + 7
    cmp     r3, 9
    blt     L2
    @ gpio_init(BUTTON_GPIO)
    movs    r0, BUTTON_GPIO
    bl      gpio_init
    @ gpio_set_dir
    movs    r1, 1
    movs    r0, BUTTON_GPIO
    bl      gpio_set_dir_wrapper
    @ gpio_pull_up
    movs    r0, BUTTON_GPIO
    bl      gpio_pull_up_wrapper
    @ val = 0
    movs    r3, 0
    str     r3, [r7, 44]
    @ while(true)
L7:
    @ if (!gpio_get(BUTTON_GPIO))
    movs    r0, BUTTON_GPIO
    bl      gpio_get_wrapper
    cmp     r0, 0
    bne     L3
    @ if (val == 9)
    ldr     r3, [r7, 44]
    cmp     r3, 9
    bne     L4
    @ val = 0
    movs    r3, 0
    str     r3, [r7, 44]
    b       L5
L4:
    @ else
    @ val++
    ldr     r3, [r7, 44]
    adds    r3, 1
    str     r3, [r7, 44]
    b       L5
L3: 
    @ else if (val == 0)
    ldr     r3, [r7, 44]
    cmp     r3, 0
    bne     L6
    @ val = 9
    movs    r3, 9
    str     r3, [r7, 44]
    b       L5
L6:
    @ else
    @ val--
    ldr     r3, [r7, 44]
    adds    r3, -1
    str     r3, [r7, 44]
L5:
    @ mask = bits[val] << FIRST_GPIO
    mov     r3, r7          @ computes base address
    ldr     r4, [r7, 44]    @ gets index value
    lsls    r4, 2           @ multiplies index by four
    ldr     r3, [r3, r4]    @ gets M[base + 4val]
    lsls    r3, FIRST_GPIO
    str     r3, [r7, 48]
    @ gpio_set_mask(mask)
    ldr     r0, [r7, 48]
    bl      gpio_set_mask_wrapper
    @ sleep_ms(500)
    ldr     r0, DELAY
    bl      sleep_ms
    @ gpio_clr_mask
    ldr     r0, [r7, 48]
    bl      gpio_clr_mask_wrapper
    b       L7


.align 4
DELAY:  .word 500
STR0:   .ascii  "Hello, 7segment - press button to count down!\012\000"

.section .rodata
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
 * bits[1] * <- r7 + 4
 ***********
 * bits[2] * <- r7 + 8
 ***********
 * bits[3] * <- r7 + 12
 ***********
 * bits[4] * <- r7 + 16
 ***********
 * bits[5] * <- r7 + 20
 ***********
 * bits[6] * <- r7 + 24
 ***********
 * bits[7] * <- r7 + 28
 ***********
 * bits[8] * <- r7 + 32
 ***********
 * bits[9] * <- r7 + 36
 ***********
 * gpio    * <- r7 + 40
 ***********
 * val     * <- r7 + 44
 ***********
 * mask    * <- r7 + 48
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