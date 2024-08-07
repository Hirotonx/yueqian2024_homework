#include <stdio.h>
#include <stdlib.h>
#include "doubly_circular_linked_list.h"

ListNode *head = NULL;

ListNode *create_node(int val, int *arr)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    if (node == NULL)
    {
        perror("Failed to create node");
        return NULL;
    }
    node->val = val;
    node->next = node->back = NULL;
    node->arr = arr;
    if (head == NULL)
    {
        head = node;
        head->next = head->back = head;
    }
    return node;
}

void append(ListNode *node, ListNode *new_node)
{
    if (node == NULL || new_node == NULL)
        return;
    ListNode *tmp = node->next;
    node->next = new_node;
    new_node->next = tmp;
    new_node->back = node;
    if (tmp != NULL)
    {
        tmp->back = new_node;
    }
    if (node == head->back)
    {
        head->back = new_node;
        new_node->next = head;
    }
}

void pop(ListNode *node)
{
    if (node == NULL || node->next == NULL || node->next == head)
        return;
    ListNode *tmp = node->next->next;
    free(node->next);
    node->next = tmp;
    if (tmp != NULL)
    {
        tmp->back = node;
    }
}

int find(int target)
{
    if (head == NULL)
        return -1;
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
    } while (head != start && head != NULL);
    return -1;
}

void display(void)
{
    if (head == NULL)
        return;
    ListNode *start = head;
    do
    {
        printf(" %d <->", head->val);
        head = head->next;
    } while (head != start && head != NULL);
    printf(" %d\n", head->val);
}

void free_list(void)
{
    if (head == NULL)
        return;
    ListNode *current = head;
    do
    {
        ListNode *next = current->next;
        free(current);
        current = next;
    } while (current != head);
    head = NULL;
}