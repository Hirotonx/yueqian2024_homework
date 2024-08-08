#include <stdio.h>
#include <stdlib.h>
#define SIZE 1024

typedef char stack_data;

// 用于选择合适的格式控制符
#define FORMAT_SPECIFIER(x) _Generic((x), \
    int: "%d",                            \
    float: "%f",                          \
    double: "%lf",                        \
    char: "%c",                           \
    char *: "%s",                         \
    default: "%p")

typedef struct
{
    stack_data *stack; // 栈(数组实现)
    int size;          // 栈大小
} Stack;

// 初始化栈
Stack *init_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->stack = (stack_data *)malloc(sizeof(stack_data) * SIZE);
    stack->size = 0;
    return stack;
}

// 出栈并返回元素
stack_data pop(Stack *stack)
{
    stack_data res = stack->stack[stack->size - 1];
    stack->size--;
    return res;
}

// 入栈
void push(Stack *stack, stack_data val)
{
    stack->stack[stack->size++] = val;
}

// 查看栈顶元素
stack_data peek(Stack *stack)
{
    return stack->stack[stack->size - 1];
}

// 打印栈
void display(Stack *stack)
{
    for (int i = stack->size - 1; i >= 0; i--)
    {
        printf(FORMAT_SPECIFIER(stack->stack[i]), stack->stack[i]);
        printf(" -> ");
    }
    printf("栈底\n");
}

// 释放栈内存
void stack_free(Stack *stack)
{
    free(stack->stack);
    free(stack);
}

int main()
{
    Stack *stack = init_stack();
    push(stack, 'h');
    push(stack, 'e');
    push(stack, 'l');
    push(stack, 'l');
    push(stack, 'o');

    display(stack);
    stack_data current;
    while(stack->size > 0)
    {
        current = pop(stack);
        printf(FORMAT_SPECIFIER(current), current);
    }
}
