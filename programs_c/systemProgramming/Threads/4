#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mtx;
pthread_cond_t odd, even, space;

int global = 0, global_space =  0;
int printedSpace = 0;
void *even_t(void *args) {
	int i;
	for (i = 0; i < 10; i++) {
		pthread_mutex_lock(&mtx);

		if(global % 2 != 0) {
			//odd number
			pthread_cond_wait(&space, &mtx);
			pthread_cond_wait(&even, &mtx); // Wait for signal from the odd thread
		}
		printf("Even thread: %d\n", global);
		global++;
		pthread_mutex_unlock(&mtx);
		pthread_cond_signal(&space);
		pthread_cond_signal(&odd); // Signal the odd thread to proceed

	}
	pthread_exit(NULL);
}

void *odd_t(void *args) {
	int i;
	for (i = 0; i < 10; i++) {
		pthread_mutex_lock(&mtx);
		pthread_cond_wait(&space, &mtx);
		if(global % 2 == 0) {
			//even number so wait on odd cond var
			pthread_cond_wait(&space, &mtx);
			pthread_cond_wait(&odd, &mtx); // Wait for signal from the even thread
		}
		printf("Odd thread: %d\n", global);
		global++;
		pthread_mutex_unlock(&mtx);
		pthread_cond_signal(&space);
		pthread_cond_signal(&even); // Signal the even thread to proceed

	}
	pthread_exit(NULL);
}


void *print_space(void *args){
	while(global_space < 20){
		
		pthread_mutex_lock(&mtx);
		pthread_cond_wait(&space, &mtx);
		printf("[space]\n");
		global_space++;
		pthread_mutex_unlock(&mtx);
		pthread_cond_signal(&space);
		pthread_cond_signal(&space);
					
		}
		

}


int main() {
	pthread_t t1, t2, t3;

	pthread_mutex_init(&mtx, NULL);
	pthread_cond_init(&odd, NULL);
	pthread_cond_init(&even, NULL);
	pthread_cond_init(&space, NULL);

	pthread_create(&t1, NULL, odd_t, NULL);
	pthread_create(&t2, NULL, even_t, NULL);
	pthread_create(&t3, NULL, print_space, NULL);

	printf("Thread 2 ID: %ld\n", t1);
	printf("Thread 3 ID: %ld\n", t2);
	printf("Thread 4 ID: %ld\n", t3);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3,NULL);

	pthread_mutex_destroy(&mtx);
	pthread_cond_destroy(&odd);
	pthread_cond_destroy(&even);

	return 0;
}


