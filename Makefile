# =========================
# Toolchain
# =========================
CC      := i686-elf-gcc
AS      := i686-elf-as
LD      := i686-elf-gcc

# =========================
# Flags
# =========================
CFLAGS  := -std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAGS := -T linker.ld -ffreestanding -O2 -nostdlib

# =========================
# Directories
# =========================
SRC_DIR := src
OBJ_DIR := obj
ISO_DIR := isodir

# =========================
# Source & Object Files
# =========================
C_SOURCES := $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/**/*.c)
C_OBJECTS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_SOURCES))

ASM_SOURCE := $(SRC_DIR)/boot.s
ASM_OBJECT := $(OBJ_DIR)/boot.o

# =========================
# Targets
# =========================
all: link

compile: $(ASM_OBJECT) $(C_OBJECTS)

link: compile
	$(LD) $(LDFLAGS) -o myos.bin $(ASM_OBJECT) $(C_OBJECTS) -lgcc

# =========================
# Rules
# =========================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CC) -c $< -o $@ $(CFLAGS)

$(ASM_OBJECT): $(ASM_SOURCE)
	if not exist "$(OBJ_DIR)" mkdir "$(OBJ_DIR)"
	$(AS) $< -o $@


# =========================
# ISO Creation
# =========================
iso:
	cp myos.bin $(ISO_DIR)/boot/myos.bin
	cp grub.cfg $(ISO_DIR)/boot/grub/grub.cfg
	grub-mkrescue -o myos.iso $(ISO_DIR)

# =========================
# Run in QEMU
# =========================
run:
	qemu-system-i386 -cdrom myos.iso

# =========================
# Cleanup
# =========================
clean:
	rm -rf $(OBJ_DIR) myos.bin myos.iso

.PHONY: all compile link iso run clean
