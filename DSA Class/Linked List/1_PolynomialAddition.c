// WAP for polynomial addition.
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int c;               //c -> coefficeint
    int e;               //e -> exponent
    struct Node *next;
};
void createList(struct Node **head, int n)
{
    struct Node *newNode;
    struct Node *temp = *head;
    if(n <= 0)
    {
        printf("List size must be greater than zero.\n");
        return;
    }
    for(int i = n; i >= 0; i--)
    {
        newNode = (struct Node*) malloc(sizeof(struct Node));
        printf("Enter the coefficient for x^%d \n", i);
        scanf("%d", &newNode -> c);
        newNode -> e = i;
        newNode -> next = NULL;
        if(temp == NULL)
            *head = newNode;
        else
            temp -> next = newNode;
        temp = newNode;
    }
}
void Addition(struct Node **head1, struct Node **head2, struct Node **head3)
{
    struct Node *temp1 = *head1, *temp2 = *head2, *temp3 = *head3;
    struct Node *newNode;
    while(temp1 != NULL && temp2 != NULL)
    {
        newNode = (struct Node*) malloc(sizeof(struct Node));
        if(temp1->e == temp2->e)
        {
            newNode -> c = temp1 -> c + temp2 -> c;
            newNode -> e = temp1 -> e;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        else if(temp1->e > temp2->e)
        {
            newNode -> c = temp1 -> c;
            newNode -> e = temp1 -> e;
            temp1 = temp1 -> next;
        }
        else
        {
            newNode -> c = temp2 -> c;
            newNode -> e = temp2 -> e;
            temp2 = temp2 -> next;
        }
        newNode -> next = NULL;
        if(*head3 == NULL)
            *head3 = newNode;
        else
            temp3 -> next = newNode;
        temp3 = newNode;
    }
    while(temp1 != NULL)
    {
        newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode -> c = temp1 -> c;
        newNode -> e = temp1 -> e;
        newNode -> next = NULL;
        if(*head3 == NULL)
            *head3 = newNode;
        else
            temp3 -> next = newNode;
        temp3 = newNode;
        temp1 = temp1 -> next;
    }
    while(temp2 != NULL)
    {
        newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode -> c = temp2 -> c;
        newNode -> e = temp2 -> e;
        newNode -> next = NULL;
        if(*head3 == NULL)
            *head3 = newNode;
        else
            temp3 -> next = newNode;
        temp3 = newNode;
        temp2 = temp2 -> next;
    }
}
void display(struct Node *head)
{       
    struct Node *temp = head;
    while(temp != NULL)
    {
        if(temp->next == NULL)
            printf("%d \n", temp -> c);
        else
            printf("%dx^%d + ", temp -> c, temp -> e);
        temp = temp -> next;
    }
}
int main()
{
    int n = 0;
    struct Node *Poly1 = NULL;
    printf("Enter highest order of polynomial1 \n");
    scanf("%d", &n);
    createList(&Poly1, n);
    struct Node *Poly2 = NULL;
    printf("Enter highest order of polynomial2 \n");
    scanf("%d", &n);
    createList(&Poly2, n);
    struct Node *Sum = NULL;
    Addition(&Poly1, &Poly2, &Sum);
    printf("Poly1: ");
    display(Poly1);
    printf("Poly2: ");
    display(Poly2);
    printf("Sum of Poly1 & Poly2: ");
    display(Sum);
}