#ifndef DISPLAY_POINT_H
#define DISPLAY_POINT_H

int open_lcd();                         // 打开液晶屏并映射内存
int display_lcd(unsigned int val, int lcd_index); // 更新指定地址的像素值
void close_lcd();                             // 关闭液晶屏并解除内存映射

#endif // DISPLAY_POINT_H
