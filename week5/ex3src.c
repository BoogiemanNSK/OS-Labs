#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define THREADS_NUM 2

int produce_flag, consume_flag, item_count;
char buffer[BUFFER_SIZE];
pthread_t thread_id[THREADS_NUM];

void* produce() {
	while(1) {
		char item = rand() % 256;

		if (item_count >= BUFFER_SIZE) {
			produce_flag = 0;
		}

		if (produce_flag) {
			buffer[item_count] = item;
			item_count++;
		}

		if (item_count > 0) {
			consume_flag = 1;
		}
	}
}

void* consume() {
	while(1) {
		if (item_count <= 0) {
			consume_flag = 0;
		}

		if (consume_flag) {
			buffer[item_count] = '-';
			item_count--;
		}

		if (item_count < BUFFER_SIZE) {
			produce_flag = 1;
		}
	}
}

int main() {
	srand(time(NULL));
	item_count = 0;
	produce_flag = 1;
	consume_flag = 1;

	pthread_create(&thread_id[0], NULL, produce, NULL);
	pthread_create(&thread_id[1], NULL, consume, NULL);

	printf("Hi.\n");

	while (1) {
		sleep(3);
		printf("Item count = %d; Last item = %c;\n", item_count, buffer[item_count]);
	}
	
	return 0;
}
