#include<stdio.h>
int main()
{	
	int year,month,day,res = 0;
	scanf("%d%d%d",&year,&month,&day);
	int leap;
	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){leap = 1;}
	else{leap = 0;}
	int month_arr[] = {31,(leap ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for(int i = 0;i<month - 1;i++){
		res += month_arr[i];
	}
	printf("%d",res+day);
}

