FRAMEBUFFEROBJ = io/framebuffer.o io/io.o io/write.o io/serial.o io/log.o
MEMORYOBJ = memory/gdt.o memory/gdt_x86.o memory/idt.o memory/idt_x86.o
LIBOBJ = lib/string.o
OBJECTS = loader.o kmain.o $(FRAMEBUFFEROBJ) $(MEMORYOBJ)
CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
LDFLAGS = -T link.ld -melf_i386
AS = nasm
ASFLAGS = -f elf
DEPENDENCIES = io memory

all: kernel

kernel: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf

iso: kernel dependencies
	cp kernel.elf iso/boot/kernel.elf
	genisoimage -R                          \
            -b boot/grub/stage2_eltorito    \
            -no-emul-boot                   \
            -boot-load-size 4               \
            -A os                           \
            -input-charset utf8             \
            -quiet                          \
            -boot-info-table                \
            -o oreOS.iso                    \
            iso

run: iso
	bochs -f bochsrc.txt -q

%.o: %.c
	$(CC) $(CFLAGS)  $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

.PHONY: dependencies

dependencies: $(DEPENDENCIES)
	-for d in $(DEPENDENCIES); do (	cd $$d; make all); done


.PHONY: clean

clean: clean_dependencies
	rm -rf *.o kernel.elf oreOS.iso

.PHONY: clean_dependencies

clean_dependencies: $(DEPENDENCIES)
	-for d in $(DEPENDENCIES); do (	cd $$d; make clean); done