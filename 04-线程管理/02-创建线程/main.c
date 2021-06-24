#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int shared_var = 0;

void *thread(void *arg) {
    while (1) {
        printf("in the thread shared_var:%d\n", --shared_var);
    }
}

int main() {
    pthread_t pt;
    int ret = pthread_create(&pt, NULL, (void *) thread, NULL);
    if (ret != 0) printf("fail to create thread\n");
    while (1) {
        printf("in the main shared_var:%d\n", ++shared_var);
    }
    pthread_join(pt, NULL);
    return 0;
}