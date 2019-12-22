#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<signal.h>
void handler_function(int sig){

  int pipe_fd[2] , buffer;
  char read_buffer[10] , write_buffer[10];
  if(pipe(pipe_fd) == -1){
        perror("PIPE ERROR!!");
        exit(0);
  }
  pid_t PID;
  PID = fork();

  if(PID == 0){
        printf("INSIDE THE CHILD PROCESS\n");
        int n,t1 = 0,t2 = 1, i , tn;
        printf("Enter the number\n");
        scanf("%d",&n);
        int process_ID = getpid();
        write(pipe_fd[1],&process_ID,sizeof(int));
        write(pipe_fd[1],&sig,sizeof(int));
        //exit(0);
        for(i = 1;i <= n;i++){
                write(pipe_fd[1],&t1,sizeof(int));
                tn = t1 + t2;
                t1 = t2;
                t2 = tn;
        }
        close(pipe_fd[1]);
        exit(0);
  }
   else{
        printf("The process ID of the child is");
        read(pipe_fd[0],&buffer,sizeof(int));
        printf("=%d\nThe signal ID of the handler is",buffer);
        read(pipe_fd[0],&buffer,sizeof(int));
        printf("=%d\nThe fibonacci series terms are\n",buffer);
        while(read(pipe_fd[0],&buffer,sizeof(int)) > 0){
                printf(" %d\n",buffer);
        }
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        exit(0);
  }
return;
}


int main(){

   printf("please Enter CNTRL+C\n");
   signal(SIGINT,handler_function);
   while(1);
   return 0;

  }