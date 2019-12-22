#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
int main(int argc,char const* argv[]){
        kill(74708,SIGINT);
        return 0;
}