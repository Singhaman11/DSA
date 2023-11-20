#include<stdio.h>
#include<math.h>
int divide(int dividend, int divisor)
{
    int c = 0;
    if((dividend < 0 && divisor > 0) || (divisor < 0 && dividend > 0))
    {
        while(abs(dividend) >= abs(divisor))
        {
            dividend = dividend + divisor;
            c--;
        }
    }
    else
    {
        while(abs(dividend) >= abs(divisor))
        {
            dividend = dividend - divisor;
            c++;
        }
    }
    return c;
}
void main()
{
    int dividend = 0;
    int divisor = 0;
    printf("Enter dividend\n");
    scanf("%d", &dividend);
    printf("Enter divisor\n");
    scanf("%d", &divisor);
    printf("Count = %d", divide(dividend, divisor));
}