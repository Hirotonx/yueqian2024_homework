#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*  封装一个函数，交换两个整数的值(加减法，乘除法，异或运算)*/
// 定义结构体
typedef struct Swap Swap;
struct Swap
{
    int *num1;
    int *num2;
    char *mode;
    void (*display)(Swap *self); // 函数指针，用于模拟成员函数
    // void (*add_sub_swap)(int *p1, int *p2);
    // void (*mul_div_swap)(int *p1, int *p2);
    // void (*xor_swap)(int *p1, int *p2);
    void (*swap_)(int *p1, int *p2);
};

void display(Swap *self)
{
    printf("使用 %s 方法交换后的值是\n num1 = %d\n num2 = %d\n", self->mode, *(self->num1), *(self->num2));
}

void add_sub_swap(int *p1, int *p2)
{
    *p1 += *p2;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;
}

void mul_div_swap(int *p1, int *p2)
{
    *p1 = *p1 * *p2;
    *p2 = *p1 / *p2;
    *p1 = *p1 / *p2;
}

void xor_swap(int *p1, int *p2)
{
    *p1 = *p1 ^ *p2;
    *p2 = *p1 ^ *p2;
    *p1 = *p1 ^ *p2;
}

// 构造函数
Swap *create_swap(int *num1, int *num2, char *mode)
{
    Swap *swap = (Swap *)malloc(sizeof(Swap));
    if ((*num1 == 0 || *num2 == 0) && strcmp(mode, "mul_div") == 0)
    {
        printf("有0无法进行乘除交换\n");
        mode = "无法交换";
    }

    if (swap != NULL)
    {
        swap->num1 = num1;
        swap->num2 = num2;
        swap->mode = mode;
        swap->display = display;

        if (strcmp(mode, "add_sub") == 0)
        {
            swap->swap_ = add_sub_swap;
        }
        else if (strcmp(mode, "mul_div") == 0)
        {
            swap->swap_ = mul_div_swap;
        }
        else if (strcmp(mode, "xor") == 0)
        {
            swap->swap_ = xor_swap;
        }
        else
        {
            swap->swap_ = NULL;
        }
    }

    return swap;
}

// 析构函数，释放分配的内存
void rm_obj(Swap * obj)
{
    if (obj != NULL)
    {
        free(obj);
    }
}

int main()
{
    int num1 = 10, num2 = 5;

    // 测试加减法交换
    Swap *swap1 = create_swap(&num1, &num2, "xor");
    if (swap1 != NULL && swap1->swap_ != NULL)
    {
        swap1->swap_(swap1->num1, swap1->num2);
        swap1->display(swap1);
        rm_obj(swap1);
    }

    return 0;
}