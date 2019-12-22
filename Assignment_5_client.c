#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

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
    if((msg_id = msgget(key, 0666)) == -1){
        perror("MSGGET Error: ");
        exit(1);
    }
    message.msg_type = 1;
    printf("Enter a message: \n");
    scanf(" %s", message.msg_text);
    if(msgsnd(msg_id, &message, sizeof(message), 0) == -1){
        perror("MSGSND Error: ");
        exit(1);
    }
    printf("Data Sent\n");
    
    
}
