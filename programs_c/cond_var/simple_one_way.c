/* usage of conditional variable in one way dependency 
 * only one thread have to wait for others threads signal and not vice versa */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

// Global variables
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condVar = PTHREAD_COND_INITIALIZER;
int workCompleted = -1;  //share resource 

void *thread_a(void *arg)
{
	//this thread prints numbers from 1 to 10 creating a 10 sec delay
	//acquire mutex 
	pthread_mutex_lock(&mtx);
	
	//-------start of some work -----------//
	int i = 0;
	while(i <= 10)
	{
		
		printf("i = %d\n", i);
		sleep(1);
		i++;

	}

	workCompleted = 0;
	//----------------end of some work--------//
	pthread_cond_signal(&condVar); //signal the thread that work is finished

	pthread_mutex_unlock(&mtx);

		

}


void *thread_b(void *arg)
{
	//thread b which should wait till thread A finishes some work
	pthread_mutex_lock(&mtx);

	//check whether work is completed or not wait till work is completed
	while(workCompleted == -1)
	{
		printf("work not completed waiting for thread_a to finish work\n");
		pthread_cond_wait(&condVar, &mtx);
	}
	printf("work from thread_a and thread_b done\n");


	pthread_mutex_unlock(&mtx);



}

int main() {
    pthread_t tidA, tidB;

    // Create threads
    pthread_create(&tidA, NULL, thread_a, NULL);
    pthread_create(&tidB, NULL, thread_b, NULL);

    // Wait for threads to finish
    pthread_join(tidA, NULL);
    pthread_join(tidB, NULL);

    return 0;
}
