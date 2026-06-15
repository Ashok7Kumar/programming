#include <iostream>
#include <pthread.h>

int global_counter = 0; // Shared resource

void* increment(void* arg) {
    for (int i = 0; i < 100000; ++i) {
        global_counter++; // Bug: Not synchronized
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Prints an unpredictable number less than 200000
    std::cout << "Final Counter: " << global_counter << std::endl;
    return 0;
}