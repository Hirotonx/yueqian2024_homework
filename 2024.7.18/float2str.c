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
    int count_0 = 0;//防止0.00x的情况做的统计
    int sign = 0;//负数符号位
    if(num<0){num *= -1;}//负数转换成正数

    //不断对小数部分*10直到小数部分和强制转换整数后的值相等
    while((dec_num -(int)dec_num) != 0.0)
    {
        dec_num *= 10;
        if((int)dec_num == 0){count_0++;}//针对小数点后面的0单独计数1.001
    }
    //printf("%d",count_0);
    char *int_str = (char *)malloc(30 * sizeof(char *));
    char *dec_str = (char *)malloc(11 * sizeof(char *));
    //合并字符串
    int2str(int_num, int_str);//使用上面定义的 int2str函数把int类型转换成str类型
    int2str((int)dec_num, dec_str);
    if(sign)//处理负号的情况
    {
        char tmp[40] = "-";
        strcat(tmp, int_str);// 连接字符串
        strcpy(int_str, tmp);//拷贝回去
    }
    strcat(int_str, ".");//链接 小数点
    while(count_0)//把小数点后面的0加回去 1.001
    {
        strcat(int_str, "0");
        count_0--;
    }
    strcat(int_str, dec_str);//链接小数部分
    free(dec_str);//释放小数部分的字符串的内存
    return int_str;
}

int main()
{
    float testValue = 1.001;
    char *result = float2str(testValue);//调用函数

    printf("Float to String: %s\n", result);

    free(result);//释放正数部分的内存
    return 0;
}