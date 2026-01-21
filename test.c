#include <stdio.h>

#define ROWS 3
#define COLS1 3 // Columns for the first array
#define COLS2 2 // Columns for the second array

int main() {
    int arr1[ROWS][COLS1] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int arr2[ROWS][COLS2] = {
        {10, 11},
        {12, 13},
        {14, 15}
    };

    printf("Arrays printed horizontally:\n");

    // Iterate through each row of the arrays
    for (int i = 0; i < ROWS; i++) {
        // Print the current row of the first array
        for (int j = 0; j < COLS1; j++) {
            printf("%d ", arr1[i][j]);
        }

        // Add a separator between the two arrays (e.g., a tab)
        printf("\t\t");

        // Print the current row of the second array
        for (int j = 0; j < COLS2; j++) {
            printf("%d ", arr2[i][j]);
        }

        // Move to the next line for the next row
        printf("\n");
    }

    return 0;
}
