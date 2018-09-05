#include <stdio.h>

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void quick_sort(int* a, int l, int r) {
	int mid = (l + r) / 2;
	int pivot = *(a + mid);
	int dl = l, dr = r;

	if (l < r) {
		while (dl <= dr) {
			while (*(a + dl) < pivot) { dl++; }
			while (*(a + dr) > pivot) { dr--; }
			if (dl <= dr) {
			       	swap(a + dl, a + dr);
				dl++;
				dr--;
		       	}
		}
		quick_sort(a, l, dr);
		quick_sort(a, dl, r);
	}
}

int main() {
	int a[10] = {8, 9, 0, 2, 3, 1, 6, 4, 5, 7};
	
	quick_sort(a, 0, 9);
	
	for (int i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
