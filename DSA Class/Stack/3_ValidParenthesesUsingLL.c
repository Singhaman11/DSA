//Stack works on the principle of Last In First Out (LIFO).
//Validate parentheses expression using Linked List.
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
    {
        new -> next = head;
    }
    head = new;
}
void pop()
{
    struct Node *deleteNode = NULL;
    if(isEmpty() != 1)
    {
        if(head->next == NULL)
        {
            head = NULL;
        }
        else
        {
            deleteNode = head;
            head = head -> next;
            free(deleteNode);
        }
    }    
}
char peek()
{
    if(isEmpty() != 1)
    {
        return head->data;
    }
    return -1;
}
int isEmpty()
{
    if(head != NULL)
    {
        return 0;
    }
    return 1;
}
int checkBracketValidity(char arr[])
{
    struct Node *top1 = NULL;
    int n = strlen(arr);
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == '{' || arr[i] == '[' || arr[i] == '(')
        {
            push(arr[i]);
        }
        else if(arr[i] == '}' || arr[i] == ']' || arr[i] == ')')
        {
            char bracket = peek();
            if(bracket == -1)
            {
                return 0;
            }
            if((arr[i] == '}' && bracket == '{') || (arr[i] == ']' && bracket == '[') || (arr[i] == ')' && bracket == '('))
            {
                pop();
            }
        }
        else
        {
            return 0;    
        }
    }
    if(peek() == -1)
    {
        return 1;
    }
}
void main()
{
    int c = 0;
    char parenthesis[100];
    memset(parenthesis, '\0', 100);
    printf("Enter the parenthesis string.\n");
    scanf("%s", parenthesis);
    if(checkBracketValidity(parenthesis) == 1)
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}