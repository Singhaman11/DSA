//Input restricted Deque using Double linked list.
//Insertion from front & deletion from both the ends.

//Output restricted Deque using Double linked list.
//Deletion from front & insertion from both the ends.

#include<stdio.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}*front = NULL, *rear = NULL;
