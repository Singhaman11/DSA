//Happy no.
#include<stdio.h>
#include<stdbool.h>
void isHappy(int n)
{
    int sum = 0;
    do
    {
        sum = 0;
        while(n > 0)
        {
            sum = sum + ((n%10)*(n%10));
            n = n / 10;
        }
        n = sum;
    }
    while(sum == 7 || sum >= 10);
    if(sum == 1)
        printf("true");
    else
        printf("false");
}
void main()
{
    int n = 0;
    printf("Enter the no.\n");
    scanf("%d", &n);
    isHappy(n);
}