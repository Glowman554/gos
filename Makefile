all: gos

gos:
	$(MAKE) -C gos

iso:
	cp ./gos/terminal/terminal.bin ./initrd/files/.
	cp ./gos/writer/writer.bin ./initrd/files/.
	cp ./gos/init/init.bin ./initrd/files/.
	cp ./gos/desktop/desktop.bin ./initrd/files/.
	cp ./gos/cursor/cursor.bin ./initrd/files/.
	cp ./gos/logos/logos.bin ./initrd/files/.
	cp ./gos/info/info.bin ./initrd/files/.
	$(MAKE) -C initrd
	cp ./initrd/initrd.img ./cdrom_files/.
	genisoimage -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o cdrom.iso cdrom_files/


update:
	git clone https://github.com/Glowman554/gkernel.git
	$(MAKE) -C gkernel
	cp ./gkernel/kernel/kernel ./cdrom_files
	rm -R gkernel

clean:
	$(MAKE) -C gos clean
push:
	$(MAKE) -C gos clean
	git add .
	git commit -m "autopush"
	git push -u origin master

.PHONY: all gos iso update clean push

