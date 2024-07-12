#include<stdio.h>
int main()
{	
	
	int input_number;
	double res;
	printf("输入一个整数");
	scanf("%d",&input_number);
	for(int i =1;i<=input_number;i++){
		res += (1.0/i);
	}
	printf("最后的结果是%lf",res);
}

