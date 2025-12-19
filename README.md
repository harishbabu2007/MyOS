# MyOS
basic operating system kernel made entirely in C


## Steps to install development enviroment and get started

you can use your prefered text editor, this project requires a cross compiler to be installed in your system

1) Install the i686 build tools from this repo https://github.com/lordmilko/i686-elf-tools and add the precompiled binary folders to your path so that you can use i686 tools from any where
2) install binuitls, make
3) install grub and grub tools so that you can use grub-mkrescue
4) install qemu for emulation

It is recommended that you use a linux environment or even WSL works, and the end of the day we will compile a .iso file which will be used by the qemu emulation environment to run the os

## Compiling the OS 
The makefile contains all the compile instructions to compile the os
to compile and run 
```
make compile
make link
make iso
make run
```
NOTE: the make run starts the qemu emulator with the compile iso file and grub bootloader


## Practice Followed for developing MyOs
the ```make compile```, ```make link``` ```make run``` commands were run on a windows environment with i686-elf tools, binutils, make and qemu installed and added to ```PATH```

the ```make iso``` command was run on Ubuntu20 WSL inside the windows enviroment with the grub and grub tools installed along with xorriso

if you have any doubts and difficulties in setting up the dev environment for development and testing (which u will in most cases), please do refer https://wiki.osdev.org/GCC_Cross-Compiler. Since this operating system is built by following articles/blogs from [wiki.osdev.org](https://wiki.osdev.org/)