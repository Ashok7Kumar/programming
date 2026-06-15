#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void* task(void* arg)
{
    int id = *(int*)arg;

    for(int i = 0; i < 5; i++)
    {
        cout << "Thread " << id << " running" << endl;

        sleep(1);
    }

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    int id1 = 1;
    int id2 = 2;

    pthread_create(&t1, NULL, task, &id1);
    pthread_create(&t2, NULL, task, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}