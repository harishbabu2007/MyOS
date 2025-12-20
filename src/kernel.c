#include "terminal/terminal.h"
#include "clock/clock.h"
#include "sutils/ports.h"


void idt_install();
void idt_set_gate(int, uint32_t);
void pic_remap();
extern void irq1();
void keyboard_init(void);
void get_keyboard_scancode(void);

void main_loop(){
	for (;;) {
		get_keyboard_scancode();
    }
}

void kernel_main(void) 
{	
	terminal_initialize();
    terminal_writestring("Keyboard ready\n");

    keyboard_init();

    main_loop();
}