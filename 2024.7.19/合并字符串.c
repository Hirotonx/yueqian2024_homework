#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char buf1[] = "hello ";
    char buf2[] = "world";
    char *res = (char*)malloc((strlen(buf1) + strlen(buf2) + 1) * sizeof(char));
    for (int i = 0; i < strlen(buf1);i++)
    {
        res[i] = buf1[i];
    }
    int j = 0;
    int buf2_idx = 0;
    for (j = strlen(buf1); j < (strlen(buf1) + strlen(buf2)); j++)
    {
        res[j] = buf2[buf2_idx++];
        //printf("%c\n", buf2[j]);
    }
    res[j] = '\0';
    printf("%s", res);
    free(res);
}