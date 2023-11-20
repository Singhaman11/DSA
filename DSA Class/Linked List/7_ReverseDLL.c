//Reverse a double linked list
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
void createList(struct Node **head, int n)
{
    struct Node *newNode;
    struct Node *temp = NULL;
    if(n <= 0)
    {
        printf("List size must be greater than zero.\n");
        return;
    }
    temp = *head;
    for(int i = 1; i <= n; i++)
    {
        newNode = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter data of node %d: ", i);
        scanf("%d", &newNode -> data);
        newNode -> next = NULL;
        newNode -> prev = NULL;
        if(*head == NULL)
            *head = newNode;
        else
        {
            temp -> next = newNode;
            newNode -> prev = temp;
        }
        temp = newNode;
    }
}
void reverseList(struct Node **head)
{
    struct Node *temp = NULL;
    while((*head)->next != NULL)
    {
        temp = (*head) -> next;
        (*head) -> next = (*head) -> prev;
        (*head) -> prev = temp;
        *head = (*head) -> prev;
    }
    temp = (*head) -> next;
    (*head) -> next = (*head) -> prev;
    (*head) -> prev = temp;
}
void display(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d, ", head -> data);
        head = head -> next;
    }
    printf("\n");
}
void main()
{
    struct Node *head = NULL;
    int n = 0;
    printf("Enter the no. of nodes for list\n");
    scanf("%d", &n);
    createList(&head, n);
    printf("Double Linked List: ");
    display(head);
    reverseList(&head);
    printf("Reversed Double Linked List: ");
    display(head);
}