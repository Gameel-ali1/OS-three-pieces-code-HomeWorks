#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(){
	printf("before forking (%d)\n", (int) getpid());
	pid_t rc = fork();
	int i = 0;
	if (rc < 0){
		fprintf(stderr, "error due forking");
		exit(1);
	}
	else if (rc == 0 ){
		while(i<5000){
			printf("test");
			i++;
	}
	}
	else {
		sleep(15);
		printf("dad says goodbye (%d)\n", (int) getpid());

	}
	
	return 0;




}
