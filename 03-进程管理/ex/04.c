#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

//子进程创建之后，会调用execlp函数，进程自己的执行代码就会变成加载程序的代码，execlp()后边的代码也就不会执行了，所以printf("LINE J");不会被执行，除非exclp函数出错，printf才会被执行。
int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) {
        printf("LINE I\n");    //多加一行，最终输出，说明这一步确实执行了
        execlp("/bin/ls", "ls", NULL);
        printf("LINE J\n");   //这一行并没有执行，说明程序提前终止了
    } else {
        wait(NULL); // 等待子进程执行完成
        printf("Child complete");
    }
    return 0;
}
