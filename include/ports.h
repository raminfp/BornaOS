#ifndef __PORTS_H
#define __PORTS_H
#include "types.h"

// output byte
void outb(uint16_t port, uint8_t value);

// input byte
uint8_t inb(uint16_t port);

// input word
uint16_t inw(uint16_t port);

#endif
