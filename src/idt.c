#include "idt.h"
#include "./sutils/sutils.h"

extern void idt_load(struct idt_ptr*);

static struct idt_entry idt[256];
static struct idt_ptr idtp;

void idt_set_gate(int n, uint32_t handler)
{
    idt[n].offset_low  = handler & 0xFFFF;
    idt[n].selector    = 0x08;   // GRUB's code segment
    idt[n].zero        = 0;
    idt[n].type_attr   = 0x8E;   // interrupt gate
    idt[n].offset_high = handler >> 16;
}

void idt_install()
{
    for (int i = 0; i < 256; i++) {
        idt[i].offset_low  = 0;
        idt[i].selector    = 0;
        idt[i].zero        = 0;
        idt[i].type_attr   = 0;
        idt[i].offset_high = 0;
    }

    idtp.limit = sizeof(idt) - 1;
    idtp.base  = (uint32_t)&idt;

    idt_load(&idtp);
}
