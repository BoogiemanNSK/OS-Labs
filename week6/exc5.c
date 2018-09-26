#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {
	int cid = fork();
	if (cid == 0) {
		for (;;) {
			printf("Child: I'm alive.\n");
			sleep(1);
		}
	} else {
		sleep(10);
		kill(cid, SIGTERM);
		printf("Parent: I've killed child. Press Ctrl-C to exit.\n");
	}

	for(;;) {}

	return 0;
}
