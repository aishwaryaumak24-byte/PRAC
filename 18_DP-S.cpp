#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t fork1[5];

void* philosopher(void* arg)
{
    int id = *(int*)arg;

    sem_wait(&fork1[id]);
    sem_wait(&fork1[(id+1)%5]);

    cout << "Philosopher " << id << " is eating\n";
    sleep(1);

    sem_post(&fork1[id]);
    sem_post(&fork1[(id+1)%5]);

    return NULL;
}

int main()
{
    pthread_t p[5];
    int id[5]={0,1,2,3,4};

    for(int i=0;i<5;i++)
        sem_init(&fork1[i],0,1);

    for(int i=0;i<5;i++)
        pthread_create(&p[i],NULL,philosopher,&id[i]);

    for(int i=0;i<5;i++)
        pthread_join(p[i],NULL);

    return 0;
}