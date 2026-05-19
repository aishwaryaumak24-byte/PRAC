#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

int buffer = 0;

pthread_mutex_t mutex;

void* producer(void* arg)
{
    for(int i=1;i<=5;i++)
    {
        pthread_mutex_lock(&mutex);

        buffer++;
        cout << "Produced: " << buffer << endl;

        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    return NULL;
}

void* consumer(void* arg)
{
    for(int i=1;i<=5;i++)
    {
        pthread_mutex_lock(&mutex);

        cout << "Consumed: " << buffer << endl;
        buffer--;

        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    return NULL;
}

int main()
{
    pthread_t p,c;

    pthread_mutex_init(&mutex,NULL);

    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);

    pthread_join(p,NULL);
    pthread_join(c,NULL);

    return 0;
}