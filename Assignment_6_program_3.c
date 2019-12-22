#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/time.h>

int main(){

	struct timeval start_time,end_time;
	gettimeofday(&start_time,NULL);
	pid_t pid;
	pid = fork();
	if(pid == 0){
		sleep(5);
		exit(0);
	}
	wait(NULL);
	gettimeofday(&end_time,NULL);
	printf("The start time is %ld\n",start_time.tv_sec);
	printf("The End time is %ld\n",end_time.tv_sec);
}