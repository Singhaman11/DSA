#include<stdio.h>
void linearsearch(int arr[], int size, int element)
{
    int i = 0;
    for(i = 0; i < size; i++)
    {
        if(arr[i] == element)
        {
            printf("The element %d was found at index no. %d \n", element, i);
            break;
        }
    }
    if(i == size)
        printf("The element %d is not found in the array\n", element);
}
void binarysearch(int arr[], int size, int element)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid] == element)
        {
            printf("The element %d was found at index no. %d \n", element, mid);
            break;
        }
        else if(arr[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if(arr[mid] != element)
        printf("The element %d was not found in the array", element);
}
int main()
{
    int arr[] = {8, 9, 11, 18, 22, 31, 38};
    int size = sizeof(arr) / sizeof(int);
    printf("LinearSearch\n");
    linearsearch(arr, size, 11);
    printf("BinarySearch\n");
    binarysearch(arr, size, 22);
}