savedcmd_/home/venu/prep/kernel_drivers/psuedoCharDriver/pcd.ko := ld -r -m elf_x86_64 -z noexecstack --build-id=sha1  -T scripts/module.lds -o /home/venu/prep/kernel_drivers/psuedoCharDriver/pcd.ko /home/venu/prep/kernel_drivers/psuedoCharDriver/pcd.o /home/venu/prep/kernel_drivers/psuedoCharDriver/pcd.mod.o;  make -f ./arch/x86/Makefile.postlink /home/venu/prep/kernel_drivers/psuedoCharDriver/pcd.ko
