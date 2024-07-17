#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_(char **arr, int idx, const char *insert_val)
{
    int arr_len = strlen(*arr);
    int insert_len = strlen(insert_val);

    // 新数组的长度
    int new_len = arr_len + insert_len;

    // 分配新空间
    *arr = (char *)realloc(*arr, (new_len + 1) * sizeof(char));
    if (*arr == NULL)
    {
        printf("内存分配失败\n");
        return;
    }

    // 后移插入位置后的字符
    for (int i = arr_len; i >= idx; i--)
    {
        (*arr)[i + insert_len] = (*arr)[i];
    }

    // 插入新字符串
    for (int i = 0; i < insert_len; i++)
    {
        (*arr)[idx + i] = insert_val[i];
    }
}

//双指针
void remove_(char *str, const char *rm_str)
{
    int len = strlen(str);
    int rm_len = strlen(rm_str);

    
    for (int end = 0; end <= len - rm_len;)
    {
        int match = 1;
        // 检查是否匹配子字符串
        for (int beg = 0; beg < rm_len; beg++)
        {
            if (str[beg + end] != rm_str[beg])
            {
                match = 0;
                break;
            }
        }

        if (match)
        {
            
            for (int j = end; j < len - rm_len; j++)
            {
                str[j] = str[j + rm_len];
            }
            len -= rm_len; // 更新字符串长度
        }
        else
        {
            end++; 
        }
    }
    str[len] = '\0'; // 添加字符串结束符
}
int main(void)
{
    char *arr = (char *)malloc(20 * sizeof(char));
    strcpy(arr, "Hello World!");
    printf("原始字符串: %s\n", arr);

    // 在指定位置插入字符串
    insert_(&arr, 6, "insert_val ");
    printf("插入后的字符串: %s\n", arr);

    // 删除字符串
    remove_(arr, "insert_val");
    printf("删除后的字符串: %s\n", arr);

    // 释放内存
    free(arr);

    return 0;
}
