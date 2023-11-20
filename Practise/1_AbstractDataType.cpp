#include<iostream>
using namespace std;
struct MyArray
{
    int total_size;
    int used_size;
    int *ptr;
    MyArray(int tsize, int usize)
    {
        total_size = tsize;
        used_size = usize;
        ptr = new int[tsize];
    }
    ~MyArray()
    {
        delete[] ptr;
    }
};
void Show(struct MyArray *a)
{
    for(int i = 0; i < (a -> used_size); i++)
        cout << a -> ptr[i] << endl;
}
void SetValue(struct MyArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        cout << "Enter element " << i << endl;    
        cin >> n;
        a -> ptr[i] = n;
    }
}
int main()
{
    MyArray marks(10, 2);
    cout << "We are running SetValue now " << endl;
    SetValue(&marks);
    cout << "We are running Show now " << endl;
    Show(&marks);
    return 0;
}