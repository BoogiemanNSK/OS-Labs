#include <stdio.h>
#include <string.h>

int strtoint(char*);

void fig0(int);
void fig1(int);
void fig2(int);
void fig3(int);

int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("Usage: ./ex5 [height] [figure variant (0-3)]\n");
		return 0;
	}

	int h = strtoint(argv[1]);
	int var = strtoint(argv[2]);

	switch (var) {
		case 0:
			fig0(h);
			break;
		case 1:
			fig1(h);
			break;
		case 2:
			fig2(h);
			break;
		case 3:
			fig3(h);
			break;
		default:
			printf("Error: wrong non-existent figure variant\n");
			printf("Usage: ./ex5 [height] [figure variant (0-3)]\n");
			return 0;
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

void fig0(int h) {
	for (int i = 0, w = 1; i < h; i++, w += 2) {
		for (int j = 0; j < (h - i - 1); j++) { printf(" "); }
		for (int j = 0; j < w; j++) 	      { printf("*"); }
		printf("\n");
	}
}

void fig1(int h) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j <= i; j++) { printf("*"); }
		printf("\n");
	}
}

void fig2(int h) {
	for (int i = 0; i < h / 2; i++) {
		for (int j = 0; j <= i; j++) { printf("*"); }
		printf("\n");

	}
	for (int i = h / 2, w = (h + 1) / 2; i < h; i++, w--) {
		for (int j = 0; j < w; j++) { printf("*"); }
		printf("\n");
	}
}

void fig3(int h) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < h; j++) { printf("*"); }
		printf("\n");
	}
}
