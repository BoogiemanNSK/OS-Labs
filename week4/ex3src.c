#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Faraday Shell v0.0001 [No copyright] (use ^C to exit)\n");
	while (1) {
		printf(">");
		char input[256];
		scanf("%s", input);
		system(input);
	}
	return 0;
}
