export ARCH := arm64
export CROSS_COMPILE := /home/magician/opt/gcc-arm-11.2-2022.02-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-

obj-m := lysi_core.o lysi_dev.o

KDIR := /home/magician/workspace/orangepi-build/orangepi-build/kernel/orange-pi-5.10-rk3588

PWD := $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	rm -rf *.o *.ko *.order *.symvers *.mod *.mod.c .**.cmd .mod* .Mod*
