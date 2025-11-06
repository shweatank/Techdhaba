#include <linux/module.h>    // Header for all kernel modules (provides module_init, module_exit, etc.)
#include <linux/kernel.h>    // Contains kernel functions like printk() and log level macros (KERN_INFO)
#include <linux/init.h>      // Contains __init and __exit macros used for memory optimization

// ---------------------------------------------------------------------------
// Function: hello_init
// Purpose: This function runs automatically when you insert the module using insmod.
// The __init macro marks it as initialization code that can be discarded after execution.
// ---------------------------------------------------------------------------
static int __init hello_init(void)
{
    printk(KERN_INFO "Hello, Kernel! My driver is loaded.\n"); // Print message to kernel log (dmesg)
    return 0; // Return 0 to indicate successful loading of the module
}

// ---------------------------------------------------------------------------
// Function: hello_exit
// Purpose: This function runs automatically when you remove the module using rmmod.
// The __exit macro marks it as cleanup code that is only used at module removal.
// ---------------------------------------------------------------------------
static void __exit hello_exit(void)
{
    printk(KERN_INFO "Goodbye, Kernel! Driver unloaded.\n"); // Print message when module is unloaded
}

// ---------------------------------------------------------------------------
// module_init() and module_exit() are macros that tell the kernel which
// functions to call when the module is loaded or unloaded.
// ---------------------------------------------------------------------------
module_init(hello_init);   // Register the initialization function
module_exit(hello_exit);   // Register the cleanup function

// ---------------------------------------------------------------------------
// Metadata about the module — visible when you run "modinfo hello.ko"
// ---------------------------------------------------------------------------
MODULE_LICENSE("GPL");               // Specifies that the module is open-source (prevents kernel taint)
MODULE_AUTHOR("AV_RAMAN");                // Author name
MODULE_DESCRIPTION("Simple Hello Module"); // Short description of the module

