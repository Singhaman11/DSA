//Queue works on the principle of First In First Out (FIFO).
//Circular queue using array.
#include<stdio.h>
#include<stdlib.h>
#define QUEUE_SIZE 5
int front = -1, rear = -1;
int queue[QUEUE_SIZE];
int isFull();
int isEmpty();
void enqueue(int element)
{
    if(isFull() == 1)
    {
        printf("Overflow\n");
    }
    else
    {
        rear = (rear + 1) % QUEUE_SIZE;
        queue[rear] = element;
        if(rear == 0)
        {
            front = rear;
        }
    }
}
void dequeue()
{
    if(isEmpty() == 1)
    {
        printf("Underflow\n");
    }
    else
    {
        front = (front + 1) % QUEUE_SIZE;
    }
}
int Front()
{
    if((front == -1) || (front > rear))
    {
        rear = -1;
        return -1;
    }
    else
    {
        return queue[front];
    }
}
int Rear()
{
    if((rear == -1) || (rear < front))
    {
        front = -1;
        return -1;
    }
    else
    {
        return queue[rear];
    }
}
int isFull()
{
    if((rear + 1) % QUEUE_SIZE == front)
    {
        return 1;
    }
    return 0;
}
int isEmpty()
{
    if(Rear() == -1)
    {
        return 1;
    }
    return 0;
}
void display()
{
    int i = front;
    while(i != rear)
    {
        printf("%d, ", queue[i]);
        i = (i + 1) % QUEUE_SIZE;
    }
    printf("%d\n", queue[rear]);
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
                printf("Enter the element to be inserted into the queue.\n");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                if(isEmpty() != 1)
                    printf("The front element of the queue is %d.\n", Front());
                break;
            case 4:
                if(isEmpty() != 1)
                    printf("The rear element of the queue is %d.\n", Rear());
                break;
            case 5:
                display();
                break;
            default:
                exit(0);
        }
    }
}