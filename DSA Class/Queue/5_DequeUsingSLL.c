/*Deque using Single linked list. 
Input restricted Deque: Insertion from front & deletion from both the ends.
Output restricted Deque: Deletion from front & insertion from both the ends.*/
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;
int isEmpty();
void insertion(int element, int option)
{
    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    new -> data = element;
    new -> next = NULL;
    if(rear == NULL)
    {
        rear = new;
        front = new;
    }
    else if(option == 1)                    //Insertion of node at the front.
    {
        new -> next = front;
        front = new;
    }
    else                                    //Insertion of node at the end.
    {
        rear -> next = new;
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
    else if(option == 1)                    //Deletion of node from the front.
    {
        deleteNode = front;
        front = front -> next;
        free(deleteNode);
    }
    else                                    //Deletion of node from the end.
    {
        struct Node *temp = front;
        deleteNode = rear;
        while(temp->next != rear)
        {
            temp = temp -> next;
        }
        temp -> next = NULL;
        rear = temp;
        free(deleteNode);
    }
}
int peek()
{
    if(isEmpty() == 1)
    {
        printf("No element is present in the deque.\n");
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
        printf("No element is present in the deque.");
    }
    while(temp != NULL)
    {
        printf("%d, ", temp -> data);
        temp = temp -> next;
    }
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