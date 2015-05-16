//10617 Again Palindromes
#include<stdio.h>
#include <string.h>


char  s[100];
long long int dp[100][100];

void rei()
{
	for(int i=0; i < 100; i++)
		for(int j=0 ; j<100 ; j++)
			dp[i][j]=-1;
}

long long int palin(int l,int r)
{
	if(l>r) return dp[l][r]=1;
	if( dp[l][r] != -1) return dp[l][r];
	if( s[l] == s[r] )
	{
		dp[l+1][r] = palin(l+1,r); dp[l][r-1] = palin(l, r-1);
		return dp[l+1][r] + dp[l][r-1];
	}
	
	dp[l+1][r] = palin(l+1,r); dp[l][r-1] = palin(l, r-1); dp[l+1][r-1] = palin(l+1, r-1);
	return dp[l+1][r] + dp[l][r-1] - dp[l+1][r-1];
}

int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s",s);
		//puts(s);
		rei();
		printf("%lld\n", palin( 0, strlen(s)-1 ) - 1 );
	}
	return 0;
}