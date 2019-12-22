#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/time.h>

int main(){

	mknod("FIFO_FILE", S_IFIFO | 0777 , 0);
	int fd,temp,t;
	pid_t PID;
	char buffer[25];
	memset(buffer,0x0,sizeof(buffer));
	printf("The Server is waiting for the Client\n");

	fd = open("FIFO_FILE",O_RDONLY);
	if (fd < 0)
	{
		perror("ERROR\n");		
	}
	read(fd,buffer,1);
	close(fd);
	printf("The Query from the client is No.: %s\n", buffer);
	temp = atoi(buffer);
	if(temp == 1){
		PID = getpid();
		printf("%d\n",PID );
		sprintf(buffer,"%d",PID);
		printf("%s\n",buffer);
		fd = open("FIFO_FILE",O_WRONLY);
		write(fd,buffer,strlen(buffer)+1);
		close(fd);
	}	
	else if(temp == 2){
		fd = open("FIFO_FILE",O_WRONLY);
		struct timeval start_time,end_time;
		gettimeofday(&start_time,NULL);
		printf("The start time is %ld\n",start_time.tv_sec);
		sprintf(buffer,"%ld",start_time.tv_sec);
		write(fd,buffer,strlen(buffer)+1);
		close(fd);
	}
	
	
}