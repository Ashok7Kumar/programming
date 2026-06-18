/**
 * file: maxInArray.c
 * description: Finds the maximum value in an integer array.
 */
#include <stdio.h>
#include <limits.h> // For INT_MIN
#define ARRAY_SIZE 7

// Function Prototype
int MaxInArray(int *arr, int size);

int main(void)
{
    int array[ARRAY_SIZE] = {0};
    int max = 0; 
    
    printf("Please enter %d integers:\n", ARRAY_SIZE);

    // Read integers from user with input validation
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (scanf("%d", &array[i]) != 1) 
        {
            printf("Error: Invalid input.\n");
            return 1; 
        }
    }
	
    // Call the function MaxInArray
    max = MaxInArray(array, ARRAY_SIZE); 
	
    if (max==INT_MIN)
    {
		printf("Error: Invalid array size or no element in array!", max); 
    }
    else
    {	
		printf("Maximum element in the Array is %d!\n", max);   
	}
    return 0;
}

/*
 * Iterates through the array to find the largest integer.
 * arr Pointer to the first element of the array.
 * size The number of elements in the array.
 * return The maximum integer value found.
 */
int MaxInArray(int *arr, int size)
{
    if (arr == NULL || size <= 0) 
		return (INT_MIN);
    // Start by assuming the first element is the largest
    int maxVal = arr[0];

    for (int i = 1; i < size; i++)
    {
        // If current element is larger than maxVal, update maxVal
        if (maxVal < arr[i]) 
        {
           maxVal = arr[i];
        }
    }	
    return maxVal;
}