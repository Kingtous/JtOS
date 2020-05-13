sys:
	find init | cpio -o -Hnewc |gzip -9 > rootfs.img
	qemu-system-x86_64 -kernel ../kernel/bzImage -initrd rootfs.img