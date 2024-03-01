/* basic code to implement PosixThreads 
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


int global_num = 0;


void * thread1(void *args){
	int i;
	for(i = 0; i < 10000; i++)
	{

		printf("from thread 1\n");


	}


}


void * thread2(void *args){

	int i;
	for(i = 0; i < 10000; i++)
	{

		printf("from thread 2\n");


	}


}


int main()
{
	
	pthread_t t1, t2;
	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);

	printf("thread 1 id: %ld\n",t1);
	printf("thread 2 id: %ld\n",t2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	

	return 0;
}
