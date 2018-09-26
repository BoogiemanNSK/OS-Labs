#include <stdio.h>
#include <signal.h>

int end = 0;

void sigint_handler(int signo) {
	if (signo != SIGINT) { return; }
	
	printf("\nWant to quit? Good luck with that :)\n(OK, just type anything)\n");
	char buffer[128];
	scanf("%s", buffer);
	
	end = 1;
}

int main() {
	struct sigaction sig;
	sig.sa_handler = sigint_handler;
	sigaction(SIGINT, &sig, NULL);

	while (!end) {}

	return 0;
}
