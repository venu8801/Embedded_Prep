/* this is a basic hello world module */

#include <linux/module.h>
#include <linux/printk.h>



static int my_module_init(void){
//module init function

	pr_info("Hello Module\n");
	return 0;
}

static void my_module_exit(void){
//module clean up function
	pr_info("Exit module\n");
	return;
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL"); //GPL license
MODULE_AUTHOR("Venu Gopal");
MODULE_DESCRIPTION("A simple hello world kernel module");
MODULE_INFO(board,"common and can work on any h/w");
