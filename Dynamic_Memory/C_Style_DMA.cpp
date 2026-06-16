#include <iostream>
#include <cstdlib> // Required header for C-style memory management (malloc, calloc, realloc, free)

// ==========================================
// 1. TYPE ALIASES (typedef)
// ==========================================
// Creating platform-independent aliases for clarity and exact-width sizes.
// As discussed earlier, these are core compiler features and do not need a library.
typedef unsigned char UINT8;       // Typically 1 byte (0 to 255)
typedef unsigned short int UINT16; // Typically 2 bytes
typedef unsigned int UINT32;       // Typically 4 bytes (unsigned)
typedef int INT32;                 // Typically 4 bytes (signed)

// ==========================================
// 2. FUNCTION PROTOTYPES
// ==========================================
void malloc_memory_allocation(UINT8 size);
void calloc_memory_allocation(UINT8 size);
void* realloc_memory_allocation(void* ptr, UINT8 size);

int main(void)
{
    UINT8 size = 10; // Operational limit tracker for the loops below
    
    // Test 1: Isolated malloc routine. Allocates, Populates, Prints, and Frees internally.
    malloc_memory_allocation(7);
    
    // Test 2: Isolated calloc routine. Verifies zero-initialization, Populates, Prints, and Frees internally.
    calloc_memory_allocation(9);

    // Test 3: Main-line dynamic allocation.
    // Allocates space for 3 integers (12 bytes total) and zero-initializes them cleanly.
    INT32* dataptr = (INT32*)calloc(3, sizeof(INT32));

    // ⚠️ CRITICAL BUG WARNING: Dangerous Assignment pattern!
    // As mentioned in the Do's and Don'ts, if realloc fails here, it returns NULL.
    // Overwriting 'dataptr' directly with NULL causes a permanent memory leak of the original 3 items!
    // Also, it resizes the array to 10 elements.
    dataptr = (int*)realloc_memory_allocation((void*)dataptr, size;

    // ⚠️ RUNTIME BUG WARNING: Out-of-Bounds Memory Read!
    // The 'size' variable is set to 7. However, the initial calloc only allocated 3 elements.
    // Even though realloc expanded it to 10, the newly added indices (3 to 6) are completely 
    // uninitialised garbage values. Printing them displays random system memory artifacts.
    std::cout << "\n---------- Main: Initial / Reallocated Values ----------" << std::endl;
    for (int i = 0; i < size; i++){
        std::cout << "Value at the location:" << dataptr[i] << std::endl;
    }
    
    // Populating the newly expanded array (Indices 0 through 6)
    for (int i = 0; i < size; i++){
        dataptr[i] = i * 10;
    }

    // Printing the newly assigned values
    std::cout << "\n---------- Main: Assigned Values ----------" << std::endl;
    for (int i = 0; i < size; i++){
        std::cout << "Value at the location:" << dataptr[i] << std::endl;
    }

    // Clean up heap memory to eliminate resource leaks.
    free(dataptr);
    dataptr = NULL; // Setting pointer to NULL protects against use-after-free bugs.
}

// ==========================================
// 3. FUNCTION DEFINITIONS
// ==========================================

void malloc_memory_allocation(UINT8 size){
    std::cout << "----------malloc function----------------" << std::endl;
    
    // Allocates 'size * 4' bytes of raw, uninitialized memory on the heap.
    // C++ requires the explicit typecast '(INT32 *)' from the returned 'void*'.
    INT32 *ptr = (INT32 *) malloc(size * sizeof(INT32));

    if (ptr==NULL){
        std::cout<<"No memory is assigned<<"std::<<endl;
    }
   
    // Populating the uninitialized space to override random garbage values.
    for (int i = 0; i < size; i++){
        ptr[i] = i * 4;
    }

    // Printing data back out
    for (int i = 0; i < size; i++){
        std::cout << "Value at the location:" << ptr[i] << std::endl;
    }

    // Clean up local heap allocations before exiting the function block.
    free(ptr);
    ptr = NULL; 
}

void calloc_memory_allocation(UINT8 size){
    std::cout << "----------Calloc function----------------" << std::endl;
    
    // Allocates space and forces absolute zero-initialization for all elements.
    INT32 *ptr = (INT32 *) calloc(size, sizeof(INT32));

    // Verifying zero-initialization. All outputs here will read exactly '0'.
    std::cout << "[Checking Default Values (Guaranteed Zeroes)]" << std::endl;
    for (int i = 0; i < size; i++){
        std::cout << "Value at the location:" << ptr[i] << std::endl;
    }
    
    // Overwriting the zeroes with real working data
    for (int i = 0; i < size; i++){
        ptr[i] = i * 3;
    }

    // Printing modified values
    std::cout << "[Checking Assigned Values]" << std::endl;
    for (int i = 0; i < size; i++){
        std::cout << "Value at the location:" << ptr[i] << std::endl;
    }

    // Clean up local heap space
    free(ptr);
    ptr = NULL;
}

void* realloc_memory_allocation(void* ptr, UINT8 size){
    std::cout << "----------Realloc function----------------" << std::endl;
    
    // Resizes the target buffer block to the new size requirement.
    // It accepts a raw 'void*' block so it can process any pointer type passing through.
    void *dptr = realloc(ptr, size * sizeof(INT32));

    return (dptr); // Returns the address of the modified memory block back to the caller
}