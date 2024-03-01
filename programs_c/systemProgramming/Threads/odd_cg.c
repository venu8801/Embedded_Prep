#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mtx;
pthread_cond_t odd, even, space;

int global = 0;
int printed_space = 0;

void *even_t(void *args) {
    int i;
    for (i = 0; i < 100; i++) {
        pthread_mutex_lock(&mtx);
        if (global % 2 == 0) {
            printf("even thread: %d\n", global);
            global++;
            printed_space = 0;
            pthread_cond_signal(&odd);  // Signal odd thread
            pthread_cond_signal(&space); // Signal space printing thread
        } else {
            pthread_cond_wait(&even, &mtx); // Wait for signal from odd thread
        }
        pthread_mutex_unlock(&mtx);
    }
}

void *odd_t(void *args) {
    int i;
    for (i = 0; i < 100; i++) {
        pthread_mutex_lock(&mtx);
        if (global % 2 != 0) {
            printf("odd thread: %d\n", global);
            global++;
            printed_space = 0;
            pthread_cond_signal(&even); // Signal even thread
            pthread_cond_signal(&space); // Signal space printing thread
        } else {
            pthread_cond_wait(&odd, &mtx); // Wait for signal from even thread
        }
        pthread_mutex_unlock(&mtx);
    }
}

void *print_space(void *args) {
    int i;
    for (i = 0; i < 100; i++) {
        pthread_mutex_lock(&mtx);
        if (printed_space == 0) {
            printf("[space]\n");
            printed_space = 1;
            pthread_cond_signal(&even); // Signal even thread
            pthread_cond_signal(&odd); // Signal odd thread
        } else {
            pthread_cond_wait(&space, &mtx); // Wait for signal to print space
        }
        pthread_mutex_unlock(&mtx);
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

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    pthread_mutex_destroy(&mtx);
    pthread_cond_destroy(&odd);
    pthread_cond_destroy(&even);
    pthread_cond_destroy(&space);

    return 0;
}

