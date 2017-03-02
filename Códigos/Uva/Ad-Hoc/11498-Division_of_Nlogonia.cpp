#include <stdio.h>

void findLocation(int cx, int cy, int x, int y) {
	if (cx == x || cy == y) {
		printf("%s", "divisa");
	}
	else if (x > cx && y > cy) {
		printf("NE");
	}
	else if (x > cx && y < cy) {
		printf("SE");
	}
	else if (x < cx && y > cy) {
		printf("NO");
	}
	else if (x < cx && y < cy) {
		printf("SO");
	}
}

int main()
{
	int k, x, y, cx, cy;
	//bool newLine = false;

	while( scanf("%d", &k), k ) {
		scanf("%d %d", &cx, &cy);

		for (int i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			/*
			if ( newLine ){
				puts("");
			}
			*/
			//newLine = true;
			findLocation(cx, cy, x, y);
			puts("");
		}
	}
}