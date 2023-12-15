// WAP to find the largest and 2nd largest element from a given unsorted array.
#include<stdio.h>
int main()
{
    int ar[] = {5, 8, 6, 9, 7, 10};
    int max = 0, pos = 0;
    int n = sizeof(ar) / sizeof(int);
    for(int i = 0; i < 2; i++)
    {
        pos = i;
        for(int j = (i + 1); j < n; j++)
        {
            if(ar[pos] < ar[j])
            {
                pos = j;
            }
        }
        max = ar[i];
        ar[i] = ar[pos];
        ar[pos] = max;
    }
    printf("Largest no. = %d\n", ar[0]);
    printf("2nd largest no. = %d\n", ar[1]);
}