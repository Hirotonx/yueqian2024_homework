#include<stdio.h>
int main()
{	
    printf("输入五个整数"); 
    int *arr = (int *)malloc(5 * sizeof(int));
    scanf("%d%d%d%d%d",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4]);
    int max_ = arr[0];
    int min_ = arr[1];
    for(int i = 0; i<5; i++){
        if(max_<arr[i]){max_ = arr[i];}
        if(min_>arr[i]){min_ = arr[i];}
    }
    printf("最大值是: %d\n最小值是: %d\n",max_,min_);
    free(arr);
    return 0;
    
}
