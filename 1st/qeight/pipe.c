#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
int main(){
	int fd[2];
	// fd[0] is the read end
	// fd[1] is the write end 
	char* msg1 = "child 1 message\n";
	char inbuf[strlen(msg1)+1]; //+1 for the null terminator
	pipe(fd);
	int rc1 = fork();
	if (rc1 < 0){
		fprintf(stderr, "error due forking first child");
		exit(1);
	}
	else if (rc1 == 0){
		close(fd[0]);
		write(fd[1], msg1, strlen(msg1));
		close(fd[1]);
		exit(0);
	}
	
	waitpid(rc1, NULL, 0); // to make sure rc2 doesn't read till 1 finishes writing
	pid_t rc2 = fork();
	if (rc2 < 0){
		fprintf(stderr, "error due forking second child");
		exit(1);
	}
	else if (rc2 == 0){
		close(fd[1]);
		read(fd[0], inbuf, sizeof(inbuf)-1);
		printf("got this from child 1: %s", inbuf);
		close(fd[0]);
		printf("after piping\n");
	}

	close(fd[0]);
	close(fd[1]);
	waitpid(rc2, NULL, 0);
	return 0;	
}

