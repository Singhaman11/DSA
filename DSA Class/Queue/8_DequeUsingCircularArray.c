/*Deque using Array.
Input restricted Deque: Insertion from front & deletion from both the ends.
Output restricted Deque: Deletion from front & insertion from both the ends.*/
#include<stdio.h>
#include<stdlib.h>
#define DEQUE_SIZE 5
int front = -1, rear = -1;
int deque[DEQUE_SIZE];
int isFull();
int isEmpty();
void insertion(int element, int option)
{
    if(isFull() == 1)
    {
        printf("Overflow\n");
    }
    else if(rear == -1)                //Insertion at 1st index of the array.
    {
        deque[0] = element;
        rear = 0;
        front = 0;
    }
    else if(option == 1)               //Insertion at front of the deque.
    {
        if(front == 0)
        {
            front = DEQUE_SIZE - 1;
            deque[front] = element;
        }
        else
        {
            front = (front - 1) % DEQUE_SIZE;
            deque[front] = element;
        }
        // for(int i = rear; i >= front; i--)
        // {
        //     deque[i+1] = deque[i];
        // }
        // rear = (rear + 1) % DEQUE_SIZE;
    }
    else
    {
        rear = (rear + 1) % DEQUE_SIZE;
        deque[rear] = element;
    }
}
void deletion(int option)
{
    if(isEmpty() == 1)
    {
        printf("No element is present in the deque.\n");
    }
    else if(option == 1)
    {
        front = (front + 1) % DEQUE_SIZE;
    }
    else
    {
        rear = (rear - 1) % DEQUE_SIZE;
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
        return deque[front];
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
        return deque[rear];
    }
}
int isFull()
{
    if((rear + 1) % DEQUE_SIZE == front)
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
        printf("%d, ", deque[i]);
        i = (i + 1) % DEQUE_SIZE;
    }
    printf("%d\n", deque[rear]);
}
void main()
{
    int c = 0, element = 0, choice = 0, option = 0;
    printf("Enter 1 for Input Restricted Deque.\n");
    printf("Enter 2 for Output Restricted Deque\n");
    scanf("%d", &choice);
    while(c >= 0 && c < 6)
    {
        printf("Enter 1 to insert an element into the deque.\n");
        printf("Enter 2 to delete an element from the deque.\n");
        printf("Enter 3 to print front element of the deque.\n");
        printf("Enter 4 to print rear element of the deque.\n");
        printf("Enter 5 to display the elements present in deque.\n");
        printf("Enter 6 to exit.\n");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                printf("Enter the element to be pushed into the deque.\n");
                scanf("%d", &element);
                if(choice == 1)
                {
                    insertion(element, 1);
                }
                else
                {
                    printf("Enter 1 to push the element at the front of deque.\n");
                    printf("Enter 2 to push the element at the end of deque.\n");
                    scanf("%d", &option);
                    insertion(element, option);
                }
                break;
            case 2:
                if(choice == 2)
                {
                    deletion(1);
                }
                else
                {
                    printf("Enter 1 to pop the element from the front of deque.\n");
                    printf("Enter 2 to pop the element from the end of deque.\n");
                    scanf("%d", &option);
                    deletion(option);
                }
                break;
            case 3:
                if(isEmpty() == 0)
                {
                    printf("The front element in the deque is %d.\n", Front());
                }
                break;
            case 4:
                if(isEmpty() == 0)
                {
                    printf("The rear element in the deque is %d.\n", Rear());
                }
                break;
            case 5:
                display();
                break;
            default:
                exit(0);
        }
    }
}