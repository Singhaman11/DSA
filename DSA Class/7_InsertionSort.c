#include<stdio.h>
int main()
{
    int ar[] = {12, 54, 65, 7, 23, 9};
    int n = sizeof(ar) / sizeof(int);
    int t = 0, key = 0, pos  = 0;
    for(int i = 1; i < n; i++)
    {
        key = ar[i];                //i = 3     key = 7
        int j = (i - 1); 
        while((ar[j] > key) && (j >= 0))
        {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = key;            
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d, ", ar[i]);
    }
}