//Reverse all the nodes of single linked list keeping intact the 1st & last node.
//Input: 1, 2, 3, 4, 5
//Output: 1, 4, 3, 2, 5 
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
            head = new;
        else
            temp -> next = new;
        temp = new;
    }
}
void reverse()
{
    struct Node *temp1 = NULL;
    struct Node *temp2 = NULL;
    temp = head -> next;
    temp1 = temp -> next;
    temp2 = temp1 -> next;
    while(temp2 != NULL)
    {
        temp1 -> next = temp;
        temp = temp1;
        temp1 = temp2;
        temp2 = temp2 -> next;
    }
    head -> next -> next = temp1;
    head -> next = temp;
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
}
void main()
{
    int n = 0;
    printf("Enter the no. of nodes for list\n");
    scanf("%d", &n);
    createList(n);
    printf("Single Linked List: ");
    display();
    reverse();
    printf("Reversed Single Linked List: ");
    display();
}