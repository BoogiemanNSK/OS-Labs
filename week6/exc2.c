#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define SIZE(s) (sizeof(s)/sizeof(s[0]))

int main() {
	char s[32] = "Hello, world!";
	int pfd[2];
	pipe(pfd);
	pid_t cid = fork();

	if (cid == 0) {
		int i = 0;
		char cs[32] = "";
		
		close(pfd[1]);
		while (read(pfd[0], cs+(i++), 1) > 0) {
			continue;
		}
		close(pfd[0]);

		printf("Child reads: %s\n", cs);
	} else {
		printf("Initial string: %s\n", s);
		
		close(pfd[0]);
		write(pfd[1], s, SIZE(s));
		close(pfd[1]);

		wait(&cid);
	}


	return 0;
}
