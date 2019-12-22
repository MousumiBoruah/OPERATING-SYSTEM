#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
        pid_t pid;
        int stat = 0;
        char *argv[] = {"./program_1",  NULL};
        pid = fork();
        if(pid == 0) {
                execv(argv[0], argv);
                exit(0);
        }
        else {
                wait(&stat);
                printf("Exit code %d\n", WEXITSTATUS(stat));
        }

}