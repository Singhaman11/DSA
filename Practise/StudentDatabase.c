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
struct student
{
    char Name[50];
    int RollNo;
    char Section[4];
    char Subject[3][4];
};
void AddDetail(struct student add[], int count)
{
    int n = 1;
    char ch[4];
    printf("Enter the Student's name\n");
    scanf("%s", add[count].Name);
    printf("Enter the Student's roll no.\n");
    scanf("%d", &add[count].RollNo);
    printf("Enter the Student's section\n");
    scanf("%s", add[count].Section);
    printf("Enter the no. of subjects\n");
    scanf("%d", &n);
    if(n > 3)
        n = 3;
    printf("Enter the Student's subject\n (Subject can contain 1, 2 or 3 subjects from C, C++ & Java)\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%s", add[count].Subject[i]);
    }
    printf("Student detail inserted successfully in the database.\n");    
}
void UpdateSubject(struct student *update)
{
    int n = 1;
    printf("Enter the Student's subject\n (Subject can contain 1, 2 or 3 subjects from C, C++ & Java)\n Before that enter the no. of subjects\n");
    scanf("%d", &n);
    for(int i = 0; i < 3; i++)
    {
        if(i < n)
            scanf("%s", update->Subject[i]);
        else
            strcpy(update->Subject[i], "\0");
    }
    printf("Student subject detail updated successfully in the database.\n");
}
void SingleDisplay(struct student display)
{
    printf("Student's name: %s \n", display.Name);
    printf("Roll no. %d \n", display.RollNo);
    printf("Section: %s \n", display.Section);
    printf("Subject: ");
    for (int i = 0; i < 3; i++)
    {
        if(display.Subject[i][0] != '\0')         // can we use (display.Subject[i] != "\0")
            printf("%s, ", display.Subject[i]);
    }
    printf("\n");
}
void PrintDatabase(struct student display[], int *count)
{
    for (int i = 0; i < *count; i++)
    {
        printf("Student's name: %s \n", display[i].Name);
        printf("Roll no. %d \n", display[i].RollNo);
        printf("Section: %s \n", display[i].Section);
        printf("Subject: ");
        for (int j = 0; j < 3; j++)
        {
            if(display[i].Subject[j][0] != '\0')
                printf("%s, ", display[i].Subject[j]);
        }
        printf("\n");
    }
}
void main()
{
    struct student list[10];
    int RN = 0, choice = 0, count = 0, t = 0;
    do
    {
        printf("Enter 1 to add a student detail\n");
        printf("Enter 2 to update the student's subject\n");
        printf("Enter 3 to pull detail of a particular student\n");
        printf("Enter 4 to pull detail of all the students\n");
        printf("Enter 5 to exit \n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                if(count < 10)
                    AddDetail(list, count);
                else
                    printf("Database is full.");
                count++;
                break;
            case 2:
                printf("Enter the Student's roll no. whose subject is to be updated.\n");
                scanf("%d", &RN);
                for (int i = 0; i < count; i++)
                {
                    if(RN == list[i].RollNo)
                    {
                        UpdateSubject(&list[i]);
                        t = 1;
                        break;
                    }
                }
                if(t == 0)
                    printf("Either the Student's Roll No. entered is incorrect or it does not exist in the database.\n");
                t = 0;
                break;
            case 3:
                printf("Enter the Student's roll no. whose detail is to be extracted.\n");
                scanf("%d", &RN);
                for (int i = 0; i < count; i++)
                {
                    if(RN == list[i].RollNo)
                    {
                        SingleDisplay(list[i]);
                        t = 1;
                        break;
                    }
                }
                if(t == 0)
                    printf("Either the Student's Roll No. entered is incorrect or it does not exist in the database.\n");
                t = 0;
                break;
            case 4:
                PrintDatabase(list, &count);
                break;
            default:
                printf("");
        }
    }
    while(choice < 5);
}