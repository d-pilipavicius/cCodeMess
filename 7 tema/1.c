#include <stdio.h>
int isInRange(int number, int low, int high);


int main()
{
    printf("%d",isInRange(,,));
    return 0;
}

int isInRange(int number, int low, int high)
{
    return (low > high) ? 0 : ((number>=low && number<=high) ? 1 : 0);
}
