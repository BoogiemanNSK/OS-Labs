#include <stdio.h>
#include <unistd.h>

#define SIZE 5

int main() {
	setvbuf(stdout, NULL, _IOLBF, 0);
	char s[SIZE] = "Hello";

	for (int i = 0; i < SIZE; i++) {
		printf("%c", s[i]);
		sleep(1);	
	}
	printf("\n");

	return 0;
}
