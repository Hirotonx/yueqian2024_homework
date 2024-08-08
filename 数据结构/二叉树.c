#include <stdio.h>
#include <stdlib.h>

// 二叉树 链表实现
int tree_size = 0;
typedef int tree_data; // 树的数据类型

#define FORMAT_SPECIFIER(x) _Generic((x), \
    int: "%d",                            \
    float: "%f",                          \
    double: "%lf",                        \
    char: "%c",                           \
    char *: "%s",                         \
    default: "%p")
    
typedef struct TreeNode
{
    tree_data val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

TreeNode *head = NULL;

//创建节点
TreeNode *create_TreeNode(tree_data val)
{
    // 分配内存
    TreeNode *node = malloc(sizeof(TreeNode));

    // 初始化节点
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    // 如果是第一个节点，设为头节点
    if (head == NULL){head = node;}
    // 更新树的节点数
    tree_size++;

    return node;
}

//广度优先搜索添加节点
void tree_append(TreeNode *node)
{
    if (head == NULL)
    {
        head = node;
        return;
    }

    TreeNode *queue[1024]; // 简单的队列实现，假设最多有1024个节点
    int left = 0, right = 0;

    queue[right++] = head;
    
    while(left<right)
    {
        TreeNode *current = queue[left++];
        if(current->left == NULL)
        {
            current->left = node;
            return;
        }
        else if(current->right == NULL)
        {
            current->right = node;
            return;
        }
        //满的就添加到队列里面
        else
        {
            queue[left++] = current->left;
            queue[left++] = current->right;
        }
    }
}

//深度优先搜索 前序
void tree_dfs(TreeNode *node)
{
    TreeNode *entry = node;
    if(entry->left == NULL){return;}
    printf("-> ");
    printf(FORMAT_SPECIFIER(entry->val), entry->val);
    tree_dfs(entry->left);
    tree_dfs(entry->right);
}
