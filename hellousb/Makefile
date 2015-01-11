obj-m += hellousb.o
ifdef KERNEL_SOURCE
all:
	make -C ${KERNEL_SOURCE} SUBDIRS=$(shell pwd) modules
clean:
	make -C ${KERNEL_SOURCE} SUBDIRS=${shell pwd} clean
else
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

endif
