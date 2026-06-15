#include <iostream>
#include <pthread.h>
#include <unistd.h> // For sleep

int data = 0;
bool ready = false; // Shared flags

void* writer(void* arg) {
    sleep(1); // Force reader to start waiting first
    data = 42;
    ready = true; 
    return NULL;
}

void* reader(void* arg) {
    // Bug: Compiler optimization turns this into an infinite loop
    // because it doesn't see 'ready' changing locally.
    while (!ready) {
        // Waiting...
    }
    std::cout << "Data received: " << data << std::endl;
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, writer, NULL);
    pthread_create(&t2, NULL, reader, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}