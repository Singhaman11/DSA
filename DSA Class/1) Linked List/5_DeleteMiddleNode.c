//Delete the middle node of a given linked list
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
void deleteNode(int n)
{
    int mid = ceil(n / 2.0);
    temp = head;
    struct Node *temp1 = NULL;
    if(n == 1)
    {
        temp1 = head;
        free(temp1);
        head = NULL;
        //If the list contains only one node and that node is freed, the head pointer will still point to the memory location that was freed. This is known as a dangling pointer.
    }
    else
    {
        for(int i = 2; i < mid; i++)
        {
            temp = temp -> next;
        }
        temp1 = temp -> next;
        temp -> next = temp1 -> next;
        free(temp1);
        if((n % 2) == 0)
        {
            temp1 = temp -> next;
            temp -> next = temp1 -> next;
            free(temp1);
        }
    }
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
    deleteNode(n);
    printf("List after deleting the middle node: \n");
    display();
}