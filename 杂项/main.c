#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include "display_point.h"
#include "doubly_circular_linked_list.h"
#include "touch_screen.h"
#include "read_bmp.h"

extern ListNode *head; 
void list_and_display_files(const char *path)
{
    DIR *dp;
    struct dirent *entry;
    int pic_idx = 0;
    ListNode *ptr = NULL;

    // 打开目录
    dp = opendir(path);
    if (dp == NULL)
    {
        perror("Failed to open directory");
        return;
    }

    // 读取目录中的条目
    while ((entry = readdir(dp)) != NULL)
    {
        // 忽略"."和".."目录
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        // 构建完整的文件路径
        char filepath[1024];
        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);

        // 读取BMP文件并创建新节点
        int *image = read_bmp_file(filepath);
        if (image == NULL)
        {
            fprintf(stderr, "Failed to read BMP file: %s\n", filepath);
            continue;
        }

        ListNode *new_node = create_node(pic_idx++, image);

        // 如果链表为空，则将新节点设为头节点
        if (head == NULL)
        {
            head = new_node;
            ptr = head;
        }
        else
        {
            // 在尾部插入新节点
            append(ptr, new_node);
            ptr = new_node;
        }
    }
    printf("读取内容完成\n");
    closedir(dp);
}

void node2lcd(ListNode *node)
{
    for (int i = 0; i < 800 * 480; i++)
    {
        display_lcd(i, node->arr[i]);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // 初始化设备
    open_lcd();
    open_touch_screen();

    list_and_display_files(argv[1]);
    printf("读取完成\n");
    int touch_count = 0;
    int touch_pos[2] = {0,0};
    if(head == NULL){printf("head是空指针");}
    printf("hi\n");
    display();
    ListNode *pic_ptr = head->next->next;
    printf("初始化完成");
    if (pic_ptr != NULL)
    {
        node2lcd(pic_ptr);
    }

    while (touch_count < 800)
    {
        touch_screen_pos(touch_pos);
        if (touch_pos[0] < 400)
        {
            if (pic_ptr != NULL)
            {
                pic_ptr = pic_ptr->back;
                if (pic_ptr != NULL)
                {
                    node2lcd(pic_ptr);
                }
            }
        }
        else
        {
            if (pic_ptr != NULL)
            {
                pic_ptr = pic_ptr->next;
                if (pic_ptr != NULL)
                {
                    node2lcd(pic_ptr);
                }
            }
        }
        touch_count++;
    }

    // 关闭设备
    close_lcd();
    touch_screen_free();

    // 释放内存
    free_list();

    return 0;
}
