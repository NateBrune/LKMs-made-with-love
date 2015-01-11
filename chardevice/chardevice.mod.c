#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xb7cc4c6d, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xab6b499c, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x40d5342a, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x32464a10, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x6eec2133, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x19fac83e, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xcc193edd, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0xd7e19de5, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

