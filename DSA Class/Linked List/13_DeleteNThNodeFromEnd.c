//Delete the nth node from the end of a given linked list.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
void deleteNthFromEnd(int n)
{
    int c = 0;
    struct Node *temp = head;
    struct Node *DeleteNode = NULL;
    while(temp != NULL)
    {
        temp = temp -> next;
        ++c;
    }
    temp = head;
    if(n == c)
    {
        DeleteNode = temp;
        temp = temp -> next;
        free(DeleteNode);
        head = temp;
        return;
    }
    if(temp->next == NULL && n == 1)
    {
        free(temp);
        return;
    }
    for(int i = 1; i < (c-n); i++)
    {
        temp = temp -> next;
    }
    DeleteNode = temp -> next;
    if(n == 1)
        temp -> next = NULL;
    else
        temp -> next = DeleteNode -> next;
    free(DeleteNode);
}
void display()
{
    temp = head;
    while(temp != NULL)
    {
        printf("%d, ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
    printf("%p", head);
    temp = head;
    while(temp != NULL)
    {
        temp = temp -> next;
        printf(" -> %p", temp);
    }
    printf("\n");
}
void main()
{
    int n = 0;
    printf("Enter the no. of nodes for the list.\n");
    scanf("%d", &n);
    createList(n);
    printf("Linked list: ");
    display();
    printf("Enter the nth node to be deleted from the end of the linked list.\n");
    scanf("%d", &n);
    deleteNthFromEnd(n);
    printf("List after deleting the nth node from the end: ");
    display();
}