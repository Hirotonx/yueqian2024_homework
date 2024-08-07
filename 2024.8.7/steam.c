#include <stdio.h>
#include <stdlib.h>
#include "kernel_list.h"
#include "list.h"

#define BIG 0x01
#define MID 0x02
#define SMALL 0x03

// 声明全局变量
List *rm_list;

typedef struct
{
    struct list_head list;
    int waybill_num; // 修改为 int
    char *beg_time;
    char *send_addr;
    char *get_addr;
    unsigned char package_kind;
} ListNode;

ListNode *create_node(int waybill_num, char *beg_time, char *send_addr,
                      char *get_addr, unsigned char package_kind) // 创造节点
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->waybill_num = waybill_num;
    node->beg_time = beg_time;
    node->send_addr = send_addr;
    node->get_addr = get_addr;
    node->package_kind = package_kind;
    INIT_LIST_HEAD(&node->list);
    return node;
}

void append_(struct list_head *head, ListNode *new_node) // 在链表头后面插入一个节点
{
    list_add_tail(&new_node->list, head);
}

int find_and_remove(struct list_head *head, int target) // 查找并删除目标元素
{
    int pos = 0;
    ListNode *entry, *tmp;
    list_for_each_entry_safe(entry, tmp, head, list) // 使用 list_for_each_entry_safe 遍历
    {
        if (entry->waybill_num == target)
        {
            append(rm_list, entry->waybill_num);
            list_del(&entry->list);
            free(entry);
            printf("已经删除包裹 %d\n", get_val(rm_list, rm_list->size - 1));
            return pos; // 返回删除元素的位置
        }
        pos++;
    }
    return -1; // 未找到目标元素
}

void display_all_kind_pag(struct list_head *head, int kind)
{
    int pos = 0;
    ListNode *entry, *tmp;
    char *pag_kind[] = {"空", "大", "中", "小"};
    list_for_each_entry_safe(entry, tmp, head, list) // 使用 list_for_each_entry_safe 遍历
    {
        if (entry->package_kind == kind)
        {
            printf("快递单号 %d \n 订单发起时间 %s \n 发送地址 %s \n 接收地址 %s \n 包裹类型 %s \n",
                   entry->waybill_num, entry->beg_time, entry->send_addr, entry->get_addr, pag_kind[entry->package_kind]);
        }
        pos++;

    }
    printf("\n\n");
}

int main()
{
    // 初始化链表头
    LIST_HEAD(my_list);

    // 初始化 rm_list
    rm_list = (List *)malloc(sizeof(List));

    // 创建并添加节点
    ListNode *node1 = create_node(1, "2024-08-01", "江西", "广东", BIG);
    ListNode *node2 = create_node(2, "2024-08-02", "新疆", "深圳", MID);
    ListNode *node4 = create_node(4, "2024-08-02", "新疆", "大阪", MID);
    ListNode *node5 = create_node(5, "2024-08-02", "上海", "东京", MID);
    ListNode *node3 = create_node(3, "2024-08-03", "霓虹", "US", SMALL);

    append_(&my_list, node1);
    append_(&my_list, node2);
    append_(&my_list, node3);
    append_(&my_list, node4);
    append_(&my_list, node5);

    // 显示所有类型为 MID 的包裹
    printf("显示所有类型为 MID 的包裹:\n");
    display_all_kind_pag(&my_list, MID);

    // 查找并删除 waybill_num 为 2 的节点
    int pos = find_and_remove(&my_list, 2);
    pos = find_and_remove(&my_list, 1);
    if (pos != -1)
    {
        printf("已删除位置为 %d 的节点\n", pos);
    }
    else
    {
        printf("未找到目标节点\n");
    }

    // 打印删除的包裹订单号
    printf("被删除的包裹序号是\n");
    display(rm_list);

    // 清除 rm_list
    del_list(rm_list);

    return 0;
}
