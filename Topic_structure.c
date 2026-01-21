#include<stdio.h>
#include<conio.h>

// User Defined DataType - Structure for Student data
struct Student
{
    int rno;
    char name[50];
    int std;
    int marks;
};

// Function prototypes
struct Student scanData(struct Student s);
void dispData(struct Student s);

// Global Function to scan student data
struct Student scanData(struct Student s)
{
    printf("\nEnter Rno : ");
    scanf("%d", &s.rno);
    fflush(stdin); // Clear input buffer
    printf("\nEnter Name : ");
    gets(s.name);
    printf("\nEnter Std : ");
    scanf("%d", &s.std);
    printf("\nEnter Marks : ");
    scanf("%d", &s.marks);
    
    return s;
}

// Function to display student data
void dispData(struct Student s)
{
    printf("\n%d\t%s\t%d\t%d", s.rno, s.name, s.std, s.marks);
}

void main()
{
    struct Student s[3];
    int i;
    

    // Input data for 3 students
    for(i = 0; i < 3; i++)
    {
        printf("\nEnter details for student %d:", i + 1);
        s[i] = scanData(s[i]);
    }

    // Display all student records
    printf("\n\nStudent Records:");
    printf("\nRno\tName\tStd\tMarks");
    printf("\n--------------------------------");
    
    for(i = 0; i < 3; i++)
    {
        dispData(s[i]);
    }
    
    getch();
}