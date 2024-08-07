#ifndef TOUCH_SCREEN_H
#define TOUCH_SCREEN_H

// 定义触摸屏设备的路径
#define TOUCHSCREEN_DEV "/dev/input/event0"

int open_touch_screen();

void touch_screen_free();

int touch_screen_pos(int arr[2]);

#endif // TOUCH_SCREEN_H
