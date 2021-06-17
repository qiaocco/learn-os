#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFSZ 512

int main(int argc, char *argv[]) {
    int shmid;
    int ret;
    key_t key;
    char *shmadd;

    //创建key值
    key = ftok("../", 2015);
    if (key == -1) {
        perror("ftok");
    }

    //创建共享内存
    shmid = shmget(key, BUFSZ, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(-1);
    }

    //将共享内存端挂载到自己地址空间
    // 第一次创建共享内存段时，它不能被任何进程访问。要想启动对该内存的访问，必须将其连接到一个进程的地址空间
    shmadd = shmat(shmid, NULL, 0);
    if (shmadd < 0) {
        perror("shmat");
        _exit(-1);
    }

    //拷贝数据至共享内存区
    printf("copy data to shared-memory\n");
    bzero(shmadd, BUFSZ); // 共享内存清空
    strcpy(shmadd, "how are you, lh\n");

    return 0;
}