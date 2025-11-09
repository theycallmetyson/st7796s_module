# Makefile for out-of-tree kernel module compilation

# KERNELRELEASE is typically set by the build system when running 'make'
# inside the kernel source tree, but for an out-of-tree module, we must
# point to the correct kernel source directory.

# 1. Determine the kernel version currently running on the RPi
# The user specified 6.12.47+rpt-rpi-v8. We assume the headers are installed
# in /lib/modules/$(shell uname -r)/build.

KVER := $(shell uname -r)
KDIR := /lib/modules/$(KVER)/build

# 2. Define module name and source files
obj-m := st7796s_drv.o
MODULE_NAME := st7796s_drv

# 3. Compilation targets
all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

# Phony targets
.PHONY: all clean