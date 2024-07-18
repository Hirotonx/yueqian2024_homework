#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char** RmNoEngStr(char (*arr)[20],int size)
{
    char** res = (char **)malloc(size * sizeof(char *));
    for (int i = 0; i < size;i++)
    {
        res[i] = (char *)malloc(20 * sizeof(char *));
        char *ptr = arr[i];
        char *res_p = res[i];
        int index = 0;//保存字符串的索引
        for (int j = 0; j < 20;j++)
        {
            if (*(ptr + j) >= 'a' && *(ptr + j) <= 'z' ||
            *(ptr + j) >= 'A' && *(ptr + j) <= 'Z')
            {
                *(res_p + index++) = *(ptr + j);
            }
            else{continue;}
        }
        *(res_p + index) = '\0';
    }
    return res;
}

int main()
{

    // 定义一个二维数组
    char arr[5][20] = {
        "Hello",
        "World123",
        "12345",
        "Test!@#",
        "AnotherOne"};
    // 调用函数
    char **result = RmNoEngStr(arr, 5);

    for (int i = 0; i < 5;i++)
    {
        printf("初始: %s -> 转换后: %s\n", arr[i], result[i]);
        free(result[i]);
    }
    free(result);
}