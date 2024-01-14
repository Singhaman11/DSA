#include<stdio.h>
void main()
{
    int x = 10;
    int *y = &x;
    int *z = &y;
    printf("x = %d\n", x);
    printf("Address x = %d\n", &x);
    printf("Address x = %p\n", x);
    printf("y = %d\n", y);
    printf("*y = %d\n", *y);
    printf("y = %p\n", y);
    printf("z = %d\n", z);
    printf("**z = %d\n", *z);
}