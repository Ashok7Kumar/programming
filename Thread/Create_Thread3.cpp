#include <stdio.h>
#include <pthread.h>

typedef struct {
    int a;
    int b;
    int result; // The thread will write directly here
} SumData;

void* sum_function(void* arg) {
    SumData* data = (SumData*)arg;
    
    // Write directly into the main thread's struct memory
    data->result = data->a + data->b; 
    
    return NULL; // No need to return anything via pthread_exit
}

int main() {
    pthread_t thread_id;
    SumData data = {5, 10, 0}; // Allocate on main's stack

    pthread_create(&thread_id, NULL, sum_function, &data);
    pthread_join(thread_id, NULL); // Wait for thread to finish

    // The data.result is now safely populated
    printf("The sum is: %d\n", data.result); 
    return 0;
}