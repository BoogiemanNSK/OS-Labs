#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREADS_NUM 10

pthread_t thread_id[THREADS_NUM];

void* print_hello(void* i) {
	int it = *(int*)(i);
	printf("Hello from thread %d on iteration %d!\n", (int)thread_id[it], it);
	pthread_exit(NULL);
}

int main() {
	for (int i = 0; i < THREADS_NUM; i++) {
		pthread_create(&thread_id[i], NULL, print_hello, &i);
		pthread_join(thread_id[i], NULL);
	}
	return 0;
}
