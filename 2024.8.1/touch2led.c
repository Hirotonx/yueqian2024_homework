#include "ALL_IO_HeadFiles.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

/*
	系统IO读取触摸屏的坐标
	触摸屏是输入设备(键盘也是输入设备)
	新知识：
		输入子系统模型：linux给程序员开发输入类型的设备驱动或者应用程序提供的一个框架
*/

int main(int argc, char **argv)
{
	static int pos_x = 0;
	static int pos_y = 0;
	int led[4] = {0, 0, 0, 0};
	char buf[2] = {0, 8};
	int tsfd;
	int led_fd;
	// 定义一个结构体存放触摸屏的坐标
	struct input_event myevent;

	// 第一步：打开触摸屏的驱动
	tsfd = open("/dev/input/event0", O_RDWR);
	if (tsfd == -1)
	{
		printf("打开触摸屏失败了!\n");
		return -1;
	}

	// 打开LED驱动
	led_fd = open("/dev/led_drv", O_RDWR);
	if (led_fd == -1)
	{
		printf("打开灯失败了!\n");
		close(tsfd);
		return -1;
	}

	for (size_t i = 0; i < 4; i++)
	{
		buf[0] = 0;
		buf[1] = 8 + i;
		write(led_fd, buf, 2);
	}

	while (1)
	{
		// 读取触摸屏点击的坐标位置
		read(tsfd, &myevent, sizeof(myevent));

		// 判断事件类型
		if (myevent.type == EV_ABS) // 说明是触摸屏的驱动
		{
			// 判断是x坐标，还是y坐标
			if (myevent.code == ABS_X) // 说明读取的x坐标
			{
				pos_x = myevent.value;
				printf("x坐标是: %d\n", pos_x);
			}
			if (myevent.code == ABS_Y) // 说明读取的y坐标
			{
				pos_y = myevent.value;
				printf("y坐标是: %d\n", pos_y);
			}
		}

		if (pos_x || pos_y)
		{
			if (pos_x < 200)
			{
				led[0] = !led[0];
				buf[0] = led[0];
				buf[1] = 8;
				write(led_fd, buf, 2);
			}
			else if (pos_x >= 200 && pos_x < 400)
			{
				led[1] = !led[1];
				buf[0] = led[1];
				buf[1] = 9;
				write(led_fd, buf, 2);
			}
			else if (pos_x >= 400 && pos_x < 600)
			{
				led[2] = !led[2];
				buf[0] = led[2];
				buf[1] = 10;
				write(led_fd, buf, 2);
			}
			else if (pos_x >= 600)
			{
				led[3] = !led[3];
				buf[0] = led[3];
				buf[1] = 7;
				write(led_fd, buf, 2);
			}
			pos_y = 0;
			pos_x = 0;
		}
	}
	// 关闭文件描述符
	close(tsfd);
	close(led_fd);
	return 0;
}
