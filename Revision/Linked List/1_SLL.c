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
    if(n <= 0)
    {
        printf("List size must be greater than 0.\n");
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        struct Node *new = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter the data of node%d.\n", i);
        scanf("%d", &new->data);
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
void display()
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d, ", temp -> data);
        temp = temp -> next;
    }
}
void main()
{
    int n = 0;
    printf("Enter the no. of nodes for the list.\n");
    scanf("%d", &n);
    createList(n);
    printf("Data of Single linked list: ");
    display();
}