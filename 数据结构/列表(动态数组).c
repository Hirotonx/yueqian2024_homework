#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    int *arr;        // 数组（存储列表元素）
    int capacity;    // 列表容量
    int size;        // 列表大小
    int extendRatio; // 列表每次扩容的倍数
}List;

//构造函数
List *create()
{
    List *list = (List *)malloc(sizeof(List));
    list->size = 0;
    list->capacity = 10;
    list->extendRatio = 2;
    list->arr = malloc(sizeof(int) * list->capacity);
    return list;
}

//析构函数
void del_list(List *list)
{
    free(list->arr);
    free(list);
}

//访问元素
int get_val(List *list, int index)
{
    if(index < 0){index = list->size + index;}

    if(index > list->size || index <0)
    {
        printf("输入错误");
        return 0;
    }

    return (list->arr[index]);
}

//更新元素
void replace(List *list, int index, int new_val)
{
    if(index < 0){index = list->size + index;}

    if(index > list->size || index <0)
    {
        printf("输入错误");
        return;
    }

    list->arr[index] = new_val;
}

//扩容
void extend_capacity(List *list)
{
    int *new_arr = (int*)malloc(sizeof(int) * (list->capacity * list->extendRatio));
    if(new_arr == NULL)
    {
        printf("扩容失败");
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

//末尾添加元素
void append(List *list, int val)
{
    if(list->size + 1 > list->capacity){extend_capacity(list);}
    list->arr[list->size++] = val;
}

//查找
int find(List *list, int target)
{
    for (int i = 0; i < list->size;i++)
    {
        if(list->arr[i] == target)
        {
            return i;
        }
    }
}

//删除
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

//打印
void display(List *list)
{
    for (int i = 0; i < list->size;i++)
    {
        printf("%d ", list->arr[i]);
    }
    printf("\n");
}


//分区函数
int partition(int *arr,int left,int right)
{
    int mid = arr[right];
    int i = left;
    for (int j = left; j < right; j++)
    {
        if(arr[j]<mid)
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

//递归调用
void quick_sort(int *arr,int left,int right)
{
    if(left<right)
    {
        int mid_idx = partition(arr, left, right);
        quick_sort(arr, left, mid_idx - 1);
        quick_sort(arr, mid_idx + 1, right);
    }
}
//快速排序
void sort(List *list)
{
    quick_sort(list->arr, 0, list->size - 1);
}

int main()
{
    // 创建列表
    List *list = create();

    // 末尾添加元素
    append(list, 3);
    append(list, 1);
    append(list, 4);
    append(list, 1);
    append(list, 5);
    append(list, 9);
    append(list, 2);
    append(list, 6);
    append(list, 5);

    // 打印列表
    printf("初始列表: ");
    display(list);

    // 获取某个索引处的值
    printf("索引2处的值: %d\n", get_val(list, 2));

    // 更新某个索引处的值
    replace(list, 2, 7);
    printf("更新后的列表: ");
    display(list);

    // 查找某个值
    int index = find(list, 9);
    printf("值9的索引: %d\n", index);

    // 删除某个值
    remove_(list, 1);
    printf("删除值1后的列表: ");
    display(list);

    // 对列表进行排序
    sort(list);
    printf("排序后的列表: ");
    display(list);

    // 删除列表
    del_list(list);

    return 0;
}
