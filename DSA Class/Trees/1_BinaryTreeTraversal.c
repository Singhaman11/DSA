//Binary tree traversal
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
void inOrder(struct Node *root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d, ",  root->data);
    inOrder(root->right);
}
void preOrder(struct Node *root)
{
    if(root == NULL)
        return;
    printf("%d, ",  root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(struct Node *root)
{
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d, ",  root->data);
}
int main()
{
    struct Node *root = NULL;
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    printf("InOrder: ");
    inOrder(root);
    printf("\nPreOrder: ");
    preOrder(root);
    printf("\nPostOrder: ");
    postOrder(root);
    return 0;
}