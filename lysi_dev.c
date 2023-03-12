#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/ide.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/gpio.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/of_gpio.h>
#include <linux/semaphore.h>
#include <linux/timer.h>
#include <linux/irq.h>
#include <linux/wait.h>
#include <linux/poll.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <linux/platform_device.h>
#include <asm/uaccess.h>
#include <asm/io.h>

static struct resource lysi_resources[] = {
    [0] = {
    },
};

static void lysi_release(struct device *dev)
{
    printk("lysi device released!\r\n");
}

static struct platform_device lysi_dev = {
    .name = "lysi",
    .id = -1,
    .dev = {
        .release = &lysi_release,
    },
    .num_resources = ARRAY_SIZE(lysi_resources),
    .resource = lysi_resources,
};

static int __init lysi_dev_init(void)
{
    return platform_device_register(&lysi_dev);
}

 static void __exit lysi_dev_exit(void)
{
    platform_device_unregister(&lysi_dev);
}

module_init(lysi_dev_init);
module_exit(lysi_dev_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("liuyang");