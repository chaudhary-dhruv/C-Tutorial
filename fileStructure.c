#include<stdio.h>
#include<conio.h>

#define SIZE 5

struct Student
{
    int sid;
    char name[30];
    float fees;
    int active;
};

int studentCount = 0;

// Function declarations
void scanStudentDetails(struct Student s[]);
void displayStudentDetails(struct Student t);
void addStudentDetails();

void main()
{
    FILE *fp;
    struct Student s[SIZE];  // Array of students
    struct Student t;
    char fileName[30];
    int i;
    
    
    printf("\nEnter the filename: ");
    scanf("%s", fileName);
    
    fp = fopen(fileName, "wb+");  // Using binary mode for structure writing
    
    if(fp == NULL) {
        printf("\nError opening file!");
        getch();
        return;
    }
    
    // Scan student details
    scanStudentDetails(s);
    
    // Write student data to file
    for(i = 0; i < SIZE; i++) {
        fwrite(&s[i], sizeof(struct Student), 1, fp);
    }

    if(fp == NULL){      
        addStudentDetails();
    }
    
    
    printf("\nThe cursor position is %ld", ftell(fp));
    
    // Reset file pointer to beginning
    fseek(fp, 0, SEEK_SET);
    printf("\nThe cursor position is %ld", ftell(fp));
    
    // Read and display student data from file
    printf("\n\nStudent Details from File:");
    printf("\n===========================");
    for(i = 0; i < SIZE; i++) {
        fread(&t, sizeof(struct Student), 1, fp);
        displayStudentDetails(t);
    }
    
    fclose(fp);
    getch();
    return;
}

// Function to scan student details
void scanStudentDetails(struct Student s[])
{
    int i;
    float temp;
    
    for(i = 0; i < SIZE; i++) {
        printf("\n\nEnter details for Student %d:", i+1);
        printf("\nEnter Student ID and Name: ");
        scanf("%d %s", &s[i].sid, s[i].name);
        printf("Enter the fees: ");
        scanf("%f", &temp);
        s[i].fees = temp;
        s[i].active = 1;  // Mark as active
    }
}

// Function to display student details
void displayStudentDetails(struct Student t)
{
    printf("\n%d\t%s\t%.2f", t.sid, t.name, t.fees);
}

void addStudentDetails(){

    struct Student s;
    int active;
    if(studentCount == SIZE)
    {
        printf("\nStudent List is full.");
        return;
    }
    scanStudentDetails(&s);
    
    

    studentCount++;

    printf("\nStudent record successfully inserted!");
}

    