#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char *argv[]) {
	int i = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;

	printf("i = %d; sizeof(i) = %d;\n", i, (int)sizeof(i));
	printf("f = %f; sizeof(f) = %d;\n", f, (int)sizeof(f));
	printf("d = %f; sizeof(d) = %d;\n", d, (int)sizeof(d));

	return 0;
}
