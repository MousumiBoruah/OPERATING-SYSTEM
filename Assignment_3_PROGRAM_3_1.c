#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){

	mknod("FIFO_FILE", S_IFIFO | 0777 , 0);
	int fd;
	char buffer[25];
	memset(buffer,0x0,sizeof(buffer));
	printf("The read command is in blocking state\n");

	fd = open("FIFO_FILE",O_RDWR);
	if (fd < 0)
	{
		perror("ERRor\n");		
	}
	read(fd,buffer,25);
	// close(fd);
	printf("The string after reading from the named pipe is: %s\n", buffer);
	memset(buffer,0x0,sizeof(buffer));
	strcpy(buffer,"Thanks!!");
	// fd = open("FIFO_FILE",O_WRONLY);
	write(fd,buffer,strlen(buffer)+1);
	close(fd);
}