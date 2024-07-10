#include<stdio.h>
#include<string.h>
int main() {
    unsigned int input_number,count = 0;
    printf("输入一个整数");
    scanf("%d",&input_number);
    if (input_number<0){printf("输入的整数数据溢出");return 0;}

    int tmp = input_number;//保存整数部分
    char number_name[][10] = {"个","十","百","千","万","十万","百万","千万","亿","十亿"};
    int remainder;
    while(tmp != 0){
        remainder = tmp%10;
        printf("%s位为%d\n",number_name[count],remainder);
        tmp /= 10;
        count++;
    }
    printf("一共有%d位\n",count);
    return 0;
    }