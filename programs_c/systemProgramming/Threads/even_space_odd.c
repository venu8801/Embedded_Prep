/* create 3 threads one thread should print even numbers 
 * one thread should print - even numbers
 * 2nd thread should print - odd numbers
 * 3rd thread should print - space 
 *
 * synchronize threads so that threads should print even, space, odd, space, even, odd */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int space = 0;
int glob = 0;
pthread_mutex_t mutex;

pthread_cond_t cond_even, cond_odd, cond_space;

void *thread_even(void *args)
{
	while(glob <= 10)
	{
		pthread_mutex_lock(&mutex);
		if(space != 0)
			pthread_cond_wait(&cond_odd, &mutex);
		printf("even : %d\n",glob);
		glob++;
		space = 1; //print space
		pthread_cond_signal(&cond_space); //signal thread waiting on space cond var
		pthread_mutex_unlock(&mutex);

	}
	pthread_exit(NULL);

}
void *thread_space(void *args){
	while(glob <= 10){
		pthread_mutex_lock(&mutex);
		if(space != 1)
			pthread_cond_wait(&cond_space, &mutex);
		printf("[space]\n");
		if(glob % 2 == 0)
		{

			space = 0;
			pthread_cond_signal(&cond_odd);  //signal even thread
		}
		else
		{
			space = 2;
			pthread_cond_signal(&cond_even);
		}
		pthread_mutex_lock(&mutex);
	}
	pthread_exit(NULL);

}

void *thread_odd(void *args)
{
	while(glob <= 10)
	{
		pthread_mutex_lock(&mutex);
		if(space != 2)
			pthread_cond_wait(&cond_even, &mutex);
		printf("odd : %d\n",glob);
		glob++;
		space = 1; //print space
		pthread_cond_signal(&cond_space); //signal thread waiting on space cond var
		pthread_mutex_unlock(&mutex);

	}


}


int main()
{
	pthread_t t1, t2, t3;
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond_space,NULL);
	pthread_cond_init(&cond_even,NULL);
	pthread_cond_init(&cond_odd,NULL);

	 pthread_create(&t1, NULL, thread_even, NULL);
    pthread_create(&t2, NULL, thread_odd, NULL);
    pthread_create(&t3, NULL, thread_space, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_even);
    pthread_cond_destroy(&cond_odd);
    pthread_cond_destroy(&cond_space);



}
