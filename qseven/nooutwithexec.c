#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child: redirect standard output to a file
 	close(STDOUT_FILENO);
    	execlp("ls", "ls", "-la", NULL);
    } else {
        // parent goes down this path (main)
	printf("here is dad");
    }
    return 0;
}
