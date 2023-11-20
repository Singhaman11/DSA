#include<stdio.h>
#include<stdlib.h>
struct MyArray
{
    int total_size;
    int used_size;
    int *ptr;
};
void CreateArray(struct MyArray *a, int tsize, int usize)
{
    a -> total_size = tsize;
    a -> used_size = usize;
    a -> ptr = (int*) malloc(tsize * sizeof(int));
}
void Show(struct MyArray *a)
{
    for (int i = 0; i < a->used_size; i++)
        printf("%d\n", (a -> ptr)[i]);    
}
void SetValue(struct MyArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d \n", i);    
        scanf("%d", &n);
        (a -> ptr)[i] = n;
    }
}
int main()
{
    struct MyArray marks;
    CreateArray(&marks, 10, 2);
    printf("We are running SetValue now \n");
    SetValue(&marks);
    printf("We are running Show now \n");
    Show(&marks);
    return 0;
}