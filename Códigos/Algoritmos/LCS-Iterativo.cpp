#include <stdio.h>
#include <algorithm>
#define MAX 1000 
#include <string.h>
using namespace std;

int dp[MAX][MAX];

char a[MAX], b[MAX];

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
	scanf("%s %s", a+1, b+1);
	l1 = strlen(a+1);
	l2 = strlen(b+1);
	
	printf("%d\n", LCS());
	return 0;
}
