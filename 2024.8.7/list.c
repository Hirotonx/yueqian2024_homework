#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// 构造函数
List *create()
{
    List *list = (List *)malloc(sizeof(List));
    list->size = 0;
    list->capacity = 10;
    list->extendRatio = 2;
    list->arr = malloc(sizeof(int) * list->capacity);
    return list;
}

// 析构函数
void del_list(List *list)
{
    free(list->arr);
    free(list);
}

// 访问元素
int get_val(List *list, int index)
{
    if (index < 0) { index = list->size + index; }

    if (index > list->size || index < 0)
    {
        printf("输入错误\n");
        return 0;
    }

    return list->arr[index];
}

// 更新元素
void replace(List *list, int index, int new_val)
{
    if (index < 0) { index = list->size + index; }

    if (index > list->size || index < 0)
    {
        printf("输入错误\n");
        return;
    }

    list->arr[index] = new_val;
}

// 扩容
void extend_capacity(List *list)
{
    int *new_arr = (int *)malloc(sizeof(int) * (list->capacity * list->extendRatio));
    if (new_arr == NULL)
    {
        printf("扩容失败\n");
        return;
    }
    for (int i = 0; i < list->size; i++) // 修正边界条件
    {
        new_arr[i] = list->arr[i];
    }

    free(list->arr);
    list->arr = new_arr;
    list->capacity *= list->extendRatio;
}

// 末尾添加元素
void append(List *list, int val)
{
    if (list->size + 1 > list->capacity) { extend_capacity(list); }
    list->arr[list->size++] = val;
}

// 查找
int find(List *list, int target)
{
    for (int i = 0; i < list->size; i++)
    {
        if (list->arr[i] == target)
        {
            return i;
        }
    }
    return -1; // 如果未找到，返回-1
}

// 删除
void remove_(List *list, int target)
{
    int index = find(list, target);
    if (index == -1)
    {
        printf("未找到目标元素\n");
        return;
    }
    for (int i = index; i < list->size - 1; i++)
    {
        list->arr[i] = list->arr[i + 1];
    }
    list->size--;
}

// 打印
void display(List *list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}

// 分区函数
int partition(int *arr, int left, int right)
{
    int mid = arr[right];
    int i = left;
    for (int j = left; j < right; j++)
    {
        if (arr[j] < mid)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
        }
    }
    int tmp = arr[right];
    arr[right] = arr[i];
    arr[i] = tmp;

    return i;
}

// 递归调用
void quick_sort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid_idx = partition(arr, left, right);
        quick_sort(arr, left, mid_idx - 1);
        quick_sort(arr, mid_idx + 1, right);
    }
}

// 快速排序
void sort(List *list)
{
    quick_sort(list->arr, 0, list->size - 1);
}
