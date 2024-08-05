#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode *create_node(int val)//创造节点
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void append(ListNode *node, ListNode *new_node)//在节点node的后面插入一个节点
{
    ListNode *tmp = node->next;
    node->next = new_node;
    new_node->next = tmp;
}

void pop(ListNode *node)//删除node后的一个节点
{
    if(node->next == NULL)return;

    ListNode *tmp = node->next->next;
    free(node->next);
    node->next = tmp;
}

int find(ListNode *head,int target)//输入链表头,查找target的首个位置
{
    int res = 0;
    while(head->next != NULL)
    {
        if(head->val == target){return res;}
        res++;
        head = head->next;
    }
}

void display(ListNode *head)
{
    while(head->next != NULL)
    {
        printf(" %d -> %d", head->val, head->next->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    // 创建链表头节点
    ListNode *head = create_node(1);
    // 插入节点
    append(head, create_node(2));
    append(head, create_node(3));
    append(head, create_node(4));

    printf("链表内容: ");
    display(head); // 打印链表内容

    // 查找节点
    int pos = find(head, 3);
    if (pos != -1)
    {
        printf("值3的第一个位置: %d\n", pos);
    }
    else
    {
        printf("链表中未找到值3\n");
    }

    // 删除节点
    printf("删除节点值3后的链表内容: ");
    pop(head->next); 
    display(head);

    // 释放链表节点
    while (head != NULL)
    {
        ListNode *tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}