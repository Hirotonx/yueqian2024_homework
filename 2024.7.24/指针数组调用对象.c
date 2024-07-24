#include <stdio.h>

float add(float a, float b)
{
    return a + b;
}

float subtract(float a, float b)
{
    return a - b;
}

float multiply(float a, float b)
{

    return a * b;
}

float divide(float a, float b)
{

    if (b != 0)
    {
        return a / b;
    }
    else
    {
        printf("Error: Division by zero.\n");
        return 0; 
    }
}




int main()
{   
    typedef float (*calc)(float a, float b);
    char sign = '*';
    float num1 = 5.0;
    float num2 = 6.0;
    float (*cal)(float a, float b);
    calc func_list[4] = {add, subtract, multiply, divide};
    if(sign == '+'){cal = func_list[0];}
    else if(sign == '-'){cal = func_list[1];}
    else if(sign == '*'){cal = func_list[2];}
    else if(sign == '/'){cal = func_list[3];}

    printf("%f", cal(num1, num2));
}