#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main() {
	int main_id = getpid(), pid;
	char input[256];

	printf("Faraday Shell v0.0002 [No copyright] (use ^C to exit)\n");
	
	while (1) {
		gets(input);
		fork();
		pid = getpid();
		if (pid != main_id) {
			system(input);
			kill(pid, SIGTERM);
		}
	}

	return 0;
}
