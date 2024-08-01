#include <stdio.h>
#include <string.h>

#define SIZE 1024

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("请传入正确的参数:(原始文件)  (复制文件)\n");
        return -1;
    }

    FILE *file_origin = fopen(argv[1], "r");
    if (file_origin == NULL)
    {
        printf("无法打开原始文件!\n");
        return -1;
    }

    FILE *file_copy = fopen(argv[2], "w+");
    if (file_copy == NULL)
    {
        printf("无法创建复制文件!\n");
        fclose(file_origin);
        return -1;
    }

    char buffer[SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, SIZE, file_origin)) > 0)
    {
        fwrite(buffer, 1, bytesRead, file_copy);
    }

    fclose(file_copy);
    fclose(file_origin);

    printf("文件复制完成。\n");
    return 0;
}
