#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
	int pfd[2];
	pipe(pfd);

	pid_t c1id = fork();
	if (c1id) {
		pid_t c2id = fork();
		if (c2id) {
			// Parent
			
			printf("Parent: Sending [%d] ID to [%d].\n", c2id, c1id);
			write(pfd[1], &c2id, 4);
			waitpid(c2id, NULL, WUNTRACED);

			printf("Parent: Child [%d] stopped.\n", c2id);
		} else {
			// Child 2
			
			printf("Child 2: My ID is %d.\n", getpid());
			for (;;) {}
		}
	} else {
		// Child 1
		
		pid_t c2id;
		read(pfd[0], &c2id, 4);
		printf("Child 1: Received [%d] from Parent.\n", c2id);
		
		sleep(2);
		
		printf("Child 1: Sending SIGSTOP to [%d].\n", c2id);
		kill(c2id, SIGSTOP);
		exit(0);
	}

	return 0;
}
