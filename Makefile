.PHONY: iso

iso:
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
