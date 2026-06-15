#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int a;
    int b;
} SumData;

void* sum_function(void* arg) {
    int* result = (int *)malloc(sizeof(int)); // Must be dynamically allocated if local variable is created then it will distroy once function retured
    *result = 5 + 10;
    return (void*)result; 
}

void* sum_function1(void* arg) {
    SumData* data= (SumData*) arg;
    int* result = (int *)malloc(sizeof(int)); // Must be dynamically allocated if local variable is created then it will distroy once function retured
    *result = data->a + data->a;
    return (void*)result; 
}

int main() {
    pthread_t thread_id1, thread_id2;
    void* return_ptr1,*return_ptr2; // Generic pointer to hold the address
    SumData nums={12,34};

    pthread_create(&thread_id1, NULL, sum_function, NULL);
    pthread_create(&thread_id2, NULL, sum_function1, (void*)&nums);

    pthread_join(thread_id1, &return_ptr1); // Passing the address of the pointer
    pthread_join(thread_id2, &return_ptr2); // Passing the address of the pointer

    int* final_sum1 = (int*)return_ptr1; // Cast it back to an int pointer
    printf("The sum is: %d\n", *final_sum1);

    int* final_sum2 = (int*)return_ptr2; // Cast it back to an int pointer
    printf("The sum is: %d\n", *final_sum2 );

    free(final_sum1); // Clean up memory
    free(final_sum2); // Clean up memory
    return 0;
}