#include <stdio.h>
// int main()
// {
//     char input[20];
//     scanf("%s",input);
//     printf("%s", input);
// }

int main()
{
    int input;
    int tmp[11]; // 倒序数组
    char res[11];
    printf("输入一个整数");
    scanf("%d", &input);
    int i = 0;
    for (i; input != 0; i++)
    {
        tmp[i] = input % 10;
        input /= 10;
    }

    res[i--] = '\0';
    int index = 0;
    for (i; i >= 0; i--)
    {
        res[i] = (char)(tmp[index++] + '0');
        // printf("---%s\n", res);
    }

    printf("转换后的字符串是: %s", res);
}