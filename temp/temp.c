// AddDetail asks whether to add the node in the begning or end.
// Update single student detail(Name) based on roll no. given.
// New Display function ask which field to display(Someone enters 1 then print all the roll no.)
// Add section and subjects

/*
Create a student database (max. 10 students).
Details:
    Name
    Roll No.
    Section
    Subject should be C, C++, Java & might also have all 3 of them.
1) Inserting a student detail.
2) Update a student's subject operating with respect to Roll no.
3) Show detail of 1 student and ask for inserion or updation.
4) Show detail of all students and ask for above 3 options, also give an option to exit the program.
5) Exit
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
    int RollNo;
    char Name[20];
    int Section;
    struct subject *subject_start_ptr;
    struct student *next;
};

struct subject
{
    char Subject[10];
    struct subject *next;
};
struct student *start = NULL;
struct subject *CreateSubjectNode(int);
struct student *CreateStudetnNode();
/*
void AddNodeEnd()
{
    int n = 1;
    // ptr is pointer to a student structure.
    struct student *ptr = (struct student*) malloc(sizeof(struct student));
    struct student *temp = NULL;
    printf("Enter the Student's name\n");
    scanf("%s", (ptr -> Name));
    printf("Enter the Student's section\n");
    scanf("%s", &(ptr -> Section));
    printf("Enter the Student's roll no.\n");
    scanf("%d", &(ptr -> RollNo));
    ptr -> next = NULL;
    if(start == NULL)
        start = ptr;
    else
    {
        temp = start;
        while((temp -> next) != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = ptr;
    }
    printf("Student detail inserted successfully in the database.\n");    
}
*/

 struct subject *CreateSubjectNode(int i)
 {
        // this is subject node
        
      	struct subject *temp = NULL;
        temp =  (struct subject*) malloc(sizeof(struct subject));
        
        printf("Enter %d subject name", i+1);
        scanf("%s", temp -> Subject);
        temp -> next = NULL;
 }       
        
 struct student *CreateStudetnNode()
 {
    int n = 0;
     // ptr is pointer to a student structure.
    struct student *ptr = (struct student*) malloc(sizeof(struct student));

    printf("Enter the Student's roll no.\n");
    scanf("%d", &(ptr -> RollNo));
    printf("Enter the Student's name\n");
    scanf("%s", (ptr -> Name));
    printf("Enter the Student's section\n");
    scanf("%d", &(ptr -> Section));
    ptr->subject_start_ptr = NULL;
    ptr -> next = NULL;
    printf("Enter the no. of subjects\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        struct subject *temp = NULL;
        
        temp = CreateSubjectNode(i);
		if (temp == NULL){
        	printf("Creation of subject failed");
            return NULL;
        }
        
        // Updating a subject for subject linked list of a particular student, adding at the start (ptr->subject_start_ptr)
    		if(ptr->subject_start_ptr == NULL) {
        	ptr->subject_start_ptr = temp;
    		}   
    		else
    		{
        		temp->next = ptr->subject_start_ptr;
            ptr->subject_start_ptr = temp;
        }
        
    }
 }

void AddStudentNode()
{
    int n = 1, ch = 0;

    struct student *ptr = NULL;
    struct student *temp = NULL;
    
    ptr = CreateStudetnNode();
    if (ptr  == NULL) {
        printf("Creation of student failed");
        return;
    }    
    // Updating a student in the student linked list
    if(start == NULL)
        start = ptr;
    else
    {
        printf(" Press 1 to add node at the end of the list\n");
        printf(" Press 2 to add node at the starting of the list\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                temp = start;
                while((temp -> next) != NULL)
                {
                    temp = temp -> next;
                }
                temp -> next = ptr;
                break;
            case 2:
            		ptr->next = start;
                start = ptr;
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    if(ch == 1 || ch == 2)
        printf("Student detail inserted successfully in the database.\n");    
}
void UpdateName(int RN)
{
    struct student *temp = start;
    while(temp != NULL)
    {
        if((temp -> RollNo) == RN)
        {
            printf("Enter the Student's name\n");
            scanf("%s", temp -> Name);
            break;
        }
        else
            temp = temp -> next;
    }
    if(temp == NULL)
        printf("Either the Student's Roll No. entered is incorrect or it does not exist in the database.\n");
}
void Display()
{
    struct student *temp = start;
    int ch = 0;
    printf(" Press 1 to print all the students' roll no.\n");
    printf(" Press 2 to print all the students' name\n");
    printf(" Press 3 to print all the students' section\n");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
            printf("Students' roll no.\n");
            while(temp != NULL)
            {
                printf("%d\n", temp -> RollNo);
                temp = temp -> next;
            }
            break;
        case 2:
            printf("Students' name\n");
            while(temp != NULL)
            {
                printf("%s\n", temp -> Name);
                temp = temp -> next;
            }
            break;
        case 3:
            printf("Students' section\n");
            while(temp != NULL)
            {
                printf("%d\n", temp -> Section);
                temp = temp -> next;
            }
            break;
        default:
            printf("Invalid choice");
    }
}
void PrintDatabase()
{
    struct student *temp = start;
    while(temp != NULL)
    {
        printf("Roll no. %d \n", temp -> RollNo);
        printf("Student's name: %s \n", temp -> Name);
        printf("Student's section: %d \n", temp -> Section);
        printf("Student's subject: ");
        struct subject *temp1 = temp -> subject_start_ptr;
        while(temp1 != NULL)
        {
            printf("%s, ", temp1 -> Subject);
            temp1 = temp1 -> next;
        }
        printf("\n");
        temp = temp -> next;
    }
}
void main()
{
    int RN = 0, choice = 0;
    do
    {
        printf("Enter 1 to add a student detail.\n");
        printf("Enter 2 to update a student name.\n");
        printf("Enter 3 to display one info of all the students.\n");
        printf("Enter 4 to pull detail of all the students\n");
        printf("Enter 5 to exit \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                AddStudentNode();
                break;
            case 2:
                printf("Enter the student's roll no. whose name is to be updated\n");
                scanf("%d", &RN);
                UpdateName(RN);
                break;
            case 3:
                Display();
                break;            
            case 4:
                PrintDatabase();
                break;
            default:
                printf("");
        }
    }
    while(choice < 5);
}