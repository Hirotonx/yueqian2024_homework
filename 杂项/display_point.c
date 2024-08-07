#include "display_point.h"
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int lcdfd = -1;
static void *lcd_mem = NULL;
static const size_t lcd_size = 800 * 480 * 4; 

int open_lcd()
{
    lcdfd = open("/dev/fb0", O_RDWR);
    if (lcdfd == -1)
    {
        perror("打开液晶屏失败");
        return -1;
    }

    lcd_mem = mmap(NULL, lcd_size, PROT_READ | PROT_WRITE, MAP_SHARED, lcdfd, 0);
    if (lcd_mem == MAP_FAILED)
    {
        perror("内存映射失败");
        close(lcdfd);
        lcdfd = -1;
        return -1;
    }

    return 0;
}

int display_lcd(unsigned int val, int lcd_index)
{
    if (lcdfd == -1 || lcd_mem == NULL)
    {
        fprintf(stderr, "液晶屏未初始化\n");
        return -1;
    }

    // 更新指定地址的像素值
    unsigned int *lcd_ptr = (unsigned int *)lcd_mem;
    lcd_ptr[lcd_index] = val;
    return 0;
}

void close_lcd()
{
    if (lcd_mem != NULL)
    {
        munmap(lcd_mem, lcd_size);
        lcd_mem = NULL;
    }
    if (lcdfd != -1)
    {
        close(lcdfd);
        lcdfd = -1;
    }
}
