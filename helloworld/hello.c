#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	

int init_module(void)
{
  printk(KERN_DEBUG "Hello World!\n");
  return 0;
}

void cleanup_module(void)
{
  printk(KERN_DEBUG "Goodbye World!\n");
}
MODULE_LICENSE("GPL");
