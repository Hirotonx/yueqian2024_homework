#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 两个字符串的最子串(修正版)*/


char *ReturnLongestSubstr(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *res = (char *)malloc((len1 + 1) * sizeof(char));//第一个错误没用堆空间
    char *tmp = (char *)malloc((len1 + 1) * sizeof(char));
    res[0] = '\0';

    for (int i = 0; i < len1; i++)
    {
        int idx = 0;     // 保存结果的索引
        int idx_tmp = i; // str1 和 str2 开始比较位置的索引
        for (int j = 0; j < len2 && idx_tmp < len1; j++)//第一个错误索引错误 idx_tmp应该是<len 而不是idx_tmp+j<len1
        {
            if (str1[idx_tmp] == str2[j])
            {
                tmp[idx++] = str2[j];
                idx_tmp++;
            }
            else
            {
                if (idx > strlen(res))
                {
                    tmp[idx] = '\0';
                    strcpy(res, tmp);
                }
                idx_tmp = i;//第三个错误这里是等于i 不是等于0
                idx = 0;
            }
        }
        if (idx > strlen(res))
        {
            tmp[idx] = '\0';
            strcpy(res, tmp);
        }
    }

    free(tmp);
    return res;
}

int main()
{
    char str1[] = "123456669";
    char str2[] = "22442669242";
    char *result = ReturnLongestSubstr(str1, str2);

    printf("Longest common substring between '%s' and '%s' is '%s'\n", str1, str2, result);

    // 释放分配的内存
    free(result);

    return 0;
}
