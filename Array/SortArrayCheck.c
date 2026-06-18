/**
 * file" SortArrayCheck.c
 * description: Checks if a given array is sorted in ascending order.
 */

#include <stdio.h>
#include <stdbool.h> // Standard boolean library

#define ARRAY_SIZE 7

// Function Prototype
bool CheckArray(int *arr, int size);

int main(void)
{
    int array[ARRAY_SIZE] = {0};
    bool isSorted = false; 
    
    printf("Please enter %d integers:\n", ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (scanf("%d", &array[i]) != 1) 
        {
            printf("Error: Invalid input.\n");
            return 1; 
        }
    }
	
    isSorted = CheckArray(array, ARRAY_SIZE);

    if (isSorted)
    {
        printf("Array is sorted!\n");
    }
    else
    {
        printf("Array is not sorted!\n");
    }

    return 0;
}

/**
 * Checks if the array is sorted in non-decreasing (ascending) order.
 */
bool CheckArray(int *arr, int size)
{
    if ((size==0 ) || (size==1))
	{
		return true;
	}
	else
	{
     	// Start by assuming it is sorted
		for (int i = 1; i < size; i++)
		{
			// If the current element is smaller than the previous one, it's not sorted
			if (arr[i] < arr[i - 1])
			{
				return false; // Exit early if we find an unsorted pair
			}
        }
	}
    return true; 
}

