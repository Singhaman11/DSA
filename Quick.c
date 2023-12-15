#include<stdio.h>
int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low;
    int j = high;
    int temp = 0;
    do
    {
        while(A[i] <= pivot)
        {
            i++;
        }
        while(A[j] > pivot)
        {
            j--;
        }
        if(i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    while(i < j);
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
void quickSort(int A[], int low, int high)
{
    int partitionIndex;
    if(low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSort(A, low, partitionIndex-1);
        quickSort(A, partitionIndex+1, high);
    }
}
void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", A[i]);
    }
    printf("\n");
}
void main()
{
    int A[] = {3, 70, 2, 12, 19, 54, 98, 69, 11, 4};
    int n = sizeof(A) / sizeof(A[0]);
    printf("Sorted array: ");
    display(A, n);
    quickSort(A, 0, n-1);
    printf("Unsorted array: ");
    display(A, n);
}