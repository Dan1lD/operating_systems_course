#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUMBER_OF_THREADS 5
pthread_t thread_id[NUMBER_OF_THREADS];

void *ThreadFunction(void* arg) {
    printf("Text from thread %d\n", *(int*)arg);
    sleep(1);
    printf("exit from thread %d\n",*(int*)arg);
    free(arg);
    pthread_exit(NULL);
}

int main() {
    for (int i = 1; i <= NUMBER_OF_THREADS; i++) {
        if(i>1){
            int rj = pthread_join(thread_id[i-2],NULL);
            if(rj){
                printf("Error during waiting the thread to finish. Error: %d\n",rj);
                exit(1);
            }
        }
        int* i_stored = malloc(sizeof(int));
        *i_stored = i;
        int rc = pthread_create(&thread_id[i - 1], NULL, ThreadFunction, i_stored);
        if (rc) {
            printf("Error creating thread %d\n", i);
            exit(1);
        }
        printf("Thread %d is created\n",i);
    }
    pthread_exit(NULL);
}