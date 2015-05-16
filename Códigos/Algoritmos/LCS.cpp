#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MAX 100
using namespace std;

int dp[MAX][MAX];

char A[MAX], B[MAX];

int LCS(int i, int j)
{
	
	if( dp[i][j] != -1)
		return dp[i][j];
	
	if(i==0 || j==0)
		return dp[i][j]=0;
	
	else if(A[i] == B[j])
		return dp[i][j] = 1 + LCS(i-1,j-1);
		
	return dp[i][j] = max( LCS(i-1,j-1), max( LCS(i,j-1), LCS(i-1,j) ) );
}

int main(){
	
	int n = strlen( gets(A+1) );
	int m = strlen( gets(B+1) );
	
	memset(dp,-1, sizeof(dp));
	
	printf("%d\n", LCS(n,m) );
	
	return 0;
}
