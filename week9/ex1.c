#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define PAGE_FRAME struct page_frame

PAGE_FRAME {
	int age, page;
};

int main() {
	int N, hits = 0, all = 0;

	printf("Enter the number of page frames: ");
	scanf("%d", &N);

	PAGE_FRAME *pf = calloc(N, sizeof(PAGE_FRAME));
	FILE *fp = fopen("input.txt", "r");
	char c = fgetc(fp);
	int page_num = 0;

	// Main loop
	while (c != EOF) {
		if (c == ' ') /* Space met (number fully read) */ {
			int replace_i = 0, max_age = 0, hit = 0;

			for (int i = 0; i < N; i++) {
				if (pf[i].page == 0) /* Free Page Frame */ {
					max_age = INT_MAX;
					replace_i = i;		
				} else {
					if (pf[i].page == page_num) /* Searched Page found */ {
						hit = 1;						
						hits++;
						pf[i].age = 0;
					} else /* Some other Page */ {
						pf[i].age++;
						if (pf[i].age > max_age) {
							max_age = pf[i].age;
							replace_i = i;
						}
					}
				}
			}

			// Miss -> Replacing oldest page
			// BTW, I use incrementing of age instead of shifting, since re-check happens only once per reference
			if (!hit) {
				pf[replace_i].page = page_num;
				pf[replace_i].age = 0;
			}

			all++;
			hit = 0;
			max_age = 0;
			page_num = 0;
		} else /* Digit met */ {
			page_num *= 10;
			page_num += ((int)c - 48);
		}
		
		c = getc(fp);
	}

	printf("Hit/Miss Ratio = %f\n", ((float)hits/(float)all));

	fclose(fp);
	return 0;
}
