#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isEmpty();
struct Node
{
    char data;
    struct Node *next;
}*head = NULL;
void push(char element)
{
    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    new -> data = element;
    new -> next = NULL;
    if(head != NULL)
        new -> next = head;
    head = new;
}
char pop()
{
    struct Node *deleteNode = NULL;
    char c;
    if(isEmpty() == 1)
    {
        return -1;
    }
    else if(head->next == NULL)
    {
        c = head -> data;
        head = NULL;
        return c;
    }
    else
    {
        deleteNode = head;
        c = head -> data;
        head = head -> next;
        free(deleteNode);
        return c;
    }
}
char peek()
{
    if(isEmpty() == 1)
        return -1;
    else
        return head->data;
}
int isEmpty()
{
    if(head == NULL)
        return 1;
    else
        return 0;
}
int priority(char c)
{
    if(c == '^')
        return 3;
    else if(c == '/' || c == '*' || c == '%')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    return -1;
}
void Infix_to_Postfix(char arr[])
{
    int n = strlen(arr);
    char postfix[n];
    memset(postfix, '\0', n);
    int j = 0;
    int s = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] >= 'A' && arr[i] <= 'Z')
            postfix[j++] = arr[i];
        else if(arr[i] == '(' || isEmpty() == 1 || priority(arr[i]) > priority(peek()))
            push(arr[i]);
        else if(arr[i] == ')')
        {
            while(peek() != '(')
            {
                postfix[j++] = pop();
            }
            if(isEmpty() != 1)
                pop();
        }   
        else if(priority(arr[i]) == 3 && priority(peek()) == 3)
        {
            push(arr[i]);
            printf("XXX");
        }
        else if(priority(arr[i]) <= priority(peek()))
        {
            while(priority(arr[i]) <= priority(peek()))
            {
                postfix[j++] = pop();
            }
            push(arr[i]);
        }
    }
    while(isEmpty() != 1)
    {
        postfix[j++] = pop();
    }
    printf("Postfix expression: ");
    for(int i = 0; i < n; i++)
    {
        printf("%c", postfix[i]);
    }
}
void main()
{
    int c = 0;
    char character[100];
    memset(character, '\0', 100);
    printf("Enter the string.\n");
    scanf("%s", character);
    printf("Infix expression: ");
    for(int i = 0; i < strlen(character); i++)
    {
        printf("%c", character[i]);
    }
    printf("\n");
    Infix_to_Postfix(character);
}