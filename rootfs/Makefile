sys:
	find init | cpio -o -Hnewc |gzip -9 > rootfs.img
	qemu-system-i386 -kernel ../kernel/bzImage -initrd rootfs.img

arm:
	find init | cpio -o -Hnewc |gzip -9 > rootfs.img
	qemu-system-arm -M vexpress-a9 -m 512M -kernel ../kernel/zImage -append "rdinit=/linuxc console=ttyAMA0 loglevel=8" -dtb ../kernel/dtbs/vexpress-v2p-ca9.dtb -initrd rootfs.img -nographic