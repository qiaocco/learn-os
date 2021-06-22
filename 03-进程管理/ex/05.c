#include <stdio.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid, pid1;
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) {
        pid1 = getpid();   //子进程的pid
        printf("child:pid = %d", pid);   // A  0 进入子进程后，pid=0
        printf("child:pid1 = %d", pid1); // B  25247 子进程pid
    } else {
        pid1 = getpid();
        printf("parent:pid = %d", pid); // C 25247 子进程id
        printf("parent:pid1 = %d", pid1); // D 25246 父进程id
        wait(NULL);
    }
    return 0;
}
