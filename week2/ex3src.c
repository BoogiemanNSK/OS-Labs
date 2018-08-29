#include <stdio.h>
#include <string.h>

int strtoint(char*);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: ./ex3 [height]\n");
		return 0;
	}

	int h = strtoint(argv[1]);
	
	for (int i = 0, w = 1; i < h; i++, w += 2) {
		for (int j = 0; j < (h - i - 1); j++) { printf(" "); }
		for (int j = 0; j < w; j++) 	      { printf("*"); }
		printf("\n");
	}

	return 0;
}

int strtoint(char* str) {
	int n = 0;
	int len = strlen(str);
	
	for (int i = 0, t = 1; i < len; i++, t *= 10) {
		n += ((int)*(str + len - i - 1) - 48) * t;
	}

	return n;
}
