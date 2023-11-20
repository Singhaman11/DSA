// WAP to sort an array using Selection sort method.
#include<stdio.h>
int main()
{
    int ar[] = {5, 6, 9, 7, 8};
    int max = 0, pos = 0, f = 0;
    int x = 0;
    int n = sizeof(ar) / sizeof(int);
    printf("Unsorted array\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d, ", ar[i]);
    }
    for(int i = 0; i < n; i++)
    {
        pos = i;
        for(int j = (i + 1); j < n; j++)
        {
            if(ar[pos] > ar[j])
            {
                pos = j;
                // f = 1;
                // x++;
            }
        }
        max = ar[i];
        ar[i] = ar[pos];
        ar[pos] = max;
        // if(f == 0)
            // break;
        // f = 0;
    }
    // printf("x = %d \n", x);
    printf("\nSorted array\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d, ", ar[i]);
    }
}