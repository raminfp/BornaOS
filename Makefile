
# sudo apt-get install gcc binutils libc6-dev-i386
# sudo apt-get install VirtualBox grub-legacy xorriso

GCCPARAMS = -m32 -Iinclude -nostdlib -fno-builtin -fno-exceptions -fno-leading-underscore -Wno-write-strings
ASPARAMS = --32
LDPARAMS = -melf_i386
ASFLAGS = -felf

objects = objs/loader.o \
	  assm/gdt_flush.o \
	  assm/idt_flush.o \
	  assm/interrupt.o \
	  objs/ports.o \
	  objs/screen.o \
	  objs/isr.o \
	  objs/irq.o \
	  objs/gdt.o \
	  objs/idt.o \
	  objs/timer.o \
	  objs/string.o \
	  objs/keyboard.o \
	  objs/kernel.o



objs/%.o: kernel/%.c
	 gcc $(GCCPARAMS) -c -o $@ $<

objs/%.o: drivers/%.c
	gcc $(GCCPARAMS) -c -o $@ $<

objs/%.o: assm/%.s
	mkdir -p $(@D)
	as $(ASPARAMS) -o $@ $<

assm/%.o: assm/idt_flush.s assm/interrupt.s
	nasm $(ASFLAGS) $<

kernel.bin: linker.ld $(objects)
	ld $(LDPARAMS) -T $< -o $@ $(objects)

kernel.iso: kernel.bin
	rm -rf iso
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	touch iso/boot/grub/grub.cfg
	cp $^ iso/boot/
	echo 'set timeout=0'                     > iso/boot/grub/grub.cfg
	echo 'set default=0'                     >> iso/boot/grub/grub.cfg
	echo ''                                  >> iso/boot/grub/grub.cfg
	echo 'menuentry "My Operating System" {' >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/kernel.bin'      >> iso/boot/grub/grub.cfg
	echo '  boot'                            >> iso/boot/grub/grub.cfg
	echo '}'                                 >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=kernel.iso iso



install: kernel.bin
	sudo cp $< /boot/kernel.bin


.PHONY: clean
clean:
	rm -rf objs kernel.bin *.iso
	rm -rf iso
