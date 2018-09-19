#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREADS_NUM 10

pthread_t thread_id[THREADS_NUM];

void* print_hello(int i) {
	printf("Hello from thread %d on iteration %d!\n", thread_id[i], i);
	pthread_exit(NULL);
}

int main() {
	for (int i = 0; i < THREADS_NUM; i++) {
		pthread_create(&thread_id[i], NULL, print_hello, i);
		if (i % 3 == 0) {
			sleep(1);
		}
	}

	return 0;
}
