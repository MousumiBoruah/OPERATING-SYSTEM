#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(int argc,char *argv[]){

	int fd;
	char buffer[25];
	memset(buffer,0x0,sizeof(buffer));
	fd = open("FIFO_FILE",O_RDWR);
	write(fd,argv[1],strlen(argv[1])+1);
	// close(fd);
	// fd = open("FIFO_FILE",O_RDONLY);
	read(fd,buffer,25);
	printf("The received Ack from the pipe is:- %s\n",buffer);
	close(fd);
}