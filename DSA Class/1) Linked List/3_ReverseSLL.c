//Reverse single linked list
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head = NULL;
void createList(int n)
{
    struct Node *temp;
    if(n == 0)
    {
        printf("List size must be greater than 0.\n");
        return;
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
void reverseList()
{
    struct Node *temp1 = NULL, *temp2 = NULL, *temp3 = NULL;
    temp1 = NULL;
    temp2 = head;
    temp3 = NULL;
    while(temp2 != NULL)
    {
        temp3 = temp2 -> next;
        temp2 -> next = temp1;
        temp1 = temp2;
        temp2 = temp3;
    }
    /*
    temp1 = head;
    temp2 = head -> next;
    temp3 = temp2 -> next;
    while(temp2 != NULL)
    {
        if(temp1 == head)
            temp1 -> next = NULL;
        temp2 -> next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        if(temp3 != NULL)
            temp3 = temp3 -> next;
    }
    */
    head = temp1;
}
void display()
{
    struct Node *temp = head;
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
    printf("Enter the no. of nodes for list\n");
    scanf("%d", &n);
    createList(n);
    printf("Single Linked List: ");
    display();
    reverseList();
    printf("Reversed Single Linked List: ");
    display();
}