#include <stdio.h>
#include <stdlib.h>

void* faraday_realloc(void *ptr, size_t size) {
	if (ptr == NULL) {
		return malloc(size);
	} else if (size == 0) {
		free(ptr);
		return NULL;
	} else {
		void *new = malloc(size);
		for (int i = 0; i < size; i++) {
			*((char*)new + i) = *((char*)ptr + i);
		}
		free(ptr);
		return new;
	}
}

int main() {
	return 0;
}
