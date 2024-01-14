// n th node from the end of the linked list
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head = NULL, *temp = NULL;
void createList(int n)
{
    if(n == 0)
    {
        printf("List size should be greater than 0.\n");
    }
    temp = head;
    for(int i = 1; i <= n; i++)
    {
        struct Node *new = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter the data of node%d\n", i);
        scanf("%d", &new -> data);
        new -> next = NULL;
        if(head == NULL)
        {
            head = new;
        }
        else
        {
            temp -> next = new;
        }
        temp = new;
    }
}
void nthNodeFromLast(int x)
{
    temp = head;
    for(int i = 1; i < x; i++)
    {
        temp = temp -> next;
    }
    printf("The data stored at node_%d from last is %d.", x, temp -> data);
}
void display()
{
    temp = head;
    printf("Linked list: ");
    while(temp != NULL)
    {
        printf("%d, ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
void main()
{
    int n = 0;
    printf("Enter the no. of nodes for the list.\n");
    scanf("%d", &n);
    createList(n);
    display();
    printf("Enter the position of node from the last.\n");
    int p = 0;
    scanf("%d", &p);
    if(p > 0 && p <= n)
    {
        nthNodeFromLast(n - p + 1);
    }
    else
    {
        printf("Entered an invalid position.\n");
    }
}