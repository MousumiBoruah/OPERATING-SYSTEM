#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(){

	int fd,Option;
	char buffer[25],temp[10];
	memset(buffer,0x0,sizeof(buffer));
	printf("Please Select The Menu\n");
	printf("The Queries client can make are\n1-process ID of the Server\n2-System Time of the Server\n");
	printf("Please Enter the Option\n");
	scanf("%d",&Option);
	sprintf(temp,"%d",Option);
	fd = open("FIFO_FILE",O_WRONLY);
	write(fd,temp,strlen(temp)+1);
	close(fd);

	fd = open("FIFO_FILE",O_RDONLY);
	read(fd,buffer,25);

	printf("The received Answer from the pipe is:- %s\n",buffer);
	close(fd);
}