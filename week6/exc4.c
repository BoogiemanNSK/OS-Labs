#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo) {
	switch (signo) {
		case SIGKILL:
			printf("SIGKILL handled.\n");
			break;
		case SIGSTOP:
			printf("SIGSTOP handled.\n");
			break;
		case SIGUSR1:
			printf("SIGUSR1 handled.\n");
			break;
	}	
}

int main() {
	struct sigaction sig;
	sig.sa_handler = sig_handler;
	sigaction(SIGKILL, &sig, NULL);
	sigaction(SIGSTOP, &sig, NULL);
	sigaction(SIGUSR1, &sig, NULL);

	for(;;) {}

	return 0;
}
