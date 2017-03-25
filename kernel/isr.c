#include "types.h"
#include "screen.h"
#include "isr.h"
#include "kernel.h"
#include "ports.h"
#include "string.h"

#define NUL 0



/* This gets called from our ASM interrupt handler stub. */
void isr_handler(struct cpu_regs regs)
{

	if (interrupt_handlers[regs.int_no] != NUL) {
		uint32_t handler = interrupt_handlers[regs.int_no];
		//handler(regs);
	} else {
    		printf("unhandled interrupt: \n");
	}
}


void register_interrupt_handler(uint32_t n, uint32_t handler)
{

	if (n > sizeof((interrupt_handlers)) / sizeof((interrupt_handlers)[0]))
		puts("Bad interrupt handler index.");
	interrupt_handlers[n] = (uint32_t)handler;
}

/* This is a simple string array. It contains the message that
*  corresponds to each and every exception. We get the correct
*  message by accessing like:
*  exception_message[interrupt_number] */
unsigned char *exception_messages[] =
{
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

void fault_handler(struct cpu_regs *r)
{
    /* Is this a fault whose number is from 0 to 31? */
    if (r->int_no < 32)
    {
        /* Display the description for the Exception that occurred.
        *  In this tutorial, we will simply halt the system using an
        *  infinite loop */
       puts(exception_messages[r->int_no]);
       puts(" Exception. System Halted!\n");
       for (;;);
    }
}
