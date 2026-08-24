// IPC using pipe

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    int fd[2];
    pid_t pid;
    char message[]="Hello from Child Process";
    char buffer[100];

    pipe(fd);
    pid=fork();

    if(pid==0){
        // Child process
        close(fd[0]); // Close read end
        write(fd[1],message,strlen(message)+1);
        close(fd[1]); // Close write end}
        exit(0);
    }
    else{
        wait(NULL); // Wait for child process to finish
        close(fd[1]); // Close write end
        read(fd[0],buffer,sizeof(buffer));
        printf("Message received from child: %s\n",buffer);
        close(fd[0]); // Close read end
    }
    return 0;
}