#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
	DIR *tmp = opendir("tmp");
	struct dirent *cur_ent = readdir(tmp);
	struct stat cur_file;
	char command[128];

	while (cur_ent != NULL) {
		if (cur_ent->d_name[0] != '.') {
			char name[64];
			sprintf(name, "./tmp/%s", cur_ent->d_name);
			stat(name, &cur_file);
			if (cur_file.st_nlink >= 2) {
				sprintf(command, "echo \"\t[%s links]:\" >> ex4.txt", cur_ent->d_name);
				system(command);			

				unsigned long int i = cur_file.st_ino;
				sprintf(command, "find -inum %lu >> ex4.txt", i);
				system(command);
			}
		}
		cur_ent = readdir(tmp);
	}

	return 0;
}
