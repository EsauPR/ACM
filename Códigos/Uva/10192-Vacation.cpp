//10192 Vacation
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

char s1[10000];
char s2[10000];

int dp[10000][10000];

int l1,l2;

int LCS()
{
	for(int i=1; i<=l1; i++)
		for(int j=1; j<=l2; j++)
			if(s1[i-1]==s2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max( dp[i][j-1], max( dp[i-1][j], dp[i-1][j-1] ) );
	return dp[l1][l2];
}

void print()
{
	for(int i=1; i<=l1; i++)
	{
		for(int j=1; j<=l2; j++)
			printf("%4d", dp[i][j]);
		puts("");
	}
}

int main()
{
	int nc=1;
	while(1)
	{
		gets(s1); gets(s2);
		if( s1[0] == '#' ) break;
		if(feof(stdin)) break;
		l1 = strlen(s1) ;
		l2 = strlen(s2) ;
		printf("Case #%d: you can visit at most %d cities.\n",nc++, LCS());
		//print();
	}
	return 0;
}