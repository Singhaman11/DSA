// Bubble sort
#include<iostream>
using namespace std;
int main()
{
    int a[5];
    cout << "Enter 5 nos." << endl;
    for(int i = 0; i < 5; i++)
        cin >> a[i];
    cout << "Unsorted array \n";
    for(int i = 0; i < 5; i++)
        cout << a[i] << ", ";
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(a[j] > a[j + 1])
            {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    cout << "\nSorted array \n";
    for(int i = 0; i < 5; i++)
        cout << a[i] << ", ";
}