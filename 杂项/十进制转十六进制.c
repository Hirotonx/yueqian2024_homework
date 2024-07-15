#include <stdio.h>

int main(void)
{
    char hex_list[] = "0123456789ABCDEF";
    int number;
    printf("输入一个10进制数\n");
    scanf("%d", &number);
    if (number == 0)
    {
        printf("输出的结果是 0");
        return 0;
    }

    int tmp = number;         // 零时变量(每次除下来的)
    int add_val;              // 余数
    char tmp_list[20];        // 临时保存素组(倒序)
    int sign = 1;             // 符号位
    int index = 0;            // 索引
    char res[21];             // 返回值(正序)
    char *tmp_ptr = tmp_list; // 临时保存素组
    char *res_ptr = res;      // 结果的指针表示

    if (number < 0)
    {
        sign *= -1;
        number *= -1;
    }

    while (tmp != 0)
    {
        if (index >= 20)
        {
            printf("超出计算范围");
            return 0;
        }
        add_val = tmp % 16;
        *(tmp_ptr + index++) = hex_list[add_val]; // index++ = *(tmp_ptr + index) = hex_list[add_val];index++
        tmp = tmp / 16;
        printf("%d\n", index);
    }

    printf("%s\n", tmp_list); // 倒序数组2

    if (sign < 0)
    {
        *res_ptr = '-';
        res_ptr++;
    }

    for (int j = 0; j < index; j++)
    {
        *(res_ptr + j) = *(tmp_ptr + index - j - 1);
    }
    //*(res_ptr + 2) = '\0';

    printf("转换后的是%s", res);

    return 0;
}
