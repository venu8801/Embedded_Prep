
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mtx, mtx2;
pthread_cond_t odd, even, space;

int global = 1;
int printed_space = 0;
int done = 0;
void *even_t(void *args)
{
	int i;
	for (i = 0; i <= 10; i++)
	{
		pthread_mutex_lock(&mtx);
		if (printed_space == 0)
		{
			// space not printed
			// wait
			pthread_cond_wait(&space, &mtx);
		}
		if (global % 2 != 0)
		{
			// odd case
			printf("waiting for signal from odd thread\n");
			pthread_cond_wait(&odd, &mtx); // wait for signal from odd thread
		}
		printf("even thread: %d\n", global);
		global++;
		printed_space = 0;
		pthread_cond_signal(&space);
		pthread_cond_signal(&even); // signal odd thread
		// pthread_cond_signal(&space);

		pthread_mutex_unlock(&mtx);
	}

	printf("done printing even\n");

	//	pthread_exit(NULL);
}

void *odd_t(void *args)
{
	int i;
	for (i = 0; i <= 10; i++)
	{
		pthread_mutex_lock(&mtx);
		if (printed_space == 0)
		{
			// space not printed
			// wait
			pthread_cond_wait(&space, &mtx);
		}
		if (global % 2 == 0)
		{
			// even case
			printf("waiting for signal from even thread\n");
			pthread_cond_wait(&even, &mtx);
		}

		printf("odd thread: %d\n", global);
		global++;
		printed_space = 0;
		pthread_cond_signal(&space);
		pthread_cond_signal(&odd); // signal even thread
								   // pthread_cond_signal(&space);
		pthread_mutex_unlock(&mtx);
	}

	printf("done printing odd\n");

	//	pthread_exit(NULL);
}

void *print_space(void *args)
{
	int i;
	for (i = 0; i < 10; i++)
	{

		pthread_mutex_lock(&mtx);

		if (printed_space != 0)
		{
			// space already printed
			pthread_cond_wait(&space, &mtx);
			
		}
	
			printf("[space]\n");
			printed_space = 1;
			pthread_mutex_unlock(&mtx);
			pthread_cond_signal(&odd);
			pthread_cond_signal(&even);
	
		//pthread_mutex_unlock(&mtx);
	}
}


	int main()
{

	pthread_t t1, t2, t3;

	pthread_mutex_init(&mtx, NULL);

	pthread_cond_init(&odd, NULL);
	pthread_cond_init(&even, NULL);

	pthread_cond_init(&space, NULL);

	pthread_create(&t1, NULL, odd_t, NULL);
	pthread_create(&t2, NULL, even_t, NULL);
	pthread_create(&t3, NULL, print_space, NULL);

	printf("thread 1 id: %ld\n", t1);
	printf("thread 2 id: %ld\n", t2);
	printf("thread 3 id: %ld\n", t3);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);

	pthread_mutex_destroy(&mtx);
	pthread_cond_destroy(&odd);
	pthread_cond_destroy(&even);
	pthread_cond_destroy(&space);
	return 0;
}
