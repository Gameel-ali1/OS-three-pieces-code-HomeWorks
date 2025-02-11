#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(){
        printf("before the mess happens (%d)\n", (int) getpid());
        pid_t rc = fork();
        if (rc <0 ){
                fprintf(stderr, "error due fork faliure");
                exit(1);
        }
        else if (rc == 0){
                printf("child before exec with pid (%d)\n", (int) getpid());
                execlp("ls", "ls", "-la", NULL);
                printf("child after exec with pid (%d)\n", (int) getpid());
        }else{
                wait(NULL);
                printf("that is dad (%d) of one child with pid (%d)\n", (int) getpid(), rc);
        }
        return 0;
}
