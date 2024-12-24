#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int balance = 0;
pthread_mutex_t mutex;

void write_balance(int new_balance)
{
    usleep(10000);
    balance = new_balance;
}


int read_balance()
{
    usleep(10000);
    return balance;
}


void* deposit(void *amount)
{
    pthread_mutex_lock(&mutex);

    int account_balance = read_balance();
    account_balance +=  *((int *) amount);
    write_balance(account_balance);

    pthread_mutex_unlock(&mutex);
}
 

int main()
{
    pthread_t thread1;
    pthread_t thread2;


    pthread_mutex_init(&mutex, NULL);
    printf("Before: %d\n", read_balance());
    

    int deposit1 = 300;
    int deposit2 = 200;


    pthread_create(&thread1, NULL, deposit, (void*) &deposit1);
    pthread_create(&thread2, NULL, deposit, (void*) &deposit2);


    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);


    printf("After: %d\n", read_balance());
    pthread_mutex_destroy(&mutex);

  return 0;
}



