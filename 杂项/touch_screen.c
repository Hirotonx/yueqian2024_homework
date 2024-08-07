#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include "touch_screen.h"

// 触摸屏设备文件描述符
static int tsfd = -1;

//初始化触摸屏设备

int open_touch_screen()
{
    // 打开触摸屏设备
    tsfd = open(TOUCHSCREEN_DEV, O_RDWR);
    if (tsfd == -1)
    {
        perror("打开触摸屏失败");
        return -1;
    }
    return 0;
}

//释放触摸屏
void touch_screen_free()
{
    if (tsfd != -1)
    {
        close(tsfd);
        tsfd = -1;
    }
}

//获取触摸屏的坐标
int touch_screen_pos(int arr[2])
{
    if (tsfd == -1)
    {
        fprintf(stderr, "触摸屏未初始化\n");
        return -1;
    }

    struct input_event myevent;
    // 初始化坐标
    arr[0] = 0;
    arr[1] = 0;

    // 读取触摸屏点击的坐标位置
    if (read(tsfd, &myevent, sizeof(myevent)) < 0)
    {
        perror("读取触摸屏数据失败");
        return -1;
    }

    // 判断事件类型

    if (myevent.type == EV_ABS)
    {
        while(arr[0] == 0 || arr[1] ==0)
        {
            if (myevent.code == ABS_X)
            {
                arr[0] = myevent.value;
            }
            else if (myevent.code == ABS_Y)
            {
                arr[1] = myevent.value;
            }
        }
    }
    return 0;
}
