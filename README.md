# oreOS

A basic operating system following the guide at http://littleosbook.github.io/

#Todo
+ Finish implementing the operating system as designed in the little os book
+ Remove dependency on GRUB bootloader

# Building and running oreOS
To build and run oreOS you will need a c compiler, an x86 assembly compiler, an ISO generator and an x86 virtual machine.

The tools used to develop oreOS include
+ gcc
+ nasm
+ genisoimage
+ bochs

These will allow you to build oreOS without modifying the makefiles included in the project.

To build an iso to use an any virtual machine 

```bash
make iso
```

To build an iso and launch oreOS on bochs

```bash
make run
```
