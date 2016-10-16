#include <stdio.h>

void findLocation(cx, cy, x, y) {
	if (cx == x || cy == y) {
		printf("%s", "divisa");
	}
	else if (x > cx && y > cy) {
		printf("%s", "NE");
	}
	else if (x > cx && y < cy) {
		printf("%s", "SE");
	}
	else if (x < cx && y > cy) {
		printf("%s", "NO");
	}
	else if (x < cx && y < cy) {
		printf("%s", "SO");
	}
}

int main()
{
	int k, x, y, cx,cy, st;

	while( scanf("%d", &k), k ) {
		scanf("%d %d", &cx, &xy);

		for (int i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);

			findLocation(cx, cy, x, y);
		}
	}
}