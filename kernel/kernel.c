#include "types.h"
#include "gdt.h"
#include "idt.h"
#include "string.h"
#include "screen.h"
#include "irq.h"
#include "timer.h"
#include "keyboard.h"
#include "screen.h"

#define	WIDTH 	80
#define HIEGHT 	25


void printf(string str)
{
    for(int i = 0; str[i] != '\0'; ++i)
    {
	switch(str[i])
        {
            case '\n':
                x = 0;
                y++;
                break;
            default:
                video_memory[WIDTH*y+x] = (video_memory[WIDTH*y+x] & 0xFF00) | str[i];
                x++;
                break;
        }

        if(x >= WIDTH)
        {
            x = 0;
            y++;
        }

        if(y >= HIEGHT)
        {
            for(y = 0; y < HIEGHT; y++)
                for(x = 0; x < WIDTH; x++)
                    video_memory[WIDTH*y+x] = (video_memory[y+x] & 0xFF00) | ' ';
            x = 0;
            y = 0;
        }
    }
}



void main(const void* multiboot_structure, uint32_t magicnumber)
{


  	init_descriptor_tables();

	init_interrupt_descriptor_tables();

  	init_irq();

	timer_install();

	keyboard_install();

	__asm__ __volatile__ ("sti");

	printf("Starting Kernel ...!");

	for (;;);
}
