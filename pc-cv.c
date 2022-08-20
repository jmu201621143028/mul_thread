#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;

int n = 1; int count = 0;

void TProduce()
{
    while (1)
    {
        pthread_mutex_lock(&mutex1);
        if(n == count)
        {
            // pthread_mutex_unlock(&mutex1);
            pthread_cond_wait(&condition_cond, &mutex1);
        }
        count++;
        printf("(");
        pthread_cond_signal(&condition_cond);
        pthread_mutex_unlock(&mutex1);
    }
}

void TConsume()
{
    while (1)
    {
        pthread_mutex_lock(&mutex1);
        if(0 == count)
        {
            //pthread_mutex_unlock(&mutex1);
            pthread_cond_wait(&condition_cond, &mutex1);
        }
        count--;
        printf(")");
        pthread_cond_signal(&condition_cond);
        pthread_mutex_unlock(&mutex1);
    }
}

int main(int args, char * argv[])
{
    if(args == 2){
        n = atoi(argv[1]);
    }
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1, iret2;
    iret1 = pthread_create(&thread1, NULL, (void *)TProduce, (void *)message1);
    iret2 = pthread_create(&thread2, NULL, (void *)TConsume, (void *)message2);
    while (1); // 
    
    return 0;
}