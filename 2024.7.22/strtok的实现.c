#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int place = 0;

char *strpop_(char *str, char rm_char)
{
    if (place >= strlen(str))
    {
        return NULL;
    }

    // 查找 rm_char 的位置
    int i = place;
    while (str[i] != rm_char && str[i] != '\0')
    {
        i++;
    }

    // 没匹配的情况
    if (str[i] == '\0')
    {
        // 计算需要分配的内存大小
        int len = strlen(str) - place;

        // 分配内存并复制前部分的字符串
        char *res = (char *)malloc((len + 1) * sizeof(char));
        strncpy(res, str + place, len);
        res[len] = '\0';

        // 更新 place 的位置到字符串末尾
        place = strlen(str);

        return res;
    }

    // 计算需要分配的内存大小
    int len = i - place;

    // 分配内存并复制前部分的字符串
    char *res = (char *)malloc((len + 1) * sizeof(char));
    strncpy(res, str + place, len);
    res[len] = '\0';

    place = i + 1; // 更新 place 的位置
    //printf("place: %d\n", place);

    return res;
}

int main()
{
    char test_str[] = "hello_world_test";
    char rm_char = '_';

    printf("原始字符串: %s\n", test_str);

    char *result;
    while ((result = strpop_(test_str, rm_char)) != NULL)
    {
        printf("结果为:  %s\n", result);
        free(result); // 释放内存
    }
}