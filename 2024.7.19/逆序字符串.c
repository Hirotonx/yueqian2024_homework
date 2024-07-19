#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char* in_str = (char*)malloc(30 * sizeof(char));
    char *res_str = (char *)malloc(30 * sizeof(char));
    scanf("%s", in_str);

    res_str[strlen(in_str)] = '\0';
    int res_idx = 0;
    for (int i = strlen(in_str ) - 1; i >= 0;i--)
    {
        res_str[res_idx++] = in_str[i];
        //printf("%d", i);
    }
    printf("%s", res_str);
    free(in_str);
    free(res_str);
}
