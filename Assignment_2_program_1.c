#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>

void signal_handle(int sig){
        pid_t PID;
        PID = fork();

        if(PID < 0){
                perror("ERROR!!");
                exit(0);
        }
        else if( PID == 0){
                printf("Child Process Id of the child process = %d\n",getpid());
                printf("Child Process Id of the parent process = %d\n",getppid());
                exit(0);
        }
        wait(NULL);
        printf("PARENT ID: %d\n", getpid());
        printf("PARENT -- CHILD ID: %d\n", PID);
        exit(1);
}

int main() {
        printf("--Signal--\n");
        printf("%d\n",getpid());
        signal(SIGINT, signal_handle);
        while(1);
        return 0;

}