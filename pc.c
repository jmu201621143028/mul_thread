#include <stdio.h>
#include <pthread.h>

void TProduce()
{
    while (1)
    {
        printf("(");
    }
}

void TConsume()
{
    while (1)
    {
        printf(")");
    }
}

int main()
{
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1, iret2;
    iret1 = pthread_create(&thread1, NULL, (void *)TProduce, (void *)message1);
    iret2 = pthread_create(&thread2, NULL, (void *)TConsume, (void *)message2);
    while (1); // 
    
    return 0;
}