#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;
}*head = NULL;
void createList(int n)
{
    if(n <= 0)
    {
        printf("Size of list should be greater than 0.\n");
        return;
    }
    struct Node *temp = head;
    for(int i = 1; i <= n; i++)
    {
        struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter the data for node%d.\n", i);
        scanf("%d", &newNode->data);
        newNode -> next = NULL;
        newNode -> previous = NULL;
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp -> next = newNode;
            newNode -> previous = temp;
        }
        temp = newNode;
    }
}
void display()
{
    struct Node *temp = head;
    while(temp->next != NULL)
    {
        printf("%d, ", temp -> data);
        temp = temp -> next;
    }
    printf("%d\n", temp -> data);
    while(temp != NULL)
    {
        printf("%d, ", temp -> data);
        temp = temp -> previous;
    }
}
void main()
{
    int n = 0;
    printf("Enter the no. of nodes for the list.\n");
    scanf("%d", &n);
    createList(n);
    printf("Data of Double linked list: ");
    display();
}