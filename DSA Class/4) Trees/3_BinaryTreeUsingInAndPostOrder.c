#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
int search(int inOrder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inOrder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
struct Node *builtTree(int rev_postOrder[], int inOrder[], int start, int end)
{
    static int ind = 4;
    if (start > end)
    {
        return NULL;
    }
    int curr = rev_postOrder[ind];
    ind--;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = curr;
    newNode->left = NULL;
    newNode->right = NULL;
    // printf("%d  ", curr);
    if (start != end)
    {
        int pos = search(inOrder, start, end, curr);
        newNode->right = builtTree(rev_postOrder, inOrder, pos + 1, end);
        newNode->left = builtTree(rev_postOrder, inOrder, start, pos - 1);
    }
    return newNode;
}
void printInOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInOrder(root->left);
    printf("%d  ", root->data);
    printInOrder(root->right);
}
void printPostOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d  ", root->data);
}
void printPreOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d  ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}
void main()
{
    int inOrder[] = {4, 2, 5, 1, 3};
    int postOrder[] = {4, 5, 2, 3, 1};
    struct Node *root = builtTree(postOrder, inOrder, 0, 4);
    printf("InOrder: ");
    printInOrder(root);
    printf("\nPostOrder: ");
    printPostOrder(root);
    printf("\nPreOrder: ");
    printPreOrder(root);
}