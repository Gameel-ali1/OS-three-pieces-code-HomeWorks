#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int x = 100; // before forking
	printf("x before forking is %d\n", x);
	pid_t rc = fork(); // here i forked
	if (rc <0){
		fprintf(stderr, "error forking\n");
		exit(1);
	}
	else if (rc == 0){ //child cause rc is zero
		printf("this is child with PID (%d)\n", (int) getpid());
		printf("this is x after forking but before change %d\n",x);
		x = 200;
		printf("x from child is %d\n", x);
	
	}
	else{ // parent because rc no zero or negative
	        x = 300;
		printf("this is dad with PID (%d)\n", (int) getpid());
		printf("x from dad is %d\n",x );
	}
	return 0;
}

