//Delete last occurence of an item from linked list.
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
void deleteLastOccurence(int n)
{
    int count = 0, position = 0;
    temp = head;
    while(temp != NULL)
    {
        count++;
        if(temp->data == n)
            position = count;
        temp = temp -> next; 
    }
    if(position == 0)
    {
        printf("Element not present in linked list\n");
        exit;
    }
    struct Node *temp1 = NULL;
    temp = head;
    if(position == 1)
    {
        temp1 = head;
        head = head -> next;
        free(temp1);
        exit;
    }
    count = 2;
    while(count < position)
    {
        count++;
        temp = temp -> next;
    }
    temp1 = temp -> next;
    temp -> next = temp -> next -> next;
    free(temp1);
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
    n = 0;
    printf("Enter an element whose last occurence need to be deleted.\n");
    scanf("%d", &n);
    deleteLastOccurence(n);
    printf("List after deleting the last occurence of node: ");
    display();
}