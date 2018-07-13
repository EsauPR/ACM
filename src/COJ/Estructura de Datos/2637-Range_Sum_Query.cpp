/**
 * Problem: Range Sum Query
 * Problem ID: 2637
 * url: http://coj.uci.cu/24h/problem.xhtml?pid=2637
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100002

int main(int argc, char const *argv[]) {
	long long int list[MAX];
	int ncases, n, q, i, j, num;
	list[0] = 0;

	scanf("%d", &ncases);

	while(ncases--) {
		scanf("%d %d", &n, &q);
		for(int k = 1; k <=n; k++) {
			scanf("%d", &num);
			list[k] = list[k-1] + num;
		}

		while(q--) {
			scanf("%d %d", &i, &j);
			if (i>j) {
				puts("0");
			} else {
				printf("%lld\n", list[j+1] - list[i]);
			}
		}

		if (ncases) puts("");
	}
	return 0;
}
