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
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *head = NULL;

// 创建节点
TreeNode *create_TreeNode(tree_data val)
{
    // 分配内存
    TreeNode *node = malloc(sizeof(TreeNode));

    // 初始化节点
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    // 如果是第一个节点，设为头节点
    if (head == NULL)
    {
        head = node;
    }
    // 更新树的节点数
    tree_size++;

    return node;
}

// 广度优先搜索添加节点
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

    while (left < right)
    {
        TreeNode *current = queue[left++];
        if (current->left == NULL)
        {
            current->left = node;
            return;
        }
        else if (current->right == NULL)
        {
            current->right = node;
            return;
        }
        // 如果左、右子节点都存在，则将其添加到队列中
        queue[right++] = current->left;
        queue[right++] = current->right;
    }
}

// 深度优先搜索 前序
void tree_dfs(TreeNode *node)
{
    TreeNode *entry = node;
    if (entry == NULL)
    {
        return;
    }
    printf("-> ");
    printf(FORMAT_SPECIFIER(entry->val), entry->val);
    tree_dfs(entry->left);
    tree_dfs(entry->right);
}

// 广度优先搜索 层序
void tree_bfs(TreeNode *node)
{
    if (head == NULL)
    {
        return;
    }
    int left = 0;
    int right = 0;

    TreeNode *queue[1024];
    queue[right++] = node;
    while (left < right)
    {
        TreeNode *current = queue[left++];
        if (current->left != NULL)
        {
            queue[right++] = current->left;
        }
        if (current->right != NULL)
        {
            queue[right++] = current->right;
        }
        printf(" -> ");
        printf(FORMAT_SPECIFIER(current->val), current->val);
    }
    printf("\n");
}

void display(TreeNode *root, int space, int level)
{
    if (root == NULL)
        return;

    // 增加当前的间隔距离
    space += level;

    // 处理右子树
    display(root->right, space, level);

    // 打印当前节点
    printf("\n");
    for (int i = 0; i < space; i++)
        printf(" ");
    printf(FORMAT_SPECIFIER(root->val), root->val);

    // 处理左子树
    display(root->left, space, level);
}

int main()
{
    // 创建并插入一些节点
    TreeNode *root = create_TreeNode(1);
    tree_append(create_TreeNode(2));
    tree_append(create_TreeNode(3));
    tree_append(create_TreeNode(4));
    tree_append(create_TreeNode(5));
    tree_append(create_TreeNode(6));
    tree_append(create_TreeNode(7));

    // 打印树的结构
    display(root, 0, 10);
    printf("\n");
    tree_dfs(root);
    printf("\n");
    tree_bfs(root);

    return 0;
}