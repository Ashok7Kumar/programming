#include <iostream>
#include <pthread.h>

using namespace std;

void* hello(void* arg)
{
    cout << "Hello from thread!" << endl;
    return NULL;
}
/*
 int pthread_create(pthread_t* restrict thread,
                          const pthread_attr_t *_Nullable restrict attr,
                          typeof(void *(void *_Nullable))* start_routine,
                          void *_Nullable restrict arg); 
  If attr is NULL, then the thread is created with default attributes.                        
                          */

int main()
{
    pthread_t tid;

    // Create thread
    pthread_create(&tid, NULL, hello, NULL);

    // Wait for thread to complete
    pthread_join(tid, NULL);

    cout << "Thread finished." << endl;

    return 0;
}