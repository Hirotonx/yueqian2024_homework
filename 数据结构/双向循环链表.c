#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct ListNode
{
    int val;
    struct ListNode *next;
    struct ListNode *back;

} ListNode;

ListNode *create_node(int val) // 创造节点
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    node->back = NULL;
    return node;
}


void link_loop(ListNode *head)
{
    ListNode *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = head;
    head->back = tail;
}

void append(ListNode *node, ListNode *new_node) // 在节点node的后面插入一个节点
{
    ListNode *tmp = node->next;
    node->next = new_node;
    new_node->next = tmp;
    new_node->back = node;
    if (tmp != NULL)
    {
        tmp->back = new_node;
    }
}

void pop(ListNode *node) // 删除node后的一个节点
{
    if (node->next == NULL)
        return;

    ListNode *tmp = node->next->next;
    free(node->next);
    node->next = tmp;
    if (tmp != NULL)
    {
        tmp->back = node;
    }
}

int find(ListNode *head, int target) // 输入链表头,查找target的首个位置
{
    int res = 0;
    ListNode *start = head;
    do
    {
        if (head->val == target)
        {
            return res;
        }
        res++;
        head = head->next;
    } while (head != start);
    return -1;
}

void display(ListNode *head)
{
    ListNode *start = head;
    do
    {
        printf(" %d <->", head->val);
        head = head->next;
    } while (head != start);
    printf(" %d\n", head->val); // To complete the circular display
}

int main()
{
    // 创建链表头节点
    ListNode *head = create_node(1);
    // 插入节点
    append(head, create_node(2));
    append(head->next, create_node(3));
    append(head->next->next, create_node(4));

    // 创建循环链表
    link_loop(head);

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
    pop(head->next); // 这里删除第二个节点（值为2的节点）
    display(head);

    // 释放链表节点
    ListNode *start = head;
    do
    {
        ListNode *tmp = head;
        head = head->next;
        free(tmp);
    } while (head != start);

    return 0;
}