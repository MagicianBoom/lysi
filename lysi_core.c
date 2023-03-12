#include "lysi_core.h"

/* lysi_dev 设备结构体 */
struct lysi_device {
    dev_t devid;           /* 设备号 */
    struct cdev cdev;      /* cdev */
    struct class *class;   /* 类 */
    struct device *device; /* 设备 */
    int major;             /* 主设备号 */
    int minor;             /* 次设备号 */
};

struct lysi_device lysi_dev;

static int lysi_open(struct inode *inode, struct file *filp)
{
    filp->private_data = &lysi_dev;
    return 0;
}

static ssize_t lysi_read(struct file *filp, char __user *buf, size_t cnt,
                         loff_t *offt)
{
  return 0;
}

static ssize_t lysi_write(struct file *filp, const char __user *buf, size_t cnt,
                          loff_t *offt)
{
    return 0;
}

static int lysi_release(struct inode *inode, struct file *filp)
{
    return 0;
}

static long lysi_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
    int ret;

    switch(cmd) {
    case LYSI_IOCTL_CMD0:
        printk("LY_DEBUG===> %s: ioctl cmd0\r\n", __func__);
        return 0;
    case LYSI_IOCTL_CMD1:
        printk("LY_DEBUG===> %s: ioctl cmd1\r\n", __func__);
        return 0;
    case LYSI_IOCTL_CMD2:
        printk("LY_DEBUG===> %s: ioctl cmd2\r\n", __func__);
        return 0;
    case LYSI_IOCTL_CMD3:
        printk("LY_DEBUG===> %s: ioctl cmd3\r\n", __func__);
        return 0;
    case LYSI_IOCTL_CMD4:
        printk("LY_DEBUG===> %s: ioctl cmd4\r\n", __func__);
        return 0;
    case LYSI_IOCTL_CMD5:
        printk("LY_DEBUG===> %s: ioctl cmd5\r\n", __func__);
        return 0;
    case LYSI_IOCTL_CMD6:
        printk("LY_DEBUG===> %s: ioctl cmd6\r\n", __func__);
        return 0;
    case LYSI_IOCTL_CMD7:
        printk("LY_DEBUG===> %s: ioctl cmd7\r\n", __func__);
        return 0;
    default:
        printk("LY_DEBUG===> %s: cmd error\r\n", __func__);
    }

    return ret;
}

static struct file_operations lysi_fops = {
    .owner = THIS_MODULE,
    .open = lysi_open,
    .read = lysi_read,
    .write = lysi_write,
    .release = lysi_release,
    .unlocked_ioctl = lysi_ioctl,
};

static int lysi_probe(struct platform_device *dev)
{
    /* 注册字符设备 */
    /* 1、创建设备号 */
    if (lysi_dev.major) {
        lysi_dev.devid = MKDEV(lysi_dev.major, 0);
        register_chrdev_region(lysi_dev.devid, LYSI_CNT, LYSI_NAME);
    } else {
        alloc_chrdev_region(&lysi_dev.devid, 0, LYSI_CNT, LYSI_NAME);
        lysi_dev.major = MAJOR(lysi_dev.devid);
    }
    printk("LY_DEBUG===> lysi_dev major=%d,minor=%d\r\n", lysi_dev.major, lysi_dev.minor);

    /* 2、初始化 cdev */
    lysi_dev.cdev.owner = THIS_MODULE;
    cdev_init(&lysi_dev.cdev, &lysi_fops);

    /* 3、添加一个 cdev */
    cdev_add(&lysi_dev.cdev, lysi_dev.devid, LYSI_CNT);

    /* 4、创建类 */
    lysi_dev.class = class_create(THIS_MODULE, LYSI_NAME);
    if (IS_ERR(lysi_dev.class)) {
        return PTR_ERR(lysi_dev.class);
    }

    /* 5、创建设备 */
    lysi_dev.device = device_create(lysi_dev.class, NULL, lysi_dev.devid,
                                        NULL, LYSI_NAME);
    if (IS_ERR(lysi_dev.device)) {
        return PTR_ERR(lysi_dev.device);
    }

    printk("LY_DEBUG===> %s: lysi regiser successful\r\n", __func__);

    return 0;

}

static int lysi_remove(struct platform_device *dev)
{
    cdev_del(&lysi_dev.cdev);
    unregister_chrdev_region(lysi_dev.devid, LYSI_CNT);
    device_destroy(lysi_dev.class, lysi_dev.devid);
    class_destroy(lysi_dev.class);
    return 0;
}

static struct platform_driver lysi_driver = {
    .driver = {
        .name = "lysi",
    },
    .probe = lysi_probe,
    .remove = lysi_remove,
};

static int __init lysi_init(void)
{
    return platform_driver_register(&lysi_driver);
}

static void __exit lysi_exit(void)
{
    platform_driver_unregister(&lysi_driver);
    printk("LY_DEBUG===> %s: lysi exit successful\r\n", __func__);
}

module_init(lysi_init);
module_exit(lysi_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("liuyang");