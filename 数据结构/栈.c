#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1024
typedef struct
{
    int *stack;        // 栈(数组实现)
    int size;          //栈大小
} Stack;

//初始化栈
Stack *init_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->stack = malloc(sizeof(SIZE));
    stack->size = 0;
    return stack;
}

//出栈并返回元素
int *pop(Stack *stack)
{
    int res = stack->stack[stack->size - 1];
    stack->size--;
    return res;
}

//入栈
void push(Stack *stack, int val)
{
    stack->stack[stack->size++] = val;
}

int peek(Stack *stack)
{
    return stack->stack[stack->size - 1];
}

//打印栈
void display(Stack *stack)
{
    for (int i = stack->size - 1; i >= 0; i++)
    {
        printf("%d -> ", stack->stack[i]);
    }
    printf("栈底\n");
}

void stack_free(Stack *stack)
{

}