#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp = fopen("/dev/random", "r");
	char buf[20];

	fscanf(fp, "%s", buf);
	
	printf("%s", buf);
	fclose(fp);
	return 0;
}
