#include<stdio.h>
int main()
{
    int arr[10];
    printf("输入10个整数(需要包含100)\n");
    for (int i = 0; i < 10;i++){
        printf("输入10个整数当前为第 %d 个\n",i+1);
        scanf("%d", &arr[i]);
    }
    int i = 0;
    for (i; i < 10;i++){
        if(arr[i] == 100){goto connet;}
    }
    connet:
        while (i < 9)
        {
            arr[i] = arr[i+1];
            i++;
    }
    
    printf("删除第一个100的数组是\n");
    for (int k = 0; k < 9;k++){
        printf("%d\n", arr[k]);
    }
}
