#include <stdint.h>
#include "../sutils/ports.h"
#include "../terminal/terminal.h"


static const char scancode_to_ascii[128] = {
    0,  27, '1','2','3','4','5','6','7','8','9','0','-','=', '\b',
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n',
    0,   'a','s','d','f','g','h','j','k','l',';','\'','`',
    0,  '\\','z','x','c','v','b','n','m',',','.','/',
    0,   '*', 0,  ' ', 0
};

static bool can_type = true;

static void ps2_wait_input(void)
{
    while (inb(0x64) & 0x02);
}

void keyboard_handler()
{
    outb(0x20, 0x20); 
}

void keyboard_init(void)
{
    ps2_wait_input();
    outb(0x64, 0xAE);   // enable keyboard interface

    ps2_wait_input();
    outb(0x60, 0xF4);   // enable scanning
}

void handle_keys(uint8_t sc){
    if (sc == 0x0E && can_type) {
        terminal_backspace();
    } else if (sc < 128) {
        char c = scancode_to_ascii[sc];
        if (c && can_type) {
            terminal_putchar(c);
        }
    };
}

void get_keyboard_scancode(void) {
    if (inb(0x64) & 1) {
        uint8_t sc = inb(0x60);

        if (sc & 0x80)
            return;

        handle_keys(sc);
    }
}