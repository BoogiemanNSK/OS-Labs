#include <stdio.h>
#include <sys/types.h>

int main() {
	int n = getpid();
	fork();
	if (getpid() == n) printf("Hello from parent %d\n", getpid() - n);
	else printf("Hello from child %d\n", getpid() - n);
	return 0;
}
