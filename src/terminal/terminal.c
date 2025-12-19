#include"terminal.h"

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer = (uint16_t*)VGA_MEMORY;

uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) 
{
	return fg | bg << 4;
}

uint16_t vga_entry(unsigned char uc, uint8_t color) 
{
	return (uint16_t) uc | (uint16_t) color << 8;
}

void terminal_initialize(void) 
{
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
	
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(uint8_t color) 
{
	terminal_color = color;
}

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) 
{	
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_scroll_down(){
    for (size_t y = 0; y < VGA_HEIGHT; y++){
        for (size_t x = 0; x < VGA_WIDTH; x++){
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(terminal_buffer[index + VGA_WIDTH], terminal_color);
        }
    }
}

void terminal_writestring(const char* data) 
{
	for (size_t i=0; i<strlen(data); i++){
		if (data[i] == '\n'){
			terminal_column = 0;
			terminal_row++;
		}
		
		if (++terminal_column == VGA_WIDTH){
			terminal_column = 0;
			if (++terminal_row == VGA_HEIGHT){
				terminal_scroll_down();
                --terminal_row;
			}
		}

		if (data[i] != '\n') terminal_putentryat(data[i], terminal_color, terminal_column, terminal_row);
	}
}