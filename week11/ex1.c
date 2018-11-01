#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>

#define SIZE 32
#define PATH "ex1.txt"

int main() {
	char buf[SIZE] = "This is a nice day\n";
	int fd = open(PATH, O_RDWR);
	lseek(fd, SIZE - 1, SEEK_SET);
	write(fd, "", 1);

	char *f = (char*)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	for (int i = 0; i < SIZE; i++) {
		f[i] = buf[i];
	}

	munmap(f, SIZE);
	close(fd);
	return 0;
}
