#include<stdio.h>
int getPivotIndex(int arr[], int start, int end)
{
    int pe = arr[end];    // pe = 15
    int pi = start - 1;    // pi = -1
    int t = 0;
    for(int i = start; i < end; i++)
    {
        if(arr[i] < pe)
        {
            ++pi;    // pi = 0
            t = arr[pi];
            arr[pi] = arr[i];
            arr[i] = t;
        }
    }
    t = arr[end];
    arr[end] = arr[pi+1];
    arr[pi+1] = t;
    return (pi+1);
}
void quickSort(int arr[], int start, int end)
{
    if(end > start)
    {
        int pi = getPivotIndex(arr, start, end);
        quickSort(arr, start, pi-1);
        quickSort(arr, pi+1, end);
    }
}
// Ascending order
int main()
{
    int arr[] = {19, 12, 11, 16, 18, 7, 8, 15};
    //  12   19   11                               i = 1   pi = 0
    //  12   11   19                               i = 2   pi = 1
    //  12   11   19   16                          i = 3   pi = 1
    //  12   11   19   16   18                     i = 4   pi = 1
    //  12   11    7   16   18   19                i = 5   pi = 2
    //  12   11    7    8   18   19   16           i = 6   pi = 3
    //  12   11    7    8   15   19   16   18
    int size = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, size-1);
    for(int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
}