#include <stdio.h>
#include<stdlib.h>
#include<string.h>


void int2str(int input, char *res)
{
    int tmp[11]; // 倒序数组
    int i = 0;

    // 处理输入整数并倒序存储每一位
    while (input != 0)
    {
        tmp[i++] = input % 10;
        input /= 10;
    }

    // 将倒序数组转换成字符串
    res[i] = '\0';
    int index = 0;
    for (int j = i - 1; j >= 0; j--)
    {
        res[index++] = (char)(tmp[j] + '0');
    }
}

char* float2str(float num)
{
    int int_num = (int)num;//整数部分
    float dec_num = num - (int)num;//小数部分
    int count_0 = 0;//防止0.00x的情况

    while((dec_num -(int)dec_num) != 0.0)
    {
        dec_num *= 10;
        if((int)dec_num == 0){count_0++;}
    }
    //printf("%d",count_0);
    char *int_str = (char *)malloc(30 * sizeof(char *));
    char *dec_str = (char *)malloc(11 * sizeof(char *));
    //合并字符串
    int2str(int_num, int_str);
    int2str((int)dec_num, dec_str);
    strcat(int_str, ".");
    while(count_0)
    {
        strcat(int_str, "0");
        count_0--;
    }
    strcat(int_str, dec_str);

    return int_str;
}

int main()
{
    float testValue = 1.001;
    char *result = float2str(testValue);

    printf("Float to String: %s\n", result);

    free(result);
    return 0;
}