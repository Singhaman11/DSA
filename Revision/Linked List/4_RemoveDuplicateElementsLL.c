//Remove duplicate element from unsorted linked list.
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
void removeDuplicateElement()
{
    temp = head;
    struct Node *temp1 = NULL;
    struct Node *temp2 = NULL;
    while(temp->next != NULL)
    {
        temp2 = temp;
        while(temp2->next != NULL)
        {
            if(temp -> data == temp2 -> next -> data)
            {
                temp1 = temp2 -> next;
                temp2 -> next = temp1 -> next;
                free(temp1);
                if(temp2->next == NULL)
                {
                    break;
                }
            }
            else
            {
                temp2 = temp2 -> next;
            }
        }
        if(temp->next == NULL)
        {
            break;
        }
        temp = temp -> next;
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