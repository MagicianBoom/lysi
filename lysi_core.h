#ifndef __LYSI_CORE_H
#define __LYSI_CORE_H

#include <asm/io.h>
#include <asm/uaccess.h>
#include <linux/cdev.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/errno.h>
#include <linux/gpio.h>
#include <linux/ide.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/of_gpio.h>
#include <linux/semaphore.h>
#include <linux/timer.h>
#include <linux/irq.h>
#include <linux/wait.h>
#include <linux/poll.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <linux/platform_device.h>

#define LYSI_CNT 1
#define LYSI_NAME "lysi_dev"

#define LYSI_TYPE               '?'
#define LYSI_MAGIC              100
#define LYSI_IOCTL_CMD0         (_IO(LYSI_TYPE, LYSI_MAGIC+0))
#define LYSI_IOCTL_CMD1         (_IO(LYSI_TYPE, LYSI_MAGIC+1))
#define LYSI_IOCTL_CMD2         (_IO(LYSI_TYPE, LYSI_MAGIC+2))
#define LYSI_IOCTL_CMD3         (_IO(LYSI_TYPE, LYSI_MAGIC+3))
#define LYSI_IOCTL_CMD4         (_IO(LYSI_TYPE, LYSI_MAGIC+4))
#define LYSI_IOCTL_CMD5         (_IO(LYSI_TYPE, LYSI_MAGIC+5))
#define LYSI_IOCTL_CMD6         (_IO(LYSI_TYPE, LYSI_MAGIC+6))
#define LYSI_IOCTL_CMD7         (_IO(LYSI_TYPE, LYSI_MAGIC+7))

#endif