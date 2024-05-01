//Stack works on the principle of Last In First Out (LIFO).
//Stack using array.
#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5
int top = -1;
int stack[STACK_SIZE];
int isFull();
int isEmpty();
void push(int element)
{
    if(isFull() == 1)
    {
        printf("Overflow\n");
    }
    else
    {
        top++;
        stack[top] = element;
    }
}
void pop()
{
    if(isEmpty() == 1)
    {
        printf("No element is present in the stack.\n");
    }
    else
    {
        top--;
    }
}
int peek()
{
    if(isEmpty() == 1)
    {
        printf("No element is present in the stack.\n");
        return -1;
    }
    else
    {
        return stack[top];
    }
}
int isFull()
{
    if(top == STACK_SIZE-1)
    {
        return 1;
    }
    else
    {
        return  0; 
    }
}
int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return  0; 
    }
}
void display()
{
   for(int i = 0; i <= top; i++)
   {
        printf("%d, ", stack[i]);
   }
   printf("\n");
}
void main()
{
    int c = 0, element = 0;
    while(c >= 0 && c < 5)
    {
        printf("Enter 1 to push an element into the stack.\n");
        printf("Enter 2 to pop an element from the stack.\n");
        printf("Enter 3 to print top element from the stack.\n");
        printf("Enter 4 to display the elements present in stack.\n");
        printf("Enter 5 to exit.\n");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                printf("Enter the element to be pushed into the stack.\n");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                if(peek() != -1)
                {
                    printf("The top element of the stack is %d.\n", peek());
                }
                break;
            case 4:
                if(isEmpty() == 1)
                {
                    printf("Stack is empty.\n");
                }
                else
                {
                    display();
                }
                break;
            default:
                exit(0);
        }
    }
}