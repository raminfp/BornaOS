#ifndef __STRING_H
#define __STRING_H
#include "types.h"

extern void cls();
extern void move_csr(void);
extern void scroll(void);
extern void puts(unsigned char *text);
extern void *memcpy(void *dest, const void *src, size_t count);
extern void *memset(void *dest, char val, size_t count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, size_t count);
extern size_t strlen(const char *str);
extern void putch(unsigned char c);



#endif
