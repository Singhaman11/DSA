//Print the data stored in the middle node of a given linked list.
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
        printf("List size should be greater than 0.\n");
    temp = head;
    for(int i = 1; i <= n; i++)
    {
        struct Node *new = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter the data of node%d\n", i);
        scanf("%d", &new -> data);
        new -> next = NULL;
        if(head == NULL)
            head = new;
        else
            temp -> next = new;
        temp = new;
    }
}
void middleNode(int n)
{
    int mid = n / 2;
    temp = head;
    if(n == 1)
        printf("The data stored at only node present in the list is %d.\n", temp -> data);
    else
    {
        for(int i = 1; i < mid; i++)
        {
            temp = temp -> next;
        }
        if((n % 2) != 0)
            printf("The data stored at middle node in the list is %d.\n", temp -> next -> data);
        else
            printf("The data stored at middle nodes in the list are %d & %d.\n", temp -> data, temp -> next -> data);
    }
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
    middleNode(n);
}