#include <iostream>
#include <pthread.h>

pthread_mutex_t my_mutex;
int global_counter = 0;

// 1. The RAII Lock Guard Guard class
class MutexGuard {
private:
    pthread_mutex_t* m_mutex;
public:
    // Constructor locks the mutex automatically
    MutexGuard(pthread_mutex_t* mutex) : m_mutex(mutex) {
        pthread_mutex_lock(m_mutex);
    }
    // Destructor unlocks the mutex automatically!
    ~MutexGuard() {
        pthread_mutex_unlock(m_mutex);
    }
};

void* safe_increment(void* arg) {
    for (int i = 0; i < 100000; ++i) {
        // 2. Create the guard object
        MutexGuard guard(&my_mutex); 
        
        // CRITICAL SECTION
        global_counter++;
        
        // If you write 'return NULL;' or if code breaks here, 
        // the 'guard' object is destroyed, and its destructor UNLOCKS the mutex!
    }
    return NULL;
}