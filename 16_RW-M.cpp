#include <iostream>
#include <pthread.h>
#include <unistd.h>
using namespace std;

pthread_mutex_t mutex1;
pthread_mutex_t wrt;

int readCount = 0;

void* reader(void* arg)
{
    int id = *(int*)arg;

    pthread_mutex_lock(&mutex1);
    readCount++;

    if(readCount == 1)
        pthread_mutex_lock(&wrt);

    pthread_mutex_unlock(&mutex1);

    cout << "Reader " << id << " is reading\n";
    sleep(1);

    pthread_mutex_lock(&mutex1);
    readCount--;

    if(readCount == 0)
        pthread_mutex_unlock(&wrt);

    pthread_mutex_unlock(&mutex1);

    return NULL;
}

void* writer(void* arg)
{
    int id = *(int*)arg;

    pthread_mutex_lock(&wrt);

    cout << "Writer " << id << " is writing\n";
    sleep(1);

    pthread_mutex_unlock(&wrt);

    return NULL;
}

int main()
{
    pthread_t r[3], w[2];

    int id[5] = {1,2,3,1,2};

    pthread_mutex_init(&mutex1,NULL);
    pthread_mutex_init(&wrt,NULL);

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