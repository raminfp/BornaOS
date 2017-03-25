#ifndef __IRQ_H
#define __IRQ_H

#include "types.h"
#include "isr.h"

void init_irq(void);

extern void irq_install_handler(int irq, void (*handler)(struct cpu_regs *r));
extern void irq_uninstall_handler(int irq);
extern void irq_install();


extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();

#endif
