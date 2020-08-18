all: gos

gos:
	$(MAKE) -C init install
	$(MAKE) -C terminal install
	$(MAKE) -C writer install
	$(MAKE) -C desktop install
	$(MAKE) -C cursor install
	$(MAKE) -C logos install
	$(MAKE) -C info install

iso: gos
	
	genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o cdrom.iso cdrom_files/


update:
	git clone https://github.com/Glowman554/gkernel.git
	$(MAKE) -C gkernel
	cp ./gkernel/kernel/kernel ./cdrom_files
	rm -R gkernel

clean:
	$(MAKE) -C init clean
	$(MAKE) -C terminal clean
	$(MAKE) -C writer clean
	$(MAKE) -C desktop clean
	$(MAKE) -C cursor clean
	$(MAKE) -C logos clean
	$(MAKE) -C info clean

push: clean
	git add .
	git commit -m "autopush"
	git push -u origin master

run: iso
	qemu-system-i386 -cdrom cdrom.iso -serial stdio

.PHONY: all gos iso update clean push run

