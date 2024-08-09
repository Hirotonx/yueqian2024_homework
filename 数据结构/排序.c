#include <stdio.h>
#include <stdlib.h>

// 快速排序 Hoare分区
void quick_sort_H(int *arr, int left, int right)
{
    if (left >= right) return;

    int mid = arr[(left + right) >> 1];//中间值
    int i = left - 1;
    int j = right + 1;
    while (i < j)
    {
        while (arr[++i] < mid){;}//找到交换元素
        while (arr[--j] > mid){;}
        
        if (i >= j) break;
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    quick_sort_H(arr, left, j);
    quick_sort_H(arr, j + 1, right);
}

// 快速排序Lomuto分区
void quick_sort_L(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = arr[right];
        int i = left;
        for (int j = left; j < right; j++)
        {
            if (arr[j] < mid)
            {
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
                i++;
            }
        }
        int tmp = arr[right];
        arr[right] = arr[i];
        arr[i] = tmp;
        quick_sort_L(arr, left, i - 1);
        quick_sort_L(arr, i + 1, right);
    }
}

//插入排序
void insert_sort(int nums[], int size)
{
    
    for (int i = 1; i < size; i++)
    {
        int base = nums[i];
        int j = i - 1;
        // 插入
        while (j >= 0 && nums[j] > base)
        {
            //向右移动
            nums[j + 1] = nums[j];
            j--;
        }
        // 将 base 赋值到正确位置
        nums[j + 1] = base;
    }
}

//选择排序
void select_sort(int *nums,int size)
{
    int min_idx;
    for (int i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (nums[j] < nums[min_idx])
            {
                min_idx = j;
            }
        }
        // 交换元素
        int tmp = nums[i];
        nums[i] = nums[min_idx];
        nums[min_idx] = tmp;
    }
}