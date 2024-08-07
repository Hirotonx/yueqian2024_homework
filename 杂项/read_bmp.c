#include "read_bmp.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 480

//读取bmp文件返回 像素点list
int *read_bmp_file(const char *file_path)
{
    FILE *file = fopen(file_path, "rb");
    if (!file)
    {
        perror("打开BMP文件失败");
        return NULL;
    }

    // 移动文件指针到像素数据的起始位置（假设BMP文件头大小为54字节）
    fseek(file, 54, SEEK_SET);

    // 为像素数据分配内存
    int *pixels = (int *)malloc(WIDTH * HEIGHT * sizeof(int));
    if (!pixels)
    {
        perror("内存分配失败");
        fclose(file);
        return NULL;
    }

    // 读取像素数据
    unsigned int color;
    unsigned int bytesRead;
    unsigned int idx = 0;
    while ((bytesRead = fread(&color, 1, 3, file)) > 0 && idx < WIDTH * HEIGHT)
    {
        unsigned int b = (color & 0xFF);
        unsigned int g = (color >> 8) & 0xFF;
        unsigned int r = (color >> 16) & 0xFF;

        color = (r << 16) | (g << 8) | b; // RGB
        color |= 0xFF000000;            

        pixels[idx++] = color;
    }

    fclose(file);
    return pixels;
}
