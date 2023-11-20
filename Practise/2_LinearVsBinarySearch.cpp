#include<iostream>
using namespace std;
void linearsearch(int arr[], int size, int element)
{
    int i = 0;
    for(i = 0; i < size; i++)
    {
        if(arr[i] == element)
        {
            cout << "The element " << element << " was found at index no. " << i << endl;
            break;
        }
    }
    if(i == size)
        cout << "The element " << element << " was not found in the array " << endl;
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
            cout << "The element " << element << " was found at index no. " << mid << endl;
            break;
        }
        else if(arr[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if(arr[mid] != element)
        cout << "The element " << element << " was not found in the array" << endl;
}
int main()
{
    int arr[] = {8, 9, 11, 18, 22, 31, 38};
    int size = sizeof(arr) / sizeof(int);
    cout << "LinearSearch" << endl;
    linearsearch(arr, size, 11);
    cout << "BinarySearch" << endl;
    binarysearch(arr, size, 22);
}