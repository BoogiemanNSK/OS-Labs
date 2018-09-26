#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	char s1[32] = "Hello, world!";
	char s2[32] = "";

	printf("Step 1:\n");
	printf("s1 = \"%s\"\n", s1);
	printf("s2 = \"%s\"\n\n", s2);

	int pfd[2];
	pipe(pfd);

	write(pfd[1], s1, sizeof(s1)/sizeof(s1[0]));
	read(pfd[0], s2, sizeof(s1)/sizeof(s1[0]));

	printf("Step 2:\n");
	printf("s1 = \"%s\"\n", s1);
	printf("s2 = \"%s\"\n\n", s2);

	return 0;
}
