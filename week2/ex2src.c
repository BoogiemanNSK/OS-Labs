#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char buffer[256];

	printf("Enter string to reverse:\n");

	gets(buffer);
	int len = strlen(buffer);

	for (int i = 0; i < len; i++) {
		printf("%c", buffer[len - i - 1]);
	}
	printf("\n");

	return 0;
}
