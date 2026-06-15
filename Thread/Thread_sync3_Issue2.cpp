#include <iostream>
#include <pthread.h>

struct Point { 
    int x; 
    int y; 
};

Point global_point = {0, 0}; // Shared resource

void* writer(void* arg) {
    for (int i = 0; i < 100000; ++i) {
        global_point.x = 9;
        global_point.y = 9;
        global_point.x = 0;
        global_point.y = 0;
    }
    return NULL;
}

void* reader(void* arg) {
    for (int i = 0; i < 100000; ++i) {
        // Bug: Can read halfway through the writer's operations
        int current_x = global_point.x;
        int current_y = global_point.y;
        
        if (current_x != current_y) {
            std::cout << "Data Corruption! x=" << current_x << ", y=" << current_y << std::endl;
            break;
        }
    }
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