#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


#define SIZE 10

void main()
{
    int a[SIZE], b[SIZE], c[SIZE];
    int choice, choice1, key;
    int i, j, temp;
    int count = 0;
    int exch = 1;
    int k, flag = -1, low, high, mid;
    

    
    // Input array A
    printf("Enter values for array A (%d elements):\n", SIZE);
    for(i = 0; i < SIZE; i++)
    {
        printf("Enter the value of a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    
    // Input array B
    printf("\nEnter values for array B (%d elements):\n", SIZE);
    for(i = 0; i < SIZE; i++)
    {
        printf("Enter the value of b[%d]: ", i);
        scanf("%d", &b[i]);
    }
    
    // Main menu loop
    while(1)
    {
        
        printf("\n========== ARRAY OPERATIONS MENU ==========\n");
        printf("1. Add Arrays (A + B)\n");
        printf("2. Subtract Arrays (A - B)\n");
        printf("3. Multiply Arrays (A * B)\n");
        printf("4. Divide Arrays (A / B)\n");
        printf("5. Sort Array A\n");
        printf("6. Search in Array A\n");
        printf("7. Exit\n");
        printf("==========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:  // Add arrays
                printf("\nArray Addition (A + B):\n");
                for(i = 0; i < SIZE; i++)
                {
                    c[i] = a[i] + b[i];
                    printf("%d + %d = %d\n", a[i], b[i], c[i]);
                }
                break;
                
            case 2:  // Subtract arrays
                printf("\nArray Subtraction (A - B):\n");
                for(i = 0; i < SIZE; i++)
                {
                    c[i] = a[i] - b[i];
                    printf("%d - %d = %d\n", a[i], b[i], c[i]);
                }
                break;
                
            case 3:  // Multiply arrays
                printf("\nArray Multiplication (A * B):\n");
                for(i = 0; i < SIZE; i++)
                {
                    c[i] = a[i] * b[i];
                    printf("%d * %d = %d\n", a[i], b[i], c[i]);
                }
                break;
                
            case 4:  // Divide arrays
                printf("\nArray Division (A / B):\n");
                for(i = 0; i < SIZE; i++)
                {
                    if(b[i] != 0)
                    {
                        c[i] = a[i] / b[i];
                        printf("%d / %d = %d\n", a[i], b[i], c[i]);
                    }
                    else
                    {
                        printf("%d / %d = Division by zero error!\n", a[i], b[i]);
                        c[i] = 0;
                    }
                }
                break;
                
            case 5:  // Sort array A
                printf("\nThe unsorted array is:\n");
                for(i = 0; i < SIZE; i++)
                {
                    printf("%d ", a[i]);
                }
                
                // Bubble sort with sound effect
                count = 0;
                exch = 1;
                for(i = 0; i < SIZE - 1 && exch == 1; i++)
                {
                    exch = 0;
                    for(j = 0; j < SIZE - i - 1; j++)
                    {
                        count++;
                        if(a[j] > a[j + 1])
                        {
                            exch = 1;
                            temp = a[j];
                            a[j] = a[j + 1];
                            a[j + 1] = temp;
                            
                        }
                    }
                }
                
                printf("\n\nSorted array is:\n");
                for(i = 0; i < SIZE; i++)
                {
                    printf("%d ", a[i]);
                }
                printf("\nNumber of comparisons: %d", count);
                break;
                
            case 6:  // Search in array A
                printf("\nSearch Options:\n");
                printf("1. Linear Search\n");
                printf("2. Binary Search (Array must be sorted first!)\n");
                printf("Enter your choice: ");
                scanf("%d", &choice1);
                
                switch(choice1)
                {
                    case 1:  // Linear Search
                        flag = -1;
                        printf("Enter the key to search: ");
                        scanf("%d", &key);
                        
                        for(i = 0; i < SIZE; i++)
                        {
                            if(key == a[i])
                            {
                                flag = i;
                                break;
                            }
                        }
                        
                        if(flag >= 0)
                        {
                            printf("Key %d found at index %d\n", key, flag);
                        }
                        else
                        {
                            printf("The key %d was not found in the array\n", key);
                        }
                        break;
                        
                    case 2:  // Binary Search
                        // Check if array is sorted
                        for(i = 0; i < SIZE - 1; i++)
                        {
                            if(a[i] > a[i + 1])
                            {
                                printf("Array is not sorted! Please sort first using option 5.\n");
                                break;
                            }
                        }
                        
                        if(i < SIZE - 1)  // Array was not sorted
                        {
                            break;
                        }
                        
                        low = 0;
                        flag = -1;
                        high = SIZE - 1;
                        
                        printf("Enter the key to search: ");
                        scanf("%d", &key);
                        
                        while(low <= high)
                        {
                            mid = (low + high) / 2;
                            
                            if(a[mid] == key)
                            {
                                flag = mid;
                                break;
                            }
                            else if(key > a[mid])
                            {
                                low = mid + 1;
                            }
                            else
                            {
                                high = mid - 1;
                            }
                        }
                        
                        if(flag >= 0)
                        {
                            printf("%d found at index %d\n", key, flag);
                        }
                        else
                        {
                            printf("The key %d was not found in the array\n", key);
                        }
                        break;
                        
                    default:
                        printf("Invalid search choice!\n");
                }
                break;
                
            case 7:  // Exit
                printf("\nExiting program...\n");
                exit(0);
                break;
                
            default:
                printf("Invalid choice! Please enter 1-7.\n");
        }
        
        printf("\n\nPress any key to continue...");
        getch();
    }
}