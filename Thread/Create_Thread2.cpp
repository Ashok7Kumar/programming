#include <iostream>
#include <pthread.h>

using namespace std;

struct SensorData
{
    int sensorId;
    float temperature;
};

void* processSensor(void* arg)
{
    SensorData* data = static_cast<SensorData*>(arg);

    cout << "Sensor ID   : " << data->sensorId << endl;

    cout << "Temperature : " << data->temperature << " C"<< endl;

    
    float* fahrenheit = new float;

    *fahrenheit = (data->temperature * 9.0f / 5.0f) + 32.0f;

    return fahrenheit;
}

int main()
{
    pthread_t tid;

    SensorData sensor;

    sensor.sensorId = 101;
    sensor.temperature = 36.5f;

    void* retVal;

    pthread_create(&tid,NULL,processSensor,&sensor);

    pthread_join(tid, &retVal);

    float* result = static_cast<float*>(retVal);

    cout << "Temperature in Fahrenheit : "<< *result<< " F" << endl;

    delete result;

    return 0;
}