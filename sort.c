#include<stdio.h>
void sortTwoSortedArray(int arr[], int start, int mid, int end)
{
    int e1 = mid - start + 1;
    int s2 = end - mid + 1;
    int ar1[e1];
    int ar2[s2];
    for(int i = start; i < e1; i++)
    {
        ar1[i] = arr[i];
    }
    int j = 0;
    for(int i = mid+1; i < s2; i++)
    {
        ar2[j] = arr[i];
        j++;
    }
    int k = 0;
    int l = 0;
    int m = start;
    while(k < e1 && l < s2)
    {
        if(ar1[k] < ar2[l])
        {
            arr[m] = ar1[k];
            k++;
        }
        else if(ar1[k] > ar2[l])
        {
            arr[m] = ar2[l];
            l++;
        }
        m++;
    }
    while(k < e1)
    {
        arr[m] = ar1[k];
        k++;
        m++;
    }
    while(l < s2)
    {
        arr[m] = ar1[l];
        l++;
        m++;
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
        sortTwoSortedArray(A, low, mid, high);
    }
}
int main()
{
    int arr[] = {9, 10, 11, 12, 3, 7, 8, 15};
    int size = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, size-1);
    for(int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
}