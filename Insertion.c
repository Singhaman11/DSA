#include<stdio.h>
void main()
{
    int A[] = {3, 70, 2, 12, 19, 54, 98, 69, 11, 4};
    int n = sizeof(A) / sizeof(A[0]);
    int key;
    for(int i = 1; i < n; i++)
    {
        int j = i - 1;
        key = A[i];
        while(A[j] > key && j >= 0)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d, ", A[i]);
    }
}