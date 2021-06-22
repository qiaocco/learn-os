
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

#define SIZE 5
int nums[SIZE] = {0, 1, 2, 3, 4};
// 系统调用子进程对数组的影响，并没有作用到父进程上，这是因为由于子进程是父进程的副本，任何发生在子进程中的改变将出现在它自己的数据拷贝上，并不会影响父进程。
int main() {
    int i;
    pid_t pid;
    pid = fork();

    if(pid == 0) {
        for(i = 0; i < SIZE; ++i) {
            nums[i] *= -i;
            printf("CHILD:%d ", nums[i]); /* LINE X */
        }
    }
    else if(pid > 0) {
        wait(NULL);
        for(i = 0; i < SIZE; ++i) {
            printf("PARENT:%d ", nums[i]); /* LINE Y */
        }
    }
    return 0;
}
