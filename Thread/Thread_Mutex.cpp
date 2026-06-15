#include <iostream>
#include <pthread.h>

using namespace std;

int counter = 0;
pthread_mutex_t mutex; // mutex variable

void* increment(void* arg)
{
    for(int i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&mutex);
       //entering  critical section
        counter++;
        
       ///exitcritical section
       pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_mutex_init(&mutex, NULL); // create a mutex(lock)
   /*  pthread_mutex_init() initializes the mutex object pointed to by
       mutex according to the mutex attributes specified in mutexattr.
       If mutexattr is NULL, default attributes are used instead. */
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    cout << "Counter = "
         << counter
         << endl;

    pthread_mutex_destroy(&mutex);

    return 0;
}