#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *thread_function(){
    printf("hello world");
    return NULL;
}

int main(){
        pthread_t TID;
        pthread_create(&TID,NULL,thread_function,NULL);
        pthread_join(TID,NULL);
}