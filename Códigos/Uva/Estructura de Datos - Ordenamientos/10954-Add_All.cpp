/**
 * Problem: Add All
 * Problem ID: 10954
 * Url: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=1895&mosmsg=Submission+received+with+ID+19561573
 */

#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

int main(int argc, char const *argv[]) {
	int list_size, a, b, cost;

	while(scanf("%d", &list_size), list_size) {
		priority_queue<int> list;
		cost = 0;

		for (int i = 0; i < list_size; i++) {
			scanf("%d", &a);
			list.push(-a);
		}

		while(list.size() > 1) {
			a = list.top();
			list.pop();
			b = list.top();
			list.pop();
			list.push(a+b);
			cost += a+b;
		}

		printf("%d\n", -cost);
	}

	return 0;
}
