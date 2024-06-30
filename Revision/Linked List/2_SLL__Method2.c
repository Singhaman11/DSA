#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void createList(struct Node **head, int data1)
{
    struct Node *temp = *head;
    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    new -> data = data1;
    new -> next = NULL;
    if(*head == NULL)
    {
        *head = new;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = new;
    }
}
void display(struct Node **head)
{
    struct Node *temp = *head;
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
void main()
{
    struct Node *head = NULL;
    int n = 0;
    printf("Enter the size of the list.\n");
    scanf("%d", &n);
    if(n == 0)
    {
        printf("List size must be greater than 0.\n");
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        int data = 0;
        printf("Enter the data of node%d.\n", i);
        scanf("%d", &data);
        createList(&head, data);
    }
    display(&head);
}