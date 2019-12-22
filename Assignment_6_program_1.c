#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
	key_t key = ftok("file",69);
	if(key < 0)
		printf("1\n");
	int shm_id = shmget(key , 10 , 0666 | IPC_CREAT);
	if(shm_id < 0)
		printf("2\n");
	pid_t *pid = (pid_t *)shmat(shm_id , 0 ,0);
	if(*pid < 0)
		printf("3");
	*pid = getpid();
	printf("The Pid written in the shared memory is%d\n", *pid);
	shmdt(pid);
	pause();

	return 0;
}