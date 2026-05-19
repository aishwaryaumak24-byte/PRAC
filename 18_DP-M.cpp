#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

pthread_mutex_t fork1[5];

void* philosopher(void* arg)
{
    int id = *(int*)arg;

    pthread_mutex_lock(&fork1[id]);
    pthread_mutex_lock(&fork1[(id+1)%5]);

    cout << "Philosopher " << id << " is eating\n";
    sleep(1);

    pthread_mutex_unlock(&fork1[id]);
    pthread_mutex_unlock(&fork1[(id+1)%5]);

    return NULL;
}

int main()
{
    pthread_t p[5];
    int id[5]={0,1,2,3,4};

    for(int i=0;i<5;i++)
        pthread_mutex_init(&fork1[i],NULL);

    for(int i=0;i<5;i++)
        pthread_create(&p[i],NULL,philosopher,&id[i]);

    for(int i=0;i<5;i++)
        pthread_join(p[i],NULL);

    return 0;
}