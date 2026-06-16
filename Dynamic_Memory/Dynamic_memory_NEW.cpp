#include <iostream>

int main() {
    // 1. Allocate space for an integer and store its address in a pointer
    int* ptr = new int; 

    // 2. Initialize the value using the dereference operator (*)
    *ptr = 42; 

    std::cout << "Value: " << *ptr << " at Address: " << ptr << "\n";

    // 3. Free the memory when done
    delete ptr; 

    // 4. Good practice: Reset to null to avoid using a "dangling pointer"
    ptr = (int *) NULL; 
}