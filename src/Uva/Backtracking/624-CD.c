/**
 * Problem: CD
 * url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=565
 */

#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b))? (a):(b))
#define MAX 21

int solve(int tape_length, int songs[MAX], int nsongs) {
	int begin = (1 << nsongs) -1;
	int max_total = 0;
	int solution = 0;

	for (int i = begin; i > 0; i--) {
		int total = 0, count = 0, selection = i;

		for( ; selection; selection = selection >> 1, count++) {
			if( selection & 1) {
				total += songs[count];
			}
		}

		if (max_total < total && total <= tape_length) {
			max_total = total;
			solution = i;
		}
		
		if (max_total == tape_length) {
			break;
		}
	}

	for (int count = 0; solution; solution = solution >> 1, count++) {
		if (solution & 1) {
			printf("%d ", songs[count]);
		}
	}

	printf("sum:%d\n", max_total);
}

int main(int argc, char const *argv[]) {
	int tape_length, nsongs;
	int songs[MAX];

	while(scanf("%d", &tape_length) != EOF) {
		scanf("%d", &nsongs);
		for (int i = 0; i < nsongs; i++) {
			scanf("%d", &songs[i]);
		}
		solve(tape_length, songs, nsongs);
	}

	return 0;
}