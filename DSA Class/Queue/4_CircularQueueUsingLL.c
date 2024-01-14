//Queue works on the principle of First In First Out (FIFO).
//Circular queue using linked list.
#include<stdio.h>
#include<stdlib.h>
int isEmpty();
struct Node
{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;
void enqueue(int element)
{
    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    new -> data = element;
    new -> next = NULL;
    if(rear == NULL)
    {
        rear = new;
        rear -> next = rear;
        front = new;
    }
    else
    {
        new -> next = front;
        rear -> next = new;
        rear = new;
    }
}
void dequeue()
{
    struct Node *deleteNode = NULL;
    if(isEmpty() == 1)
    {
        printf("No element is present in the queue.\n");
    }
    else if(front->next == front)
    {
        front = NULL;
    }
    else
    {
        deleteNode = front;
        front = front -> next;
        rear -> next = front;
        free(deleteNode);
    }
}
int peek()
{
    if(isEmpty() == 1)
    {
        printf("No element is present in the queue.\n");
    }
    else
    {
        return front->data;
    }
}
int Front()
{
    if(isEmpty() == 0)
    {
        return front->data;
    }
    else
    {
        return 0;
    }
}
int Rear()
{
    if(isEmpty() == 0)
    {
        return rear->data;
    }
    else
    {
        return 0;
    }
}
int isEmpty()
{
    if(front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display()
{
    struct Node *temp = front;
    if(isEmpty() == 1)
    {
        printf("No element is present in the queue.");
    }
    do
    {
        printf("%d, ", temp -> data);
        temp = temp -> next;
    }
    while(temp != front);
    printf("\n");
}
void main()
{
    int c = 0, element = 0;
    while(c >= 0 && c < 6)
    {
        printf("Enter 1 to insert an element into the queue.\n");
        printf("Enter 2 to delete an element from the queue.\n");
        printf("Enter 3 to print front element of the queue.\n");
        printf("Enter 4 to print rear element of the queue.\n");
        printf("Enter 5 to display the elements present in queue.\n");
        printf("Enter 6 to exit.\n");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                printf("Enter the element to be pushed into the queue.\n");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                if(isEmpty() == 0)
                    printf("The front element in the queue is %d.\n", Front());
                break;
            case 4:
                if(isEmpty() == 0)
                    printf("The rear element in the queue is %d.\n", Rear());
                break;
            case 5:
                display();
                break;
            default:
                exit(0);
        }
    }
}