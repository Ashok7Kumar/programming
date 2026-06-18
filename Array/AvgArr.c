/**
 * file: sumArr.c
 * description: Calculates the sum and floating-point average of an array.
 */

#include <stdio.h>

int main(void)
{
    unsigned int arrSize = 0;
    int sumArr = 0;
    double average = 0.0; // double to store decimals

    printf("Enter the array size: ");
    if (scanf("%u", &arrSize) != 1 || arrSize <= 0) 
    {
        printf("Error: Invalid array size.\n");
        return 1;
    }

    int arr[arrSize];
    
    printf("Please enter %u integers:\n", arrSize);

    for (int i = 0; i < arrSize; i++)
    {
        if (scanf("%d", &arr[i]) != 1) 
        {
            printf("Error: Invalid input.\n");
            return 1; 
        }
    }
	
	for (int i = 0; i < arrSize; i++)
	{
		sumArr += arr[i];
	}

    // Use (double) to ensure floating-point division
    average = (double)sumArr / arrSize;

    // Use %f to print decimals. .2 limits it to two decimal places.
    printf("Sum of the array is %d.\n", sumArr);
    printf("Average of the array is %.2lf.\n", average);

    return 0; 
}