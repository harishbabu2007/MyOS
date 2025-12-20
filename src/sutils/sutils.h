#ifndef SUTILS_H
#define SUTILS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

size_t strlen(const char *str);
void reverse_str(char *str, int length);
char *itoa(int num, char *str, int base);
void *memset(void *dest, int val, size_t len);
char *strcpy(char *dest, const char *src);
int strcmp(const char *str1, const char *str2);
char *strconcat(char *dest, const char *src);

#endif