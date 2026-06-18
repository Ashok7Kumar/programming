/**
 * file: sumArr.c
 * description: Calculates the sum of all elements in an integer array.
 */

#include <stdio.h>

int main(void)
{
    unsigned int arrSize = 0;
    int sumArr = 0;

    printf("Enter the array size: ");
    // 1. Validate that the user enters a number and it's greater than 0
    if (scanf("%u", &arrSize) != 1 || arrSize <= 0) 
    {
        printf("Error: Invalid array size.\n");
        return 1;
    }

    // 2. Variable Length Array (VLA) - allocates memory based on arrSize
    int arr[arrSize];
    
    printf("Please enter %u integers:\n", arrSize);

    // 3. Fill the array with input validation
    for (int i = 0; i < arrSize; i++)
    {
        if (scanf("%d", &arr[i]) != 1) 
        {
            printf("Error: Invalid input.\n");
            return 1; 
        }
    }
	
    // 4. Loop through the array and accumulate the total
	for (int i = 0; i < arrSize; i++)
	{
		sumArr += arr[i];
	}

	printf("Sum of the array is %d.\n", sumArr);

    return 0; // Signal successful program completion
}