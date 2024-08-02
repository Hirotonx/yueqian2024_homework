#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <sys/mman.h>
#include <stdlib.h>

int main(int argc ,char** argv)
{
    FILE *file = fopen("1.bmp","r");

    int lcdfd, filefd;
    unsigned int color;
    void *lcd_mem;
    size_t lcd_size = 800 * 480 * 4; // 假设800x480分辨率，每个像素4字节
    unsigned int bytesRead;

    // 打开液晶屏的驱动
    lcdfd = open("/dev/fb0", O_RDWR);
    if (lcdfd == -1)
    {
        printf("打开液晶屏失败了!\n");
        return -1;
    }

    // 将液晶屏的驱动文件映射到内存
    lcd_mem = mmap(NULL, lcd_size, PROT_READ | PROT_WRITE, MAP_SHARED, lcdfd, 0);
    if (lcd_mem == MAP_FAILED)
    {
        printf("内存映射失败!\n");
        close(lcdfd);
        return -1;
    }
    // 将文件指针移动到55字节处
    fseek(file, 55, SEEK_SET);
    // 按行读取pixels.txt中的ARGB数据并写入映射的内存
    
    unsigned int *lcd_ptr = (unsigned int *)lcd_mem;
    unsigned int idx = 0;
    while ((bytesRead = fread(&color, 1, 3, file)) > 0)
    {
        unsigned int b = ((color >>16)& 0xFF);//0xbb
        unsigned int g = ((color >> 8) & 0xFF);
        unsigned int r = ((color) & 0xFF);
        
        color = (r << 16) | (g << 8) | b;  //  RGB
        color |= 0xFF000000; 

        lcd_ptr[idx++] = color;
    }

    // 关闭文件和解除内存映射
    fclose(file);
    munmap(lcd_mem, lcd_size);
    close(lcdfd);
}
