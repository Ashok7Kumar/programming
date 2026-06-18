/**
 * file: countDistinct.c
 * description: Counts the number of unique (distinct) elements in an array.
 */

#include <stdio.h>
#include <stdbool.h>

// Using a custom type for a 16-bit unsigned integer
typedef unsigned short int uint16;

// Function Prototype: int *arr is the correct syntax for a pointer
uint16 findDistinct(int *arr, int arrSize);

int main(void)
{
    unsigned int arrSize = 0;
    uint16 numDistinct = 0;

    printf("Enter the array size: ");
    // Validate that the user enters a number and it's greater than 0
    if (scanf("%u", &arrSize) != 1 || arrSize <= 0) 
    {
        printf("Error: Invalid array size.\n");
        return 1;
    }

    // Variable Length Array (VLA)
    int arr[arrSize];
    
    printf("Please enter %u integers:\n", arrSize);

    // Fill the array with input validation
    for (int i = 0; i < arrSize; i++)
    {
        if (scanf("%d", &arr[i]) != 1) 
        {
            printf("Error: Invalid input.\n");
            return 1; 
        }
    }

    // Call the function to count unique numbers
    numDistinct = findDistinct(arr, arrSize);

    // %hu is the format specifier for unsigned short
    printf("Number of distinct elements in the array is: %hu\n", numDistinct);
    
    return 0;
}

/**
 * Logic: For every element, look at all previous elements.
 * If we find a match, it's a duplicate and we don't count it.
 */
uint16 findDistinct(int *arr, int arrSize)
{
    uint16 count = 0;

    for (int i = 0; i < arrSize; i++)
    {
        bool isDistinct = true;

        // The "Look Back" loop: checks index 0 to i-1
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                // We found this number earlier in the array
                isDistinct = false; 
                break; // Stop looking, we know it's a duplicate
            }
        }

        // Only increment if we finished the inner loop without finding a match
        if (isDistinct)
        {
            count++;
        }
    }
    
    return count;
}