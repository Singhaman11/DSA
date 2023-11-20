// WAP to sort a given array that contain 0's & 1's only.
#include<stdio.h>
int main()
{
    int t = 0, f = 0;
    int ar[] = {1, 0, 1, 0, 1};
    int n = sizeof(ar) / sizeof(int);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - 1 - i); j++)
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
            break;
        f = 0;
    }
    printf("Sorted array \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", ar[i]);
    }
}