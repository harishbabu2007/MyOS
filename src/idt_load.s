.global idt_load

idt_load:
    mov 4(%esp), %eax   # load pointer argument
    lidt (%eax)         # load IDT
    ret
