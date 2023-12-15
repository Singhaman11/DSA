#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* BST_insert(struct Node *root, int value)
{
    if(root == NULL)
    {
        struct Node *new = (struct Node*) malloc(sizeof(struct Node));
        new -> data = value;
        new -> left = NULL;
        new -> right = NULL;
        return new;
    }
    else if(root->data > value)
    {
        root->left = BST_insert(root->left, value);
    }
    else if(root->data < value)
    {
        root->right = BST_insert(root->right, value);
    }
    return root;
}

struct Node *BST_search(struct Node *root, int value)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->data == value)
    {
        return root;
    }
    else if(root->data > value)
    {
        return BST_search(root->left, value);
    }
    else
    {
        return BST_search(root->right, value);
    }
}

struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* BST_delete(struct Node *root, int value)
{
    if (root == NULL) return root;
    if (value < root->data)
        root->left = BST_delete(root->left, value);
    else if (value > root->data)
        root->right = BST_delete(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = BST_delete(root->right, temp->data);
    }
    return root;
}

void postorder(struct Node *root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d, ",  root->data);
}

void main()
{
    struct Node *root = NULL;
    int c = 0, v = 0;
    do
    {
        printf("Enter 1 to insert an element.\n");
        printf("Enter 2 to search an element.\n");
        printf("Enter 3 to delete an element.\n");
        printf("Enter 4 to find post order.\n");
        printf("Enter 5 to exit.\n");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                printf("Enter the value to be inserted.\n");
                scanf("%d", &v);
                root = BST_insert(root, v);
                break;
            case 2:
                printf("Enter the value to be searched.\n");
                scanf("%d", &v);
                if(BST_search(root, v) != NULL)
                    printf("%d is present in the BST.\n", v);
                else
                    printf("%d is not present in the BST.\n", v);
                break;
            case 3:
                printf("Enter the value to be deleted.\n");
                scanf("%d", &v);
                root = BST_delete(root, v);
                break;
            case 4:
                postorder(root);
                printf("\n");
                break;
            default:
                break;
        }
    }
    while(c < 5);
}
