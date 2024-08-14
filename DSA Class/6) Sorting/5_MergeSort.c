#include<stdio.h>
void merge(int A[], int mid, int low, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high+1];
    while(i <= mid && j <= high)
    {
        if(A[i] < A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    while(i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while(j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for(int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}
void mergeSort(int A[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
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
int main()
{
    int A[] = {3, 70, 20, 11, 9, 54, 98, 69, 12, 14};
    int n = sizeof(A) / sizeof(A[0]);
    printf("Unsorted array: ");
    display(A, n);
    mergeSort(A, 0, n-1);
    printf("Sorted array: ");
    display(A, n);
}