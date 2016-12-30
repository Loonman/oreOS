.PHONY: iso

iso: kernel
	genisoimage -R \
            -b boot/grub/stage2_eltorito \
            -no-emul-boot \
            -boot-load-size 4 \
            -A oreOS \
            -input-charset utf8 \
            -quiet \
            -boot-info-table \
            -o oreOS.iso \
            iso

kernel: link.ld loader.o
	ld -T link.ld -melf_i386 loader.o -o kernel.elf

loader.o : loader.s
	nasm -f elf32 loader.s
