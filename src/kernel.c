#include "terminal/terminal.h"
#include "clock/clock.h"

void kernel_main(void) 
{
	/* Initialize terminal interface */
	terminal_initialize();

	/* Newline support is left as an exercise. */
	terminal_writestring("My Operating System \n");
	terminal_writestring("Made By harish \n");

	int count = 0;
	char count_str[100];

	terminal_writestring(itoa(count, count_str, 10));
	terminal_writestring("\n");

	count = 10;

	terminal_writestring(itoa(count, count_str, 10));
	terminal_writestring("\n");

	terminal_writestring("Hello world \n");
}