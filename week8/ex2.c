#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

#define MB (1024 * 1024) // (Bytes in 1 KB) * (KBs in 1 MB)

int main() {
	char *p;
	for (int i = 0; i < 10; i++) {
		p = (char*)malloc(100 * MB);
		memset(p, 0, 100 * MB);
		sleep(1);
	}
	return 0;
}
