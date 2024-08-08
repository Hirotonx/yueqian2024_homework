#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int queue_data;

typedef struct ListNode
{
    queue_data val;
    struct ListNode *next;
    struct ListNode *back;
} ListNode;

ListNode *head = NULL;
ListNode *last = NULL;
static int queue_size = 0;

void init_queue(queue_data val)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    if (node == NULL)
    {
        perror("初始化失败");
        return;
    }
    node->val = val;
    node->next = NULL;
    node->back = NULL;

    head = node; // 头指针指向第一个节点
    last = node; // 尾指针指向第一个节点
    queue_size++;
}

// 尾部入队
int queue_push_last(queue_data val)
{
    if (last == NULL)
    {
        perror("队列尾未定义");
        return -1;
    }

    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->val = val;
    new_node->next = NULL;
    new_node->back = last;

    last->next = new_node;
    last = new_node;
    queue_size++;
    return 0;
}

// 头部入队
int queue_push_first(queue_data val)
{
    if (head == NULL)
    {
        perror("队列头未定义");
        return -1;
    }

    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->val = val;
    new_node->next = head;
    new_node->back = NULL;

    head->back = new_node;
    head = new_node;
    queue_size++;
    return 0;
}

// 查看队首元素
int queue_peek_first()
{
    return head->val;
}

// 查看队尾元素
int queue_peek_last()
{
    return last->val;
}

// 删除队首元素
queue_data queue_pop_first()
{
    queue_data res = head->val;

    ListNode *current = head->next;
    free(head);
    head = current;
    head->back = NULL;

    queue_size--;
    return res;
}

// 删除队尾元素
queue_data queue_pop_last()
{
    queue_data res = last->val;

    ListNode *current = last->back;
    free(last);
    last = current;
    last->next = NULL;
    queue_size--;
    return res;
}

void display_queue()
{
    ListNode *entry = head;
    while (entry != NULL)
    {
        printf(" %d ", entry->val);
        entry = entry->next;
    }
    printf("\n");
}

int main()
{
    // 初始化队列并插入第一个元素
    init_queue(10);

    // 尾部插入元素
    queue_push_last(20);
    queue_push_last(30);

    // 头部插入元素
    queue_push_first(5);
    queue_push_first(2);

    // 打印队列当前状态
    printf("当前队列内容：");
    display_queue();

    // 查看队首和队尾元素
    printf("队首元素: %d\n", queue_peek_first());
    printf("队尾元素: %d\n", queue_peek_last());

    // 从队首删除元素并打印
    printf("从队首删除元素: %d\n", queue_pop_first());
    printf("从队首删除后的队列内容：");
    display_queue();

    // 从队尾删除元素并打印
    printf("从队尾删除元素: %d\n", queue_pop_last());
    printf("从队尾删除后的队列内容：");
    display_queue();

    return 0;
}
