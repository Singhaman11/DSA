//Reverse the range of the nodes of single linked list.
//Input: 1, 2, 3, 4, 5, 6, 7     left = 2     right = 5
//Output: 1, 5, 4, 3, 2, 6, 7
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head = NULL, *prev = NULL;
void createList(int n)
{
    if(n == 0)
    {
        printf("List size must be greater than 0.\n");
        return;
    }
    prev = head;
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
            prev -> next = new;
        }
        prev = new;
    }
}
void reverse(int left, int right)
{
    int c = 1;
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *Next = NULL;
    struct Node *temp1 = NULL;
    if(right == 1)
    {
        head = head;
    }
    else if(left == 1)
    {
        while(right >= left)
        {
            Next = current -> next;
            current -> next = prev;
            prev = current;
            current = Next;
            right--;
        }
        head -> next = current;
        head = prev;
    }
    else
    {
        while (c <= left)
        {
            prev = current;
            current = current -> next;
            c++;
        }
        temp1 = prev;
        while(c <= right)
        {
            Next = current -> next;
            current -> next = prev;
            prev = current;
            current = Next;
            c++;
        }
        c = 1;
        Next = head;
        while (c < left-1)
        {
            Next = Next -> next;
            c++;
        }
        Next -> next = prev;
        temp1 -> next = current;
    }
}
void display()
{
    prev = head;
    while(prev != NULL)
    {
        printf("%d, ", prev -> data); 
        prev = prev -> next;
    }
    printf("\n");
}
void main()
{
    int n = 0, left = 0, right = 0;
    printf("Enter the no. of nodes for list\n");
    scanf("%d", &n);
    createList(n);
    printf("Single Linked List: ");
    display();
    printf("Enter the node no. from where the list is to be reversed.\n");
    scanf("%d", &left);
    printf("Enter the node no. till where the list is to be reversed.\n");
    scanf("%d", &right);
    reverse(left, right);
    printf("Reversed Single Linked List: ");
    display();
}