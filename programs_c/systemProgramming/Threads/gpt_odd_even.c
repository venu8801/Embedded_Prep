// #include <stdio.h>
// #include <pthread.h>

// pthread_mutex_t mtx;
// pthread_cond_t odd, even, space;

// int global = 0, global_space =  0;
// int printedSpace = 0;
// void *even_t(void *args) {
// 	int i;
// 	for (i = 0; i < 10; i++) {
// 		pthread_mutex_lock(&mtx);
// 		if(printedSpace == 0 )
// 		{
// 			//space not printed

// 			//printf("waiting for signal from space--even\n\n");
// 			pthread_cond_signal(&space);
// 			pthread_cond_wait(&space, &mtx);
// 		}

// 		if(global % 2 != 0) {
// 			//odd number
// 			pthread_cond_wait(&even, &mtx); // Wait for signal from the odd thread
// 		}
// 		printf("Even thread: %d\n", global);
// 		global++;
// 		printedSpace = 0; //reset
// 		pthread_cond_signal(&space);
// 		pthread_cond_signal(&odd); // Signal the odd thread to proceed
		
		
// 		pthread_mutex_unlock(&mtx);

// 	}
// 	pthread_exit(NULL);
// }

// void *odd_t(void *args) {
// 	int i;
// 	for (i = 0; i < 10; i++) {
// 		pthread_mutex_lock(&mtx);
// 		if(printedSpace != 0 )
// 		{

// 			//printf("waiting for signal from space-odd\n\n");
// 			pthread_cond_signal(&space);
// 			pthread_cond_wait(&space, &mtx);
// 		}
// 		if(global % 2 == 0) {
// 			//even number so wait on odd cond var
// 			pthread_cond_wait(&odd, &mtx); // Wait for signal from the even thread
// 		}

// 		printf("Odd thread: %d\n", global);
// 		global++;
// 		printedSpace = 0;  //reset it to 0
// 		pthread_cond_signal(&space);
// 		pthread_cond_signal(&even); // Signal the even thread to proceed
		
	
// 		pthread_mutex_unlock(&mtx);

// 	}
// 	pthread_exit(NULL);
// }


// void *print_space(void *args){
// 	while(global_space < 20){
		
// 		pthread_mutex_lock(&mtx);
		
// 		if(printedSpace == 1){
// 			//space already printed
// 			//printf("waiting for signal from odd/even\n");
// 			pthread_cond_signal(&even);
// 			pthread_cond_signal(&odd);

// 			pthread_cond_wait(&space, &mtx);
					
// 		}
// 		//space not printed
// 		printf("[space]\n");
// 		printedSpace = 1; //set to 1 after printing space
// 		global_space++;
// 		pthread_cond_signal(&even);
// 		pthread_cond_signal(&odd);
		
// 		pthread_mutex_unlock(&mtx);
// 	}

// }


// int main() {
// 	pthread_t t1, t2, t3;

// 	pthread_mutex_init(&mtx, NULL);
// 	pthread_cond_init(&odd, NULL);
// 	pthread_cond_init(&even, NULL);
// 	pthread_cond_init(&space, NULL);

// 	pthread_create(&t1, NULL, odd_t, NULL);
// 	pthread_create(&t2, NULL, even_t, NULL);
// 	pthread_create(&t3, NULL, print_space, NULL);

// 	printf("Thread 2 ID: %ld\n", t1);
// 	printf("Thread 3 ID: %ld\n", t2);
// 	printf("Thread 4 ID: %ld\n", t3);

// 	pthread_join(t1, NULL);
// 	pthread_join(t2, NULL);
// 	pthread_join(t3,NULL);

// 	pthread_mutex_destroy(&mtx);
// 	pthread_cond_destroy(&odd);
// 	pthread_cond_destroy(&even);

// 	return 0;
// }

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mtx;
pthread_cond_t cond_even, cond_odd, cond_space;

int global = 1;
int turn = 0; // 2: even, 1: space, 0: odd

void *print_even(void *arg) {
    while (global < 10) {
        pthread_mutex_lock(&mtx);
        if (turn != 2)
            pthread_cond_wait(&cond_odd, &mtx);

        printf("Even thread: %d\n", global);
        global++;
        turn = 1; // Switch turn to space
        pthread_cond_signal(&cond_space);
        pthread_mutex_unlock(&mtx);
    }
    pthread_exit(NULL);
}

void *print_odd(void *arg) {
    while (global < 10) {
        pthread_mutex_lock(&mtx);
        if (turn != 0)
            pthread_cond_wait(&cond_even, &mtx);

        printf("Odd thread: %d\n", global);
        global++;
        turn = 1; // Switch turn to space
        pthread_cond_signal(&cond_space);
        pthread_mutex_unlock(&mtx);
    }
    pthread_exit(NULL);
}

void *print_space(void *arg) {
    while (global < 10) {
        pthread_mutex_lock(&mtx);
        if (turn != 1)
            pthread_cond_wait(&cond_space, &mtx);
        printf("[Space]\n");
       // turn = (global % 2 == 0) ? 0 : 2; // Switch turn based on even/odd
        if (global % 2 == 0){
			turn = 2;
            pthread_cond_signal(&cond_odd);
		}
        else{
			turn = 0;
            pthread_cond_signal(&cond_even);
		}
        pthread_mutex_unlock(&mtx);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t t_even, t_odd, t_space;
	
    printf("sizeof: %ld\n",sizeof(mtx));
    pthread_mutex_init(&mtx, NULL);
    pthread_cond_init(&cond_even, NULL);
    pthread_cond_init(&cond_odd, NULL);
    pthread_cond_init(&cond_space, NULL);

    pthread_create(&t_even, NULL, print_even, NULL);
    pthread_create(&t_odd, NULL, print_odd, NULL);
    pthread_create(&t_space, NULL, print_space, NULL);

    pthread_join(t_even, NULL);
    pthread_join(t_odd, NULL);
    pthread_join(t_space, NULL);

    pthread_mutex_destroy(&mtx);
    pthread_cond_destroy(&cond_even);
    pthread_cond_destroy(&cond_odd);
    pthread_cond_destroy(&cond_space);

    return 0;
	}
