#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/resource.h>

#define MB (1024 * 1024) // (Bytes in 1 KB) * (KBs in 1 MB)

int main() {
	char *p;
	struct rusage r;
	for (int i = 0; i < 10; i++) {
		p = (char*)malloc(100 * MB);
		memset(p, 0, 100 * MB);

		if (getrusage(RUSAGE_SELF, &r)) {
			printf("Error occured during getrusage call.\n");
			exit(0);
		} else {
			printf("*---------------------------*\n");
			printf("Max Resident Set Size: %ld\n", r.ru_maxrss);
			printf("Shared Memory Size: %ld\n", r.ru_ixrss);
			printf("Unshared Data Size: %ld\n", r.ru_idrss);
			printf("Unshared Stack Size: %ld\n", r.ru_isrss);
			printf("Page Reclaims: %ld\n", r.ru_minflt);
			printf("Page Faults: %ld\n", r.ru_majflt);
			printf("*---------------------------*\n\n");
		}

		sleep(1);
	}
	return 0;
}
