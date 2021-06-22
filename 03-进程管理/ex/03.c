#include<stdio.h>
#include <unistd.h>

int main() {
    printf("主进程：%d\n", getpid());
    int i;
    for (i = 0; i < 1; ++i) {
        fork();
        printf("%d\n", getpid());
    }
    return 0;
}
// 1: 2
// 2: 4
// 3: 8
// 4: 16