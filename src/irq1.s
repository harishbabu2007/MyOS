.global irq1
.extern keyboard_handler

irq1:
    cli                 # block nested interrupts

    pushl %ds
    pushl %es
    pushl %fs
    pushl %gs
    pusha

    mov $0x10, %ax      # kernel data segment
    mov %ax, %ds
    mov %ax, %es
    mov %ax, %fs
    mov %ax, %gs

    call keyboard_handler

    popa
    popl %gs
    popl %fs
    popl %es
    popl %ds

    iret
