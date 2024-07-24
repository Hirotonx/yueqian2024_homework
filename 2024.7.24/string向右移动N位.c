#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void move_right(char* str, const int num)
{
    int len = strlen(str);
    char tmp[num];
    //保存末尾的
    int tmp_idx = 0;
    for (int i = len - num ; i <= len - 1;i++)
    {
        tmp[tmp_idx++] = str[i];
    }
    //其他的向后移动
    for (int i = len - 1; i >= num - 1;i--)
    {
        str[i] = str[i - num];
    }
    //末尾的一过来
    for (int i = 0; i < num;i++)
    {
        str[i] = tmp[i];
    }
} 

int main()
{
    char str[10] = "hello";
    move_right(str, 2);
    printf("%s", str);
}