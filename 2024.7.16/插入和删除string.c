#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_(char **arr, int idx, const char *insert_val)
{
    int arr_len = strlen(*arr);
    int insert_len = strlen(insert_val);

    // 计算新数组的长度
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

char *remove_(char *str, const char *rm_str)
{
    int len = strlen(str);
    int rm_len = strlen(rm_str);

    // 如果要删除的字符串比原字符串长，直接返回原字符串
    if (len < rm_len)
    {
        printf("输入有误\n");
        return NULL;
    }

    // 分配足够大的空间来存储结果，最多可能为原字符串长度
    char *res = (char *)malloc((len + 1) * sizeof(char));
    if (res == NULL)
    {
        printf("内存分配失败\n");
        return NULL;
    }

    int res_index = 0;
    int i = 0;
    while (i < len)
    {
        int match = 1;
        for (int j = 0; j < rm_len; j++)
        {
            if (i + j >= len || str[i + j] != rm_str[j])
            {
                match = 0;
                break;
            }
        }
        if (match)
        {
            i += rm_len; // 跳过已匹配的部分
        }
        else
        {
            res[res_index++] = str[i++];
        }
    }

    res[res_index] = '\0';

    // 释放原字符串内存
    free(str);

    return res;
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
    arr = remove_(arr, "insert_val");
    printf("删除后的字符串: %s\n", arr);

    // 释放内存
    free(arr);

    return 0;
}
