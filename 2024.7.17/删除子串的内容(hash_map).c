#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
写一个程序处理字符串A，处理规则是: 只要字符串B里面有的字符，不论大小写，一律从A字符串中删除
*/
char* remove_(char* str,const char* rm_str)
{
    char *res = (char *)malloc(strlen(str) * sizeof(char));
    int res_index = 0;
    //创建哈希map
    int hash[128] = {0};
    for (int i = 0; i < strlen(rm_str);i++)
    {
        if(rm_str[i] < 'a'){hash[rm_str[i] + 'a'] = 1;}
        else{hash[rm_str[i] - 'a'] = 1;}
        hash[rm_str[i]] = 1;
    }
    //
    for (int i = 0; i < strlen(str);i++)
    {
        if(hash[str[i]] == 1){continue;}
        else
        {
            res[res_index++] = str[i];
        }
    }
    res[res_index] = '\0';
    return res;
}
int main()
{
    char *test_str = "Hello, World!";
    char *test_rm_str = "o";

    char *result = remove_(test_str, test_rm_str);
    printf("Original: %s\n", test_str);
    printf("Removed: %s\n", result);
    free(result); // 释放内存
}