#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 传入的必须是顺序表
int *nums_union(int *nums1, int len1, int *nums2, int len2, int *res_len)
{
    int *res = (int *)malloc(sizeof(int) * (len1 + len2));
    int res_idx = 0;
    int idx1 = 0; // nums1索引
    int idx2 = 0; // nums2索引
    while(idx1 < len1 && idx2 < len2)
    {
        if (nums1[idx1] < nums2[idx2])
        {
            res[res_idx++] = nums1[idx1++];
        }
        else
        {
            res[res_idx++] = nums2[idx2++];
        }
        
    }
    while (idx1 < len1)
    {
        res[res_idx++] = nums1[idx1++];
    }
    while (idx2 < len2)
    {
        res[res_idx++] = nums2[idx2++];
    }
    //初始化返回值长度
    *res_len = 1;
    for (int i = 1; i < res_idx;i++)
    {
        if(res[*res_len-1] != res[i])
        {
            res[*res_len] = res[i];
            (*res_len)++;
        }        
    }
    printf("%d", *res_len);
    return res;
}

int main(int argc, char **argv)
{
    int nums1[] = {1, 3,5,5, 5, 7};
    int len1 = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {2, 3, 6, 8};
    int len2 = sizeof(nums2) / sizeof(nums2[0]);
    int res_len ;
    int *result = nums_union(nums1, len1, nums2, len2,&res_len);
    printf("%d",res_len);
    // 输出结果
    printf("结果: ");
    
    for (int i = 0; i < res_len; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");


    free(result);
}
