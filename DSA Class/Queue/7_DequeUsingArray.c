/*Deque using Array.
Input restricted Deque: Insertion from front & deletion from both the ends.
Output restricted Deque: Deletion from front & insertion from both the ends.*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;
}*front = NULL, *rear = NULL;
int isEmpty();
void insertion(int element, int option)
{
    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    new -> data = element;
    new -> next = NULL;
    new -> previous = NULL; 
    if(rear == NULL)
    {
        rear = new;
        front = new;
    }
    else if(option == 1)                //Insertion at front of the deque.
    {
        new -> next = front;
        front -> previous = new;
        front = new;
    }
    else                                //Insertion at end of the deque.
    {
        rear -> next = new;
        new -> previous = rear;
        rear = new;
    }
}
void deletion(int option)
{
    struct Node *deleteNode = NULL;
    if(isEmpty() == 1)
    {
        printf("No element is present in the deque.\n");
    }
    else if(front->next == NULL)
    {
        front = NULL;
    }
    else if(option == 1)                //Deletion of node from the front.
    {
        deleteNode = front;
        front = front -> next;
        front -> previous = NULL;
        free(deleteNode);
    }
    else                                //Deletion of node from the end.
    {
        deleteNode = rear;
        rear = rear -> previous;
        rear -> next = NULL;
        free(deleteNode);
    }
}
int peek()
{
    if(isEmpty() == 1)
        printf("No element is present in the deque.\n");
    else
        return front->data;
}
int Front()
{
    if((front == -1) || (front > rear))
    {
        front = -1;
        rear = -1;
        return 0;
    }
    else
        return queue[front];
}
int Rear()
{
    if((rear == -1) || (rear < front))
    {
        front = -1;
        rear = -1;
        return 0;
    }
    else
        return queue[rear];
}
int isFull()
{
    if(rear == (QUEUE_SIZE - 1))
        return 1;
    return 0;
}
int isEmpty()
{
    if(Rear() == -1)
        return 1;
    return 0;
}
void display()
{
    for(int i = front; i <= rear; i++)
    {
        printf("%d, ", queue[i]);
    }
    if(front > rear)
        printf("No element present in the queue.");
    printf("\n");
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