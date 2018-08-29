#include <stdio.h>
#include <string.h>

int strtoint(char*);
void swap(int*, int*);

int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("Usage: ./ex4 [num1] [num2]\n");
		return 0;
	}

	int a = strtoint(argv[1]);
	int b = strtoint(argv[2]);
	
	swap(&a, &b);

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

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
