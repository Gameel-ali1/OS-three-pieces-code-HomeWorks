#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
int main(){
	int fd = open("q2.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd == -1){
		fprintf(stderr, "erro due file opening\n");
		return 1;
	}
	pid_t rc = fork();
	if (rc < 0){
		fprintf(stderr, "error due forking\n");
		exit(1);
	}

	else if (rc ==0){
		printf("this is child with PID (%d) \n", (int) getpid());
		for (int i = 0; i<3; i++){
			write(fd, "child", 5);
		}
	}

	else {
		printf("this is parent with PID (%d) \n", (int) rc);
		for (int i = 0; i<3; i++){
			write(fd, "parent", 6);
		}
	}
	return 1;


 }
