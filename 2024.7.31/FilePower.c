#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("请提供文件名作为参数\n");
        return 0;
    }

    int fd = open(argv[1], O_RDWR | O_CREAT, 777);
    if (fd == -1)
    {
        printf("你滴权限大大滴没有");
        return 0;}
   close(fd);

   struct stat file_power;
   if (stat(argv[1], &file_power) == -1)
   {
       printf("无法获取文件状态\n");
       return 0;
   }
   printf("你的权限是   ");
   printf((file_power.st_mode & S_IRUSR) ? "r" : "-");
   printf((file_power.st_mode & S_IWUSR) ? "w" : "-");
   printf((file_power.st_mode & S_IXUSR) ? "x" : "-");
   printf((file_power.st_mode & S_IRGRP) ? "r" : "-");
   printf((file_power.st_mode & S_IWGRP) ? "w" : "-");
   printf((file_power.st_mode & S_IXGRP) ? "x" : "-");
   printf((file_power.st_mode & S_IROTH) ? "r" : "-");
   printf((file_power.st_mode & S_IWOTH) ? "w" : "-");
   printf((file_power.st_mode & S_IXOTH) ? "x" : "-");
   printf("\n");
   int res = chmod(argv[1], 0777);
   if(res == -1){printf("你没有权限修改文件权限\n");return 0;}

   if (stat(argv[1], &file_power) == -1)
   {
       printf("无法获取文件状态\n");
       return 0;
   }
   printf("你修改后的权限是   ");
   printf((file_power.st_mode & S_IRUSR) ? "r" : "-");
   printf((file_power.st_mode & S_IWUSR) ? "w" : "-");
   printf((file_power.st_mode & S_IXUSR) ? "x" : "-");
   printf((file_power.st_mode & S_IRGRP) ? "r" : "-");
   printf((file_power.st_mode & S_IWGRP) ? "w" : "-");
   printf((file_power.st_mode & S_IXGRP) ? "x" : "-");
   printf((file_power.st_mode & S_IROTH) ? "r" : "-");
   printf((file_power.st_mode & S_IWOTH) ? "w" : "-");
   printf((file_power.st_mode & S_IXOTH) ? "x" : "-");
   printf("\n");
}