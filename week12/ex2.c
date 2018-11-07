#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_SIZE 128

void write_str(int, char*, int);

int main(int argc, char* argv[]) {
	char buf[MAX_SIZE];

	int a_key = (argc > 1) && (argv[1][0] == '-') ? 1 : 0;
	int *fd = (int*)malloc((argc - a_key - 1) * sizeof(int));
	for (int i = 0; i < argc - a_key - 1; i++) {
		fd[i] = a_key ?
			open(argv[i + 2], O_CREAT | O_WRONLY | O_APPEND, S_IRWXU) :
			open(argv[i + 1], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	}
	
	read(0, buf, MAX_SIZE);
	printf("%s", buf);
	for (int i = 0; i < argc - a_key - 1; i++) {
		write_str(fd[i], buf, MAX_SIZE);
		close(fd[i]);
	}

	return 0;
}

void write_str(int fd, char* str, int max) {
	for (int i = 0; i < max; i++) {
		if (str[i] == '\0') { break; }
		write(fd, (str + i), 1);
	}
}
