//Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
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
struct Node* oddEvenList(struct Node* head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
    {
        return head;
    }
    struct Node *temp = head;
    struct Node *head1 = head -> next;
    struct Node *temp1 = head1;
    while(temp->next->next != NULL && temp1->next->next != NULL)
    {
        temp -> next = temp1 -> next;
        temp = temp -> next;
        temp1 -> next = temp -> next;
        temp1 = temp1 -> next;
        if(temp1->next == NULL)
        {
            temp -> next = head1;
            return head;
        }
    }
    if(temp1->next->next == NULL)
    {
        temp -> next = temp1 -> next;
        temp = temp -> next;
        temp1 -> next = NULL;
        temp -> next = head1;
        return head;
    }
    return head;
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
    oddEvenList(head);
    display();
}