#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;
};
int size(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while(temp != 0)
    {
        count++;
        temp = temp -> next;
    }
    return count;
}
void createList(struct Node **head, int n)
{
    struct Node *newNode, *temp;
    if(n <= 0)
    {
        printf("List size must be greater than zero.\n");
        return;
    }
    *head = (struct Node *) malloc(sizeof(struct Node));
    if(*head == NULL)
    {
        printf("Unable to allocate memmory.\n");
        return;
    }
    printf("Enter data of node 1: ");
    scanf("%d", &(*head) -> data);
    (*head) -> next = NULL;
    (*head) -> previous = NULL;
    temp = *head;
    for (int i = 2; i <= n; i++)
    {
        newNode = (struct Node *) malloc(sizeof(struct Node));
        if(newNode == NULL)
        {
            printf("Unable to allocate memory.\n");
            break;
        }
        printf("Enter data of node %d: ", i);
        scanf("%d", &newNode -> data);
        newNode -> next = NULL;
        newNode -> previous = NULL;
        temp -> next = newNode;
        newNode -> previous = temp;
        temp = temp -> next;
    }
}
void traverseList(struct Node *head)
{
    struct Node *temp = head;
    if(temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    while(temp != NULL)
    {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("Null\n");
    temp = head;
    printf("Null");
    while(temp != NULL)
    {
        printf(" <- %d", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
int searchList(struct Node *head, int key)
{
    int index = 0;
    struct Node *curNode = head;
    while(curNode != NULL && curNode -> data != key)
    {
        index++;
        curNode = curNode -> next;
    }
    return (curNode != NULL) ? index : -1;
}
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.\n");
        return;
    }
    newNode -> data = data;
    newNode -> next = *head;
    newNode -> previous = NULL;
    (*head) -> previous = newNode;
    *head = newNode;
}
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.\n");
        return;
    }
    newNode -> data = data;
    newNode -> next = NULL;
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    newNode -> previous = temp;
    temp -> next = newNode;
}
void insertAtN(struct Node **head, int data, int position)
{
    if(position < 1 || position > size(*head) + 1)
    {
        printf("Invalid position! Please enter position between 1 to %d\n", size(*head));
        return;
    }
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory.\n");
        return;
    }
    newNode -> data = data;
    if(position == 1)
    {
        newNode -> next = *head;
        newNode -> previous = NULL;
        (*head) -> previous = newNode;
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    for(int i = 1; i < (position - 1); i++)
        temp = temp -> next;
    newNode -> next = temp -> next;
    newNode -> previous = temp;
    temp -> next = newNode;
    newNode -> next -> previous = newNode;
}
void deleteFirstNode(struct Node **head) 
{
    if(*head == NULL)
    {
        printf("List is already empty.\n");
        return;
    }
    struct Node *toDelete = *head;
    *head = (*head) -> next;
    (*head) -> previous = NULL;
    free(toDelete);
}
void deleteLastNode(struct Node **head)
{
    if(*head == NULL)
    {
        printf("List is already empty.\n");
        return;
    }
    struct Node *toDelete = *head;
    struct Node *secondLastNode = *head;
    while(toDelete -> next != NULL)
    {
        secondLastNode = toDelete;
        toDelete = toDelete -> next;
    }
    if(toDelete == *head)
    {
        *head = NULL;
    }
    else
    {
        secondLastNode -> next = NULL;
    }
    free(toDelete);
}
void deleteNthNode(struct Node **head, int position)
{
    int i;
    if(*head == NULL)
    {
        printf("List is already empty.\n");
        return;
    }
    struct Node *toDelete = *head;
    struct Node *prevNode = *head;
    if(position == 1)
    {
        *head = (*head) -> next;
        (*head) -> previous = NULL;
        free(toDelete);
        return;
    }
    for(i = 2; i <= position; i++)
    {
        prevNode = toDelete;
        toDelete = toDelete -> next;
        if(toDelete == NULL)
            break;
    }
    if(toDelete != NULL)
    {
        prevNode -> next = toDelete -> next;
        toDelete -> next -> previous = prevNode;
        toDelete -> next = NULL;
        toDelete -> previous = NULL;
        free(toDelete);
    }
    else
    {
        printf("Invalid position!\n");
    }
}
int main()
{
    int n, data, choice, position, index;
    struct Node *head = NULL;
    do
    {
        printf("SINGLE LINKED LIST PROGRAM\n");
        printf("1. Create List\n");
        printf("2. Traverse List\n");
        printf("3. Search Element\n");
        printf("4. Insert Node\n");
        printf("5. Delete Node\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(&head, n);
                break;
            case 2:
                traverseList(head);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &data);
                index = searchList(head, data);
                if(index >= 0)
                    printf("%d found in the list at position %d\n", data, index + 1);
                else
                    printf("%d not found in the list.\n", data);
                break;
            case 4:
                printf("Enter data of the new node: ");
                scanf("%d", &data);
                printf("Enter the position where you want to insert new node: ");
                scanf("%d", &position);
                if(position == 1)
                    insertAtBeginning(&head, data);
                else if(position == size(head) + 1)
                    insertAtEnd(&head, data);
                else
                    insertAtN(&head, data, position);
                break;
            case 5:
                printf("Enter the position of node you want to delete: ");
                scanf("%d", &position);
                if(position == 1)
                    deleteFirstNode(&head);
                else if(position == size(head))
                    deleteLastNode(&head);
                else
                    deleteNthNode(&head, position);
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    while (choice != 0);
    return 0;
}