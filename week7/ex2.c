#include <stdio.h>
#include <stdlib.h>

int main() {
	int N = 0;

	printf("Enter N: ");
	scanf("%d", &N);

	int *arr = (int*)malloc(N * sizeof(int));
	printf("Arr:\n");
	for (int i = 0; i < N; i++) {
		*(arr + i) = i;
		printf("[%d] = %d\n", i, *(arr + i));
	}
	free(arr);

	return 0;
}
