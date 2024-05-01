//Sum of all nodes in Binary tree.
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
int inOrder(struct Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftSum = inOrder(root->left);
    int rightSum = inOrder(root->right);
    return root->data + leftSum + rightSum;
    // return root->data + inOrder(root -> left) + inOrder(root -> right);
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
    printf("Sum = %d", inOrder(root));
    return 0;
}