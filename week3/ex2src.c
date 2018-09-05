#include <stdio.h>

void bubble_sort(int* a, int len) {
	for (int i = 1; i < len; i++) {
		int j = i;
		while (*(a + j) < *(a + j - 1) && j > 0) {
			int t = *(a + j);
			*(a + j) = *(a + j - 1);
			*(a + j - 1) = t;
			j--;
		}
	}
}

int main() {
	int a[10] = {8, 9, 0, 2, 3, 1, 6, 4, 5, 7};
	
	bubble_sort(a, 10);
	
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
