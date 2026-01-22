#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define ROW 36
#define COL 36

int a[ROW][COL], b[ROW][COL], c[ROW][COL] = {0};
int r1, c1, r2, c2;

void scanArray();
void displayArray();
void mult();
void add();
void sub();
void devision();
void sort();
void menu();

void main()
{
    int i, j, k;
    int choice;
    
    
    scanArray();
    displayArray();
    
    
    while(1) {
        menu();
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add();
                break;
            case 2:
                sub();
                break;
            case 3:
                mult();
                break;
            case 4:
                devision();
                break;
            case 5:
                sort();
                printf("\nSort array option selected");
                break;
            case 6:
                printf("\nSearch array option selected");
                break;
            case 7:
                printf("\nExit...");
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
        
        getch();
    }
}

void menu()
{
    printf("\n1- Add");
    printf("\n2- Subtract");
    printf("\n3- Multiply");
    printf("\n4- Divide");
    printf("\n5- Sort the array");
    printf("\n6- Search the array");
    printf("\n7- Exit");
}

void scanArray()
{
    int i, j;
    
    printf("\nEnter the number of rows and columns for the first array: ");
    scanf("%d%d", &r1, &c1);
    
    printf("Enter the number of rows and columns for the 2nd array: ");
    scanf("%d%d", &r2, &c2);
    
    if(r1 > 30 || c1 > 30 || r2 > 30 || c2 > 30) {
        printf("The size cannot go above 30");
        return;
    }
    
    printf("\nEnter the values for first matrix (%d values):\n", r1 * c1);
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c1; j++) {
            printf("Enter the value of a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("\nEnter the values for 2nd matrix (%d values):\n", r2 * c2);
    for(i = 0; i < r2; i++) {
        for(j = 0; j < c2; j++) {
            printf("Enter the value of b[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
}

void displayArray()
{
    int i, j ;
    
    
    printf("\nThe matrixes are as follows:\n");

    int maxRow = (r1 > r2) ? r1 : r2;
    for(i = 0; i < maxRow; i++) {
        // Print row from first matrix
        if(i < r1) {
            for(j = 0; j < c1; j++) {
                printf("%d ", a[i][j]);
            }
        } else {
            for(j = 0; j < c1; j++) {
                printf("  ");          // Print spaces if row doesn't exist
            }
        }

        printf("\t\t"); // Separate between matrices

        // Print row from second matrix
        if(i < r2) {
            for(j = 0; j < c2; j++) {
                printf("%d ", b[i][j]);
            }
        }

        printf("\n"); // New line after each row
    }

    
}

void add()
{
    int i, j;
    
    if((r1 == r2) && (c1 == c2)) {
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++) {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        
        printf("\nThe addition is as follows:\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++) {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nThe matrices are not conformable for addition!");
    }
}

void sub()
{
    int i, j;
    
    if((r1 == r2) && (c1 == c2)) {
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++) {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        
        printf("\nAfter subtraction is as follows:\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c1; j++) {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nThe matrices are not conformable for subtraction!");
    }
}

void mult()

{
    int i, j, k;
    
    if(c1 == r2) {
        // Reset result matrix to 0
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c2; j++) {
                c[i][j] = 0;
            }
        }
        
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c2; j++) {
                for(k = 0; k < c1; k++) {
                    c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
                }
            }
        }
        
        printf("\nThe resultant matrix after multiplication is:\n");
        for(i = 0; i < r1; i++) {
            for(j = 0; j < c2; j++) {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nIt is not possible to multiply the matrices!");
    }
}

void sort()
{
    int arr[9];
    int exch = 1;
    int k = 0, i, j, temp;
    int sortedArray[3][3];
    
    // Copy 3x3 matrix 'a' into 1D array 'arr'
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            arr[k] = a[i][j];
            k++;
        }
    }
    
    // Bubble sort the 1D array
    for(i = 0; i < 9 && exch == 1; i++) {
        exch = 0;
        for(j = 0; j < 8; j++) {
            if(arr[j] > arr[j + 1]) {
                exch = 1;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    // Copy sorted 1D array back to 2D array
    k = 0;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            sortedArray[i][j] = arr[k];
            k++;
        }
    }
    
    // Display the sorted array
    printf("The sorted array is\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", sortedArray[i][j]);
        }
        printf("\n");
    }
} //end of sort

void devision()
{
    int i, j, k;

    float detemint = (b[0][0] * b[1][1]) - (b[0][1] * b[1][0]);  // calculating determinant
    
    // Find the Inverse matrix of b = inverseB
    float inverseB[2][2];

    inverseB[0][0] = (float)b[1][1] / detemint;
    inverseB[0][1] = (float)-b[0][1] / detemint;  
    inverseB[1][0] = (float)-b[1][0] / detemint;
    inverseB[1][1] = (float)b[0][0] / detemint;

    
    // to devide the matrix a by b we have to multiply a by the inverse of b(it is arr here)
    // Reset result matrix to 0

    float result[2][2] = {0};
        
        
        for(i = 0; i < 2; i++) {
            for(j = 0; j < 2; j++) {
                for(k = 0; k < 2; k++) {
                    result[i][j] = result[i][j] + ((float)a[i][k] * inverseB[k][j]);
                }
            }
        }
        
        printf("\nThe resultant matrix after multiplication is:\n");
        for(i = 0; i < 2; i++) {
            for(j = 0; j < 2; j++) {
                printf("%.2f ", result[i][j]);
            }
            printf("\n");
        }


    
} // End of devision