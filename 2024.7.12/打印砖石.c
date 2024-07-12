#include<stdio.h>
int main()
{
    char val = '*';
    int space_number;
    int star_number;
    int input_number;
    scanf("%d",&input_number);
    int mid_line = input_number;
    input_number = input_number >> 1;
    int i = 1;
    int extar = 0;
    if(mid_line % 2 == 1){extar++;}

    for(i;i<=input_number;i++){
        space_number = input_number + extar - i;//+1为了处理奇数行设计的冗余
        while(space_number){printf(" ");space_number--;}
        //if(index%2==0){index+=1;}
        star_number = i;
        star_number = star_number*2 - 1;
        while(star_number){printf("*");star_number--;}
        printf("\n");
    }

    i--;
    if (mid_line % 2 != 0){
        space_number = input_number - (mid_line >> 1);
        star_number = mid_line;
        while(space_number){printf(" ");space_number--;}
        while(star_number){printf("*");star_number--;}
        printf("\n");
    }

        for(i;i>=1;i--){
        space_number = input_number + extar - i;
        while(space_number){printf(" ");space_number--;}
        //if(index%2==0){index+=1;}
        star_number = i;
        star_number = star_number*2 - 1;
        while(star_number){printf("*");star_number--;}
        printf("\n");
    }
}