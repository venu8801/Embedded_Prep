#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void * print_even(void *arg);
void * print_odd(void *arg);
int count = 0; //global shared resource 
pthread_mutex_t mutexCount;
pthread_cond_t odd_cond, even_cond;
int main()
{
	pthread_t threadArr[2];
	//init mutex and convar
	pthread_mutex_init(&mutexCount, NULL);
	pthread_cond_init(&odd_cond, NULL);
	pthread_cond_init(&even_cond, NULL);

	pthread_create(&threadArr[0], NULL, print_even, NULL);
	pthread_create(&threadArr[1], NULL, print_odd, NULL);
	

	pthread_join(threadArr[0], NULL);
	pthread_join(threadArr[1], NULL);

	pthread_mutex_destroy(&mutexCount);
	pthread_cond_destroy(&odd_cond);
	return 0;
}
/*
void * print_even(void *arg)
{
	
	while(count < 100){
	
		if(count % 2 == 0)
		{
			pthread_mutex_lock(&mutexCount);
			
			printf("even: %d\n",count);
			count++;
			pthread_cond_signal(&even_cond);
			pthread_mutex_unlock(&mutexCount);
		}
		else{
			printf("waiting on cond var\n");
			pthread_cond_wait(&odd_cond, &mutexCount); // waits for signal from oddthread
		}

	}
}
void * print_odd(void *arg)
{       

        while(count < 100){

                if(count % 2 != 0)
		{
        		pthread_mutex_lock(&mutexCount);
                        
			printf("odd: %d\n",count);
       			count++;
			pthread_cond_signal(&odd_cond); //signals threads waiting on odd_cond
        		pthread_mutex_unlock(&mutexCount);
		}
                else{
                        printf("waiting on cond var\n");
                        pthread_cond_wait(&even_cond, &mutexCount); //waits for signal from even thread
                }

        }
}       

*/


void *print_even(void *arg) {
	int i;
	for(i = 0; i < 100; i++){
//    while (count <= 100) {
        pthread_mutex_lock(&mutexCount);

        if (count % 2 == 0) {
            printf("even: %d\n", count);
            count++;
            pthread_cond_signal(&even_cond); // signal odd thread
        } else {
            printf("waiting on cond var\n");
            pthread_cond_wait(&odd_cond, &mutexCount); // wait for signal from odd thread
        }

        pthread_mutex_unlock(&mutexCount);
    }
   // pthread_exit(NULL);
}

void *print_odd(void *arg) {
	int i;
	for(i = 0; i < 100; i++){
    //while (count <= 100) {
        pthread_mutex_lock(&mutexCount);

        if (count % 2 != 0) {
            printf("odd: %d\n", count);
            count++;
            pthread_cond_signal(&odd_cond); // signal even thread
        } else {
            printf("waiting on cond var\n");
            pthread_cond_wait(&even_cond, &mutexCount); // wait for signal from even thread
        }

        pthread_mutex_unlock(&mutexCount);
    }
    //pthread_exit(NULL);
}


/* explanation -----
 * Certainly! The provided code involves two threads (`print_even` and `print_odd`) that are responsible for printing even and odd numbers, respectively. These threads use condition variables and a mutex for synchronization. The goal is to ensure that the even thread prints even numbers, and the odd thread prints odd numbers alternatively, up to a count of 100.

Let's break down the code:

```c
#include <pthread.h>
#include <stdio.h>

int count = 0;  // shared variable
pthread_mutex_t mutexCount = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t even_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t odd_cond = PTHREAD_COND_INITIALIZER;

void *print_even(void *arg) {
    while (count < 100) {
        pthread_mutex_lock(&mutexCount);

        if (count % 2 == 0) {
            printf("even: %d\n", count);
            count++;
            pthread_cond_signal(&odd_cond); // signal odd thread
        } else {
            printf("waiting on cond var\n");
            pthread_cond_wait(&even_cond, &mutexCount); // wait for signal from odd thread
        }

        pthread_mutex_unlock(&mutexCount);
    }
    pthread_exit(NULL);
}

void *print_odd(void *arg) {
    while (count < 100) {
        pthread_mutex_lock(&mutexCount);

        if (count % 2 != 0) {
            printf("odd: %d\n", count);
            count++;
            pthread_cond_signal(&even_cond); // signal even thread
        } else {
            printf("waiting on cond var\n");
            pthread_cond_wait(&odd_cond, &mutexCount); // wait for signal from even thread
        }

        pthread_mutex_unlock(&mutexCount);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t even_tid, odd_tid;

    // Create threads
    pthread_create(&even_tid, NULL, print_even, NULL);
    pthread_create(&odd_tid, NULL, print_odd, NULL);

    // Wait for threads to finish
    pthread_join(even_tid, NULL);
    pthread_join(odd_tid, NULL);

    return 0;
}
```

1. **Global Variables:**
   - `count`: Shared variable representing the current number to be printed.
   - `mutexCount`: Mutex to ensure mutual exclusion while accessing the shared variable.
   - `even_cond` and `odd_cond`: Condition variables used for signaling between the two threads.

2. **`print_even` Function:**
   - This function runs in the thread responsible for printing even numbers.
   - It enters a loop that continues until the count reaches 100.
   - It locks the mutex, checks if the current count is even, and prints the even number.
   - If the count is even, it increments the count, signals the odd thread using `pthread_cond_signal`, and unlocks the mutex.
   - If the count is not even, it prints a message and waits for a signal from the odd thread using `pthread_cond_wait`. While waiting, it releases the mutex to allow the odd thread to acquire it.

3. **`print_odd` Function:**
   - This function runs in the thread responsible for printing odd numbers.
   - It enters a loop similar to `print_even`.
   - It locks the mutex, checks if the current count is odd, and prints the odd number.
   - If the count is odd, it increments the count, signals the even thread using `pthread_cond_signal`, and unlocks the mutex.
   - If the count is not odd, it prints a message and waits for a signal from the even thread using `pthread_cond_wait`. While waiting, it releases the mutex to allow the even thread to acquire it.

4. **`main` Function:**
   - In the main function, two threads (`even_tid` and `odd_tid`) are created using `pthread_create`.
   - The main thread waits for both threads to finish using `pthread_join`.
   - The program then exits.

The key here is the use of condition variables to signal the other thread when it's their turn to execute. The mutex ensures that only one thread at a time can access and modify the shared variable (`count`). This coordination between threads ensures that even and odd numbers are printed in an alternating fashion up to a count of 100.



*///



