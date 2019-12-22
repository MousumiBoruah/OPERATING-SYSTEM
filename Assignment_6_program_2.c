#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int main(){
	int key =ftok("file",69);
	int shm_id = shmget(key,10,0);
	pid_t *pid = (pid_t *)shmat(shm_id , 0 , 0);
	printf("The read data from shared memory is %d\n",*pid);
	shmdt(pid);
	pause();
}