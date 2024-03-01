/* psuedo char driver
 * */

#include <linux/module.h>
#include <linux/printk.h>
#include <linux/cdev.h> 
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/kernel.h>

#define mem_size 100
#define MAX_DEVICES 4



/* Device private data */

static struct PCDprivate_data
{
	char *buffer;
	unsigned size;
	const char *serial;
	int perm;
	struct cdev pcdCDEV;
};

/* Driver private data */
struct PCDdrv_private_data
{
	int total_dev;
	struct PCDprivate_data;
};




dev_t dev;  //device number
static struct class *dev_class;
static struct cdev pcdDev;
static char kernel_buffer1[mem_size];
static char kernel_buffer2[mem_size];
static char kernel_buffer3[mem_size];
static char kernel_buffer4[mem_size];

/* ---driver routine prototypes ---*/



static int mod_init(void);
static void mod_clean(void);
static int my_open(struct inode *inode, struct file *file);
static int my_close(struct inode *inode, struct file *file);
static ssize_t my_read(struct file *filp, char __user *buf, size_t len,loff_t *off);
static ssize_t my_write(struct file *filp, const char *buf, size_t len, loff_t *off);

static struct file_operations fops = 
{
	.owner = THIS_MODULE,
	.read = my_read,
	.write = my_write,
	.open = my_open,
	.release = my_close,


};


static int my_open(struct inode *inode, struct file *file){
	pr_info("Device File Closed\n");
	return 0;
}

static ssize_t my_read(struct file *filp, char __user *buf, size_t len, loff_t *off){
  //Copy the data from the kernel space to the user-space
        if( copy_to_user(buf, kernel_buffer, mem_size) )
        {
                pr_err("Data Read : Err!\n");
        }
        pr_info("Data Read : Done!\n");
        return mem_size;
}


static ssize_t my_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
        //Copy the data to kernel space from the user-space
        if( copy_from_user(kernel_buffer, buf, len) )
        {
                pr_err("Data Write : Err!\n");
        }
        pr_info("Data Write : Done!\n");
        return len;
}


static int my_close(struct inode *inode, struct file *file)
{
        pr_info("Device File Closed...!!!\n");
        return 0;
}


static int mod_init(void)
{
	/* allocating major num */
	int ret;

	ret = alloc_chrdev_region(&dev,0,1,"venu_char");
	if(ret < 0){
		pr_info("driver registration failed\n");
		return-1;
	}
	pr_info("Driver registration sucess\n");
	pr_info("Maj:%d Min:%d\n",MAJOR(dev),MINOR(dev));

	/* creating cdev object*/
	cdev_init(&pcdDev,&fops);
	pr_info("cdev init success\n");

	/*adding cdev to system */
	ret = cdev_add(&pcdDev, dev, 1);
	if(ret < 0){
		pr_info("cannot add character device to system\n");
		return-1;
	}
	pr_info("char dev addition successful\n");

	/* creating struct class */
	dev_class = class_create("venus_class");
	if(dev_class == NULL){
		pr_info("Cannot create class\n");
		return-1;
	}
	pr_info("class created: venus_class\n");

	/* creating device file*/
	device_create(dev_class, NULL, dev, NULL, "venus_dev");

	pr_info("Device driver Init Successful\n");

	return 0;
	
}



static void mod_clean(void)
{
        device_destroy(dev_class,dev);
        class_destroy(dev_class);
        cdev_del(&pcdDev);
        unregister_chrdev_region(dev, 1);
        pr_info("Device Driver Remove...Done!!!\n");
}


module_init(mod_init);
module_exit(mod_clean);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Venus PCD Driver\n");
MODULE_DESCRIPTION("Simple PCD Driver\n");

