//Remove duplicate element from sorted linked list.
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
void removeDuplicateElement()
{
    struct Node *temp = head;
    struct Node *next_next; 
    if (temp == NULL) 
       return; 
    while (temp->next != NULL) 
    {
       if (temp->data == temp->next->data) 
       {
           next_next = temp->next->next;
           free(temp->next);
           temp->next = next_next;  
       }
       else 
       {
          temp = temp->next; 
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
    removeDuplicateElement();
    printf("List after deleting the duplicate elemeents: ");
    display();
}