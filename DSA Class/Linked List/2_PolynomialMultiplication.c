//WAP to perform polynomial multiplication.
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
void Multiplication(struct Node **head1, struct Node **head2, struct Node **head3)
{
    struct Node *temp1 = *head1;
    struct Node *temp2 = *head2;
    struct Node *temp3 = *head3;
    struct Node *new = NULL;
    if(temp1 == *head1)
    {
        while(temp2 != NULL)
        {
            struct Node *new = (struct Node*) malloc(sizeof(struct Node));
            new -> c = temp1->c * temp2->c;
            new -> e = temp1->e + temp2->e;
            new -> next = NULL;
            if(temp3 == NULL)
                *head3 = new;
            else
                temp3 -> next = new;
            temp3 = new;
            temp2 = temp2 -> next;
        }
    }
    temp1 = (*head1) -> next;
    temp2 = *head2;
    temp3 = *head3;
    while(temp1 != NULL)
    {
        while(temp2->next != NULL)
        {
            temp3 = temp3 -> next;
            if(temp3->e == (temp1->e + temp2->e))
            {
                temp3 -> c = temp3->c + (temp1->c * temp2->c);
                temp2 = temp2 -> next;
            }

        }
        struct Node *new = (struct Node*) malloc(sizeof(struct Node));
        new -> c = temp1->c * temp2->c;
        new -> e = temp1->e + temp2->e;
        new -> next = NULL;
        temp3 -> next = new;
        temp3 = new;
        temp2 = *head2;
        temp3 = *head3;
        temp1 = temp1 -> next;
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
    int n = 0, n1 = 0;
    struct Node *Poly1 = NULL;
    printf("Enter highest order of polynomial1 \n");
    scanf("%d", &n);
    createList(&Poly1, n);
    struct Node *Poly2 = NULL;
    printf("Enter highest order of polynomial2 \n");
    scanf("%d", &n1);
    createList(&Poly2, n1);
    printf("Poly1: ");
    display(Poly1);
    printf("Poly2: ");
    display(Poly2);
    struct Node *Product = NULL;
    (n >= n1) ? Multiplication(&Poly1, &Poly2, &Product) : Multiplication(&Poly2, &Poly1, &Product);
    printf("Product of Poly1 & Poly2: ");
    display(Product);
}