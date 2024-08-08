#include <stdio.h>
#include <stdlib.h>

typedef int link_list_data; // 链表的数据类型

typedef struct ListNode
{
    link_list_data val;
    struct ListNode *next;
    struct ListNode *back;
} ListNode;

ListNode *head = NULL;
ListNode *last = NULL;

ListNode *create_node(link_list_data val) // 创建节点
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    node->back = NULL;
    return node;
}

void append_last(ListNode *new_node) // 在链表末尾插入一个节点
{
    if (head == NULL)
    {
        head = new_node;
        last = new_node;
    }
    else
    {
        last->next = new_node;
        new_node->back = last;
        last = new_node;
    }
}

void append_head(ListNode *new_node) // 在链表头尾插入一个节点
{
    if (head == NULL)
    {
        head = new_node;
        last = new_node;
    }
    else
    {
        head->back = new_node;
        new_node->next = head;
        head = new_node;
    }
}

// 析构函数
void free_linked_list()
{
    ListNode *current = head;
    ListNode *next_node;

    while (current != NULL)
    {
        next_node = current->next; // 保存下一个节点
        free(current);             // 释放当前节点
        current = next_node;       // 移动到下一个节点
    }
}

void display()
{
    ListNode *current = head;
    printf("NULL <-> ");
    while (current != NULL)
    {
        printf("%d <-> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

void quick_sort(int *arr, int left, int right)
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
        quick_sort(arr, left, i - 1);
        quick_sort(arr, i + 1, right);
    }
}
int main()
{
    int input[12] = {5, 1, 9, 3, 7, 2, 12, 8, 6, 4, 11, 10};
    int size = sizeof(input) / sizeof(input[0]);
    int odd_arr[size];
    int even_arr[size];
    int odd_idx = 0;
    int even_idx = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] % 2 == 0)
        {
            odd_arr[odd_idx++] = input[i];
        }
        else
        {
            even_arr[even_idx++] = input[i];
        }
    }

    // 排序
    quick_sort(odd_arr, 0, odd_idx - 1);
    quick_sort(even_arr, 0, even_idx - 1);

    for (int i = 0; i < odd_idx; i++)
    {
        append_last(create_node(odd_arr[i]));
    }
    for (int i = 0; i < even_idx; i++)
    {
        append_head(create_node(even_arr[i]));
    }
    display();
    free_linked_list();
}
