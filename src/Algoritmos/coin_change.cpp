/**
	Given a value N, if we want to make change for N cents,
	and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, 
	how many ways can we make the change? The order of coins doesn’t matter.

	For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
	So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: 
	{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 
	So the output should be 5.

	UVA 357 - Let Me Count The Ways
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