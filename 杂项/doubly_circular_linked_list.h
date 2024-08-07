#ifndef DOUBLY_CIRCULAR_LINKED_LIST_H
#define DOUBLY_CIRCULAR_LINKED_LIST_H

typedef struct ListNode
{
    int val;
    struct ListNode *next;
    struct ListNode *back;
    char *arr;
} ListNode;

extern ListNode *head;
// 创建节点
ListNode *create_node(int val, int *arr);

// 在节点node后插入节点
void append(ListNode *node, ListNode *new_node);

// 删除node后的一个节点
void pop(ListNode *node);

// 查找节点
int find(int target);

// 打印链表
void display(void);

//释放内存
void free_list(void);
#endif // DOUBLY_CIRCULAR_LINKED_LIST_H
