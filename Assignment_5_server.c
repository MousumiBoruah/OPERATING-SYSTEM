#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
// Issues - 1. why 1 is not working in msg type in msgrcv. 2. How to delete the queue?
struct msg_buffer{
    char msg_text[50];
    long msg_type;
}message;

int main(){
    key_t key;
    int msg_id;

    if((key = ftok("keyfile", 65)) == -1){
        perror("FTOK Error: ");
        exit(1);
    }
    if((msg_id = msgget(key, 0666 | IPC_CREAT)) == -1){
        perror("MSGGET Error: ");
        exit(1);
    }
    
    while(1){
        printf("--Server is waiting for the Client--\n");
        if(msgrcv(msg_id, &message, sizeof(message), 0, 0) == -1){
            perror("MSGRCV Error: ");
            exit(1);
        }
        printf("Data Received: %s\n", message.msg_text);
        // msgctl(msg_id, IPC_RMID, NULL);
    }
}