#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(){

  int PID_1,PID_2,count = 0,temp = 0,child_id = 0,grand_child_id = 0;
  FILE *file = fopen("input.txt","w+");
  PID_1 = fork();
  if(PID_1 < 0){
      printf("Error");
  }
  else if(PID_1 == 0){
    count++;
    printf("Inside the child process\n");
    PID_2 = fork();
    count++;
    if(PID_2 < 0){
        printf("Error");
    }
    else if(PID_2 == 0){
        printf("Inside Grandchild Process\n");
        printf("My Roll Number = CSB17024\n");
        fprintf(file,"%d %d %d",getpid(),getppid(),count);
        rewind(file);
    }

  }
  else{

        fscanf(file,"%d %d %d",&grand_child_id,&child_id,&temp);
        printf("number of child process created = %d\n",temp);
        printf("The PID of parent process = %d\n",getpid());
        printf("The PID of child process = %d\n",child_id);
        printf("The PID of the grandchild process = %d\n",grand_child_id);
        fclose(file);
  }

}
