#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


int sum; // 这个数据在多个线程间共享
void *runner(void *parma); // 多线程调用这个函数

int main(int argc, char *argv[]) {
    pthread_t tid; // 线程标识符
    pthread_attr_t attr; // 线程的属性

    if (argc != 2) {
        fprintf(stderr, "usage: a.out <integer value>\n");
        return -1;
    }
    if (atoi(argv[1]) < 0) {
        fprintf(stderr, "%d must be >=0\n", atoi(argv[1]));
        return -1;
    }

    // 初始化属性
    pthread_attr_init(&attr);

    // 创建线程
    pthread_create(&tid, &attr, runner, argv[1]);

    // 等待线程结束
    pthread_join(tid, NULL);

    printf("sum=%d\n", sum);
}

void *runner(void *param) {
    int i, upper = atoi(param);
    sum = 0;

    for (i = 1; i <= upper; i++)
        sum += i;
    pthread_exit(0);
}