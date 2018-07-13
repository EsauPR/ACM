/**
	357 - Let Me Count The Ways
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 30005

using namespace std;

long long int DP[7][MAX];

void coinChange(int S[], int m, int n) {

	DP[0][0] = 1LL;

	for (int i = 1; i < m; ++i) {
		for (int j = 0; j <= n; j++) {

			DP[i][j] = DP[i-1][j];
			
			if ( j >= S[i] ) {
				DP[i][j] += DP[i][j-S[i]];
			}
			
		}
	}
}

int main(int argc, char const *argv[])
{
	int n, m = 6;
	int S[] = {0, 1, 5, 10, 25, 50};
	coinChange(S, m, 30000);

	while(scanf("%d", &n) != EOF) {
		if (DP[m-1][n] == 1) {
			printf("There is only 1 way to produce %d cents change.\n", n);
		}
		else {
			printf("There are %lld ways to produce %d cents change.\n", DP[m-1][n], n );
		}		
	}

	return 0;
}