#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>


 
static int probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    printk(KERN_INFO "OnePlus One detected\n", id->idVendor, id->idProduct);
    return 0;
}
 
static void disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "OnePlus One removed\n");
}



static struct usb_device_id oneplusone_table[] =
{
    { USB_DEVICE(0x05c6, 0x6765) },
    {} /* Terminating entry */
};

static struct usb_driver oneplusone_driver =
{
    .name = "usb_driver",
    .id_table = oneplusone_table,
    .probe = probe,
    .disconnect = disconnect,
};

MODULE_DEVICE_TABLE (usb, oneplusone_table);


  
static int __init usb_init(void)
{
    return usb_register(&oneplusone_driver);
}
 
static void __exit usb_exit(void)
{
    usb_deregister(&oneplusone_driver);
}
 
module_init(usb_init);
module_exit(usb_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nate Brune");