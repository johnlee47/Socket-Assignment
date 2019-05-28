#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static int pipefd1[2],pipefd2[2];
void TELL_WAIT(void){
    if(pipe(pipefd1)<0 || pipe(pipefd2)<0){
        perror("pipe not created");
        exit(EXIT_FAILURE);
    }
}

void TELL_PARENT(void){
//waitting to complete
    printf("Child send message to parent: Wusha\n");
}

void WAIT_PARENT(void){
//waitting to complete
    printf("Child receive message from parent: Sikome achir sikemete rejeme\n");
}

void TELL_CHILD(void){
//waitting to complete
    printf("Parent send message to child: Enkokelesh\n");
}

void WAIT_CHILD(void){
//Waitting to complete
    printf("Parent receive message from child: Menawekeleh\n");
}

void TELL_BOTH(void){
    printf("Parent receive message from child!\n");
}

int main(int argc, char *argv[]){
    TELL_WAIT();
    pid_t pid;
    pid = fork();
    alarm(3);
    if(pid!=0){
        while(1){
            sleep(rand()%2+1);
            TELL_CHILD();
            WAIT_CHILD();
        }
    }else{
        while(1){
            sleep(rand()%2+1);
            WAIT_PARENT();
            TELL_PARENT();
        }
    }
    return 0;
}