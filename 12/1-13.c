#include <stdio.h>
#include <string.h>

#define IN 1    /* in word */
#define OUT 0   /* out word */
#define MAXWORD 10 /* max size of word - 1 */

int main() {
	int c, tmp = 0, state = OUT, max = 0;
	int i, j;
	int count[MAXWORD];
	memset(count, 0, sizeof(count));

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {
				++count[tmp];
				tmp = 0;
			}
			state = OUT;
		}
		else {
			state = IN;
			++tmp;
		}
	}

	//绘制垂直方向直方图
	for (i = 0; i < MAXWORD; ++i) {
		if (count[i] > max)
			max = count[i];
	}
	for (i = 0; i < max; ++i) {
		for (j = 0; j < MAXWORD; ++j) {
			if ((max - count[j]) <= i)
				printf("-");
			else 
				printf(" ");
			printf(" ");
		}
		printf("\n");
	}
	for (i = 0; i < MAXWORD; ++i) {
		printf("%d", i);
		printf(" ");
	}
	printf("\n");

	//绘制水平方向直方图
	/*for (i = 0; i < MAXWORD; ++i) {
		printf("%d: ", i);
		for (j = 0; j < count[i]; j++) {
			printf("|");
		}
		printf("\n");
	}*/
	return 0;
}
