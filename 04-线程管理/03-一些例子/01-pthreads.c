#include <pthread.h>
#include <stdio.h>

void *PrintHello(void *id) {
    printf("Thread-%d: hello qiaocc\n", id);
}

void main() {
    printf("hello %d\n", 1);
    pthread_t thread0, thread1;
    pthread_create(&thread0, NULL, PrintHello, (void *) 0);
    pthread_create(&thread1, NULL, PrintHello, (void *) 1);
}