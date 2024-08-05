#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct ListNode
{
    int score;
    int age;
    char *name;
    struct ListNode *next;
} ListNode;

ListNode *create_node(int score, char *name, int age) // 创造节点
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->score = score;
    node->age = age;
    node->name = name;
    node->next = NULL;
    return node;
}

void append(ListNode *node, ListNode *new_node)//在节点node的后面插入一个节点
{
    ListNode *tmp = node->next;
    node->next = new_node;
    new_node->next = tmp;
}

void append_end(ListNode *head, ListNode *new_node) // 在末尾节点node的后面插入一个节点
{   
    while(head->next != NULL)
    {
       head = head->next;
    }
    head->next = new_node;
}
void display(ListNode *head)
{
    printf("head -->");
    while (head != NULL)
    {
        printf(" --> [%s ,%d ,%d ]",head->name,head->age,head->score);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    // 创建节点
    ListNode *head = create_node(90, "A", 20);
    ListNode *node1 = create_node(85, "B", 21);
    ListNode *node2 = create_node(92, "C", 22);
    ListNode *node3 = create_node(88, "D", 23);

    // 测试 append_end
    append_end(head, node1);
    append_end(head, node2);
    append_end(head, node3);

    // 显示链表内容
    printf("链表内容: ");
    display(head);

    // 测试 append
    ListNode *node4 = create_node(95, "Eva", 24);
    append(node2, node4); // 在node2后插入node4

    // 显示链表内容
    printf("在C后插入Eva后的链表内容: ");
    display(head);

    // 释放内存
    ListNode *current = head;
    while (current != NULL)
    {
        ListNode *next = current->next;
        free(current);
        current = next;
    }
}