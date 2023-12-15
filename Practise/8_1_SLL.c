#include<stdio.h>
#include<stdlib.h>
struct data
{
    int RollNo;
    struct data *next;
};
int main()
{
    int x = 5;
    int *y = &x;
    struct data student1;
    student1.RollNo = 378;
    student1.next = NULL;
    struct data *student2 = &student1;
    
    struct data *student3 = NULL;
    student3 = (struct data*) malloc(sizeof(struct data));
    student3 -> RollNo = 654;
    student3 -> next = NULL;

    struct data *student4 = NULL;
    student4 = (struct data*) malloc(sizeof(struct data));
    student4 -> RollNo = 789;
    student4 -> next = NULL;

    struct data *student5 = NULL;
    student5 = (struct data*) malloc(sizeof(struct data*));
    student5 -> RollNo = 555;
    student5 -> next = NULL;

    student3 -> next = student4;
    student4 -> next = student5; 
}