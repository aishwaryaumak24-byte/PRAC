#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

sem_t mutex;
sem_t wrt;

int readCount = 0;

void* reader(void* arg)
{
    int id = *(int*)arg;

    sem_wait(&mutex);
    readCount++;

    if(readCount == 1)
        sem_wait(&wrt);

    sem_post(&mutex);

    cout << "Reader " << id << " is reading\n";
    sleep(1);

    sem_wait(&mutex);
    readCount--;

    if(readCount == 0)
        sem_post(&wrt);

    sem_post(&mutex);

    return NULL;
}

void* writer(void* arg)
{
    int id = *(int*)arg;

    sem_wait(&wrt);

    cout << "Writer " << id << " is writing\n";
    sleep(1);

    sem_post(&wrt);

    return NULL;
}

int main()
{
    pthread_t r[3], w[2];

    int id[5]={1,2,3,1,2};

    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);

    for(int i=0;i<3;i++)
        pthread_create(&r[i],NULL,reader,&id[i]);

    for(int i=0;i<2;i++)
        pthread_create(&w[i],NULL,writer,&id[i+3]);

    for(int i=0;i<3;i++)
        pthread_join(r[i],NULL);

    for(int i=0;i<2;i++)
        pthread_join(w[i],NULL);

    return 0;
}