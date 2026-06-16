#include <iostream>

int main() {
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;

    // 1. Allocate an array of 'size' elements. 
    // The empty braces {} automatically zero-initialize all elements.
    int* arr = new int[size](); 

    // 2. Use it just like a normal array
    arr[0] = 10;
    arr[1] = 20;

    // 3. CRITICAL: Use delete[] with brackets for arrays
    delete[] arr; 
    arr = NULL;
}