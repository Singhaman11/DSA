//Binary tree using PreOrder.
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int element)
{
    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    new -> data = element;
    new -> left = NULL;
    new -> right = NULL;
    return new;
}
