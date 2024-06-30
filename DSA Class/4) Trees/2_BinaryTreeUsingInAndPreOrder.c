// Binary tree using InOrder & PreOrder.
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
struct Node *builtTree(int preOrder[], int inOrder[], int start, int end)
{
    static int ind = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preOrder[ind];
    ind++;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = curr;
    newNode->left = NULL;
    newNode->right = NULL;
    if (start != end)
    {
        int pos = search(inOrder, start, end, curr);
        newNode->left = builtTree(preOrder, inOrder, start, pos - 1);
        newNode->right = builtTree(preOrder, inOrder, pos + 1, end);
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
void main()
{
    int inOrder[] = {4, 2, 5, 1, 3};
    int preOrder[] = {1, 2, 4, 5, 3};
    struct Node *root = builtTree(preOrder, inOrder, 0, 4);
    printf("InOrder: ");
    printInOrder(root);
}