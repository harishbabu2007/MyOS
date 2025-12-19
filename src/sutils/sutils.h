#ifndef SUTILS_H
#define SUTILS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

size_t strlen(const char* str);
void reverse_str(char* str, int length);
char* itoa(int num, char* str, int base);

#endif