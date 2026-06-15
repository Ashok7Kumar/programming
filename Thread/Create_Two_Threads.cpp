#include <iostream>
#include<stdio.h>
#include <pthread.h>

void* print_message(void* arg) {
    char* msg = (char*)arg;
    printf("%s\n", msg);
    return NULL;
}

int main() {
    // 1. Declare two separate thread IDs
    pthread_t thread1, thread2;

    char * msg1 = (char*)"Hello from Thread 1";
    char * msg2 = (char*)"Hello from Thread 2";

    // 2. Create the first thread
    pthread_create(&thread1, NULL, print_message, (void*)msg1);

    // 3. Create the second thread
    pthread_create(&thread2, NULL, print_message, (void*)msg2);

    // 4. Wait for both threads to finish execution
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have finished execution.\n");
    return 0;
}