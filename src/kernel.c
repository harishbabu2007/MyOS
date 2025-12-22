#include "terminal/terminal.h"
#include "clock/clock.h"
#include "sutils/ports.h"
#include "keyboard/keyboard.h"

void main_loop(){
	for (;;) {
        keyboard_event_t event = get_keyboard_event();

        if (event.key == KEY_SPACE){
            terminal_writestring("Space pressed!\n");
        }
    }
}

void kernel_main(void) 
{	
	terminal_initialize();
    terminal_writestring("Keyboard ready\n");

    keyboard_init();

    main_loop();
}