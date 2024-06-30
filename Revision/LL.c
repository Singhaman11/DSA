#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;
} *head = NULL;
void createList(int n)
{
    struct Node *temp = NULL;
    if (n <= 0)
    {
        printf("The size of the list should be greater than 0.");
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        struct Node *new = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the data for node%d\t", i);
        scanf("%d", &new->data);
        new->next = NULL;
        new->previous = temp;
        if (head == NULL)
        {
            head = new;
        }
        else
        {
            temp->next = new;
        }
        temp = new;
    }
}
void display()
{
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
    while (temp->previous != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->previous;
    }
    printf("%d\n", temp->data);
}
void main()
{
    int n = 0;
    printf("Enter the no. of nodes for the list\n");
    scanf("%d", &n);
    createList(n);
    display();
}