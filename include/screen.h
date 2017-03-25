#ifndef __SCREEN_H
#define __SCREEN_H
#include "types.h"


// The VGA framebuffer starts at 0xB8000.
static uint16_t *video_memory = (uint16_t *)0xB8000;
// Stores the cursor position.
static uint8_t x = 0;
static uint8_t y = 0;

#endif
