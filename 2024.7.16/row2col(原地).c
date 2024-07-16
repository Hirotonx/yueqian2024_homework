#include <stdio.h>
#include <string.h>
/*
定义一个int a[5][5]的二维数组，键盘输入数据对它初始化
要求1.把二维数组中的行和列对调，然后输出二维数组所有的值
*/

// int main()
// {
//     int matrix[5][5];
//     int val = 0;
//     int new_matrix[5][5] = {0};
//     for (int i = 0; i < 5;i++){
//         for (int j = 0; j < 5;j++)
//         {
//             matrix[i][j] = ++val;
//         }
//     }
//     for (int col = 0; col < 5; col++)
//     {
//         for (int row = 0; row < 5;row++)
//         {
//             new_matrix[row][col] = matrix[col][row];
//         }
//     }
//     printf("转换前的数组\n");
//     for (int row = 0; row < 5;row++)
//     {
//         for (int col = 0; col < 5;col++)
//         {
//             printf("%d   ", matrix[row][col]);
//         }
//         printf("\n");
//     }

//     printf("转换后的数组\n");
//     for (int row = 0; row < 5; row++)
//     {
//         for (int col = 0; col < 5; col++)
//         {
//             printf("%d   ", new_matrix[row][col]);
//         }
//         printf("\n");
//     }
// }

int main()
{
    int matrix[5][5];
    int val = 0;
    //int new_matrix[5][5] = {0};
    int tmp = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = ++val;
        }
    }

    printf("转换前的数组\n");
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            printf("%d   ", matrix[row][col]);
        }
        printf("\n");
    }

    for (int row = 0; row < 5; row++)
    {
        for (int col = row + 1; col < 5; col++)
        {
            tmp = matrix[row][col];
            matrix[row][col] = matrix[col][row] ;
            matrix[col][row] = tmp;
        }
    }


    printf("转换后的数组\n");
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            printf("%d   ", matrix[row][col]);
        }
        printf("\n");
    }
}