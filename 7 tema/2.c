#include <stdio.h>
int getFactorial(int number);
int getFactorialNoRecur(int number);
int main()
{
    printf("%d\n",getFactorial(16));
    //printf("%d\n",getFactorialNoRecur());
    return 0;
}

int getFactorialNoRecur(int number)
{
    long long int factorial = 1;
    while(number!=1)
    {
        factorial *= number--;
    }
    return factorial;
}

int getFactorial(int number)
{
    if(number == 0)
    {
        return 1;
    }
    else if(number!=1)
        return number*getFactorialNoRecur(number-1);
    else
        return number;
}
