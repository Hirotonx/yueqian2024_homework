#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cutstr(char* str, int beg, int end)
{
    int len = strlen(str);
    if((beg >len || beg<0) || (end>len || end<0) || (end<=beg)){printf("输入有误");return;}
    char *res = (char *)malloc(len * sizeof(char));
    while(beg<end)
    {
        res[beg] = str[beg];
        beg++;
    }
    res[end] = '\0';
    // int idx = 0;
    // while(idx<strlen(res))
    // {
    //     str[idx] = res[idx];
    //     idx++;
    // }
    // str[idx] = '\0';
    strcpy(str, res);
    free(res);
}
int main()
{
    char str[50] = "hehwhgfgedgfgdfgdgfgsdgdfgdsgf";
    printf("原始: %s\n",str);
    cutstr(str, 0, 6);
    printf("切片: %s\n",str);
}