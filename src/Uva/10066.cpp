//10066 - The Twin Towers
#include <stdio.h>
#include <algorithm>
#define MAX 109 
#include <string.h>
using namespace std;

int dp[MAX][MAX];

int a[MAX], b[MAX];

int l1,l2;

int LCS()
{
	for(int i=0; i<=l1; i++) dp[i][0]=0;
	for(int j=0; j<=l2; j++) dp[0][j]=0;
	
	for(int i=1; i<=l1; i++)
		for(int j=1; j<=l2; j++)
			if( a[i] == b[j] )
				dp[i][j] = dp[i-1][j-1] +1;
			else dp[i][j] = max( dp[i-1][j-1] , max( dp[i-1][j], dp[i][j-1] ) );
			
	return dp[l1][l2];
}

int main()
{	
	int cont=1;
	while(scanf("%d %d", &l1, &l2),l1,l2)
	{
		
		for(int i=1; i<=l1; i++)
			scanf("%d", &a[i]);
		for(int i=1; i<=l2; i++)
			scanf("%d", &b[i]);
			
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", cont++,LCS());
		
	}
	return 0;
}
