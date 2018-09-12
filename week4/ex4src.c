#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Faraday Shell v0.0002 [No copyright] (use ^C to exit)\n");
	while (1) {
		printf(">");
		char input[256];
		gets(input);
		system(input);
	}
	return 0;
}
