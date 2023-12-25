//Stack works on the principle of Last In First Out (LIFO).
//Validate parentheses expression using Array.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define STACK_SIZE 50 
int top = -1;
int stack[STACK_SIZE];
int isEmpty();
void push(char element)
{
    top++;
    stack[top] = element;
}
void pop()
{
    if(isEmpty() != 1)
        top--;
}
char peek()
{
    if(isEmpty() != 1)
        return stack[top];
    return '\0';
}
int isEmpty()
{
    if(top != -1)
        return 0; 
    return 1;
}
bool isValid(char* s)
{
    int n = strlen(s);
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            push(s[i]);
        }
        else if(s[i] == '}' || s[i] == ']' || s[i] == ')')
        {
            char element = peek();
            if(element == '\0')
            {
                return false;
            }
            else if((s[i] == '}' && element == '{') || (s[i] == ']' && element == '[') || (s[i] == ')' && element == '('))
            {
                pop();
            }
        }
        else
        {
            return false;  
        }
    }
    if(isEmpty() == 1)
    {
        return true;
    }
    return false;
}
void main()
{
    int c = 0;
    char element;
    char parenthesis[100];
    memset(parenthesis, '\0', 100);
    printf("Enter the parenthesis string.\n");
    scanf("%s", parenthesis);
    if(isValid(parenthesis) == true)
        printf("VALID\n");
    else
        printf("INVALID\n");
}