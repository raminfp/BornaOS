#ifndef __ISR_H
#define __ISR_H

#include "types.h"

uint32_t interrupt_handlers[256];

struct cpu_regs
{
   uint32_t	ds;                                     /* Data segment selector */
   uint32_t	edi, esi, ebp, esp, ebx, edx, ecx, eax; /* Pushed by pusha. */
   uint32_t	int_no, err_code;                       /* Interrupt number and error code (if applicable) */
   uint32_t	eip, cs, eflags, useresp, ss;           /* Pushed by the processor automatically. */
};

/*
 * Enables registration of callbacks for interrupts or IRQs.  For IRQs, to ease
 * confusion, use the #defines above as the first parameter.
 */
typedef	void (*isrhdl_t)(struct cpu_regs);

void register_interrupt_handler(uint32_t n, uint32_t handler);

#endif
