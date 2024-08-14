#include<stdio.h>
void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int A1[high + 1];
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
        {
            A1[k] = arr[i];
            i++;
        }
        else
        {
            A1[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid)
    {
        A1[k] = arr[i];
        i++;
        k++;
    }
    while(j <= high)
    {
        A1[k] = arr[j];
        j++;
        k++;
    }
    for(int i = low; i <= high; i++)
    {
        arr[i] = A1[i];
    }
}
void mergeSort(int arr[], int low, int high)
{
    int mid;
    if(low < high)
    { 
        mid = (high + low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}
void display(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d\n", arr[n-1]);
}
int main()
{
    int n;
    printf("Enter the size of the array.\n");
    scanf("%d", &n);
    int ar[n];
    printf("Enter %d elements.\n", n); 
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    printf("Unsorted array: ");
    display(ar, n);
    mergeSort(ar, 0, n-1);
    printf("Sorted array: ");
    display(ar, n);
}