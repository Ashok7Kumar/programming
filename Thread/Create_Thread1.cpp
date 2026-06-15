#include <stdio.h>
#include <pthread.h>

typedef struct
{
    int sensorId;
    float temperature;
} SensorData;

void* processSensor(void* arg)
{
    SensorData* data = (SensorData*)arg;

    printf("Sensor ID    : %d\n", data->sensorId);
    printf("Temperature  : %.2f\n", data->temperature);

    return NULL;
}

int main()
{
    pthread_t tid;

    SensorData sensor = {101, 36.5};

    pthread_create(
        &tid,
        NULL,
        processSensor,
        &sensor);

    pthread_join(tid, NULL);

    return 0;
}