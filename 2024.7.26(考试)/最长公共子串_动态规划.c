#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *longest_common_substring(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **dp = (int **)malloc((len1 + 1) * sizeof(int *));
    int end = 0; // 共同子串的末尾索引
    int res_len = 0; // 共同子串的最大长度
    //初始化数组为0
    for (int i = 0; i <= len1; i++)
    {
        dp[i] = (int *)malloc((len2 + 1) * sizeof(int));
        memset(dp[i], 0, (len2 + 1) * sizeof(int)); // 初始化数组为0
    }
    //开始创建dp矩阵
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > res_len)
                {
                    res_len = dp[i][j];
                    end = i;
                }
            }
        }
    }

    // 保存结果
    char *res = (char *)malloc(sizeof(char) * (res_len + 1));
    int idx = 0;
    for (int i = end - res_len; i < end; i++)
    {
        res[idx++] = str1[i];
    }
    res[res_len] = '\0';

    // 释放dp数组的内存
    for (int i = 0; i <= len1; i++)
    {
        free(dp[i]); // 释放dp数组的每一行
    }
    free(dp);
    return res;
}

int main()
{
    char str1[] = "abcdef";
    char str2[] = "zcdemf";

    char *result = longest_common_substring(str1, str2);

    printf("Longest common substring: %s\n", result);

    free(result); 

    return 0;
}