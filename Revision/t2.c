// Polynomial Multiplication
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int c;
    int e;
    struct Node *next;
};
void createNode(struct Node **head, int c, int e)
{
    struct Node *temp = *head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode -> c = c;
    newNode -> e = e;
    newNode -> next = NULL;
    if(temp == NULL)
    {
        *head = newNode;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}
void Multiplication(struct Node **head1, struct Node **head2, struct Node **head3)
{
    struct Node *temp1 = *head1;
    struct Node *temp2 = *head2;
    struct Node *temp3 = *head3;
    if(temp1 == *head1)
    {
        while(temp2 != NULL)
        {
            createNode(head3, temp1->c * temp2->c, temp1->e + temp2->e);
            temp2 = temp2 -> next;
        }
    }
    temp1 = temp1 -> next;
    temp2 = *head2;
    temp3 = *head3;
    while(temp1 != NULL)
    {
        while(temp2->next != NULL)
        {
            temp3 = temp3 -> next;
            if(temp1->e + temp2->e == temp3->e)
            {
                temp3 -> c = temp3 -> c + (temp1->c * temp2->c);
                temp2 = temp2 -> next;
            }
        }
        createNode(head3, temp1->c * temp2->c, temp1->e + temp2->e);
        temp2 = *head2;
        temp3 = *head3;
        temp1 = temp1 -> next;
    }
}
void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            printf("%d \n", temp->c);
        }
        else
        {
            printf("%dx^%d + ", temp->c, temp->e);
        }
        temp = temp->next;
    }
}
void main()
{
    int n = 0;
    int c = 0;
    struct Node *Poly1 = NULL;
    printf("Enter the highest order of polynomial1.\n");
    scanf("%d", &n);
    for (int i = n; i >= 0; i--)
    {
        printf("Enter the coefficient for x^%d\n", i);
        scanf("%d", &c);
        createNode(&Poly1, c, i);
    }
    struct Node *Poly2 = NULL;
    printf("Enter the highest order of polynomial2.\n");
    scanf("%d", &n);
    for (int i = n; i >= 0; i--)
    {
        printf("Enter the coefficient for x^%d\n", i);
        scanf("%d", &c);
        createNode(&Poly2, c, i);
    }
    struct Node *Sum = NULL;
    printf("X");
    Multiplication(&Poly1, &Poly2, &Sum);
    printf("Y");
    printf("Poly1\n");
    display(Poly1);
    printf("Poly2\n");
    display(Poly2);
    printf("Sum of Poly1 & Poly2\n");
    display(Sum);
}