//Stack works on the principle of Last In First Out (LIFO).
//Stack using linked list
#include<stdio.h>
#include<stdlib.h>
int isEmpty();
struct Node
{
    int data;
    struct Node *next;
}*top = NULL;
void push(int element)
{
    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    new -> data = element;
    new -> next = NULL;
    if(top != NULL)
        new -> next = top;
    top = new;
}
void pop()
{
    struct Node *deleteNode = NULL;
    if(isEmpty() == 1)
        printf("No element is present in the stack.\n");
    else if(top->next == NULL)
        top = NULL;
    else
    {
        deleteNode = top;
        top = top -> next;
        free(deleteNode);
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
        return top->data;
}
int isEmpty()
{
    if(top == NULL)
        return 1;
    else
        return 0;
}
void display()
{
    struct Node *temp = top;
    while(temp != NULL)
    {
        printf("%d, ", temp -> data);
        temp = temp -> next;
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
                    printf("The top element of the stack is %d.\n", peek());
                break;
            case 4:
                if(isEmpty() == 1)
                    printf("Stack is empty.\n");
                else
                    display();
                break;
            default:
                exit(0);
        }
    }
}