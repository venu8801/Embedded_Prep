#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int fuelFilled = 0;
pthread_mutex_t mutexFuel = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condFuel = PTHREAD_COND_INITIALIZER;

void *thread_fillFuel(void *args){

	int i;
	printf("--------fillFuel thread-----\n");
	pthread_mutex_lock(&mutexFuel);
	while(i != 5)
	{
		printf("filling fuel: %d\n",fuelFilled);
		sleep(1);
		i++;
		fuelFilled += 10;
	}
	printf("signalling startCar\n");
	pthread_cond_signal(&condFuel);
	pthread_mutex_unlock(&mutexFuel);

}

void *thread_startCar(void *args){
		
	//start car to start car first fuel needs to fill
	pthread_mutex_lock(&mutexFuel);
	printf("--------startCar thread-----\n");
	if(fuelFilled == 0)
	{
		//wait until fuel is filled		
		printf("waiting for fuel: %d\n",fuelFilled);
		pthread_cond_wait(&condFuel,&mutexFuel);
	}	
	
	printf("fuel filled: %d\n",fuelFilled);
	printf("starting car\n");

	pthread_mutex_unlock(&mutexFuel);

}


int main()
{
	pthread_t t1, t2;

	pthread_create(&t1, NULL, thread_startCar,NULL);
	pthread_create(&t2, NULL, thread_fillFuel, NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);


	return 0;
}

