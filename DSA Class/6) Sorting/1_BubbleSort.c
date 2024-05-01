// WAP to sort an array using Bubble sort technique.
#include<stdio.h>
int main()
{
    int ar[] = {5, 6, 9, 7, 8};
    int t = 0, f = 0;
    int n = sizeof(ar) / sizeof(int);
    for(int i = 0; i < n; i++)
    {
        f = 0;
        for(int j = 0; j < (n - 1 - i); j++)
        {
            if(ar[j] > ar[j + 1])
            {
                t = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = t;
                f = 1;
            }
        }
        if(f == 0)
        {
            break;
        }
    }
    printf("Sorted array\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d, ", ar[i]);
    }
}