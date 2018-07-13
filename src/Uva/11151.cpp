//11151 - Longest Palindrome
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string.h>

#define MAX 1010 

using namespace std;

int dp[MAX][MAX];

char a[MAX], b[MAX];

int l1,l2;

char iquals(char c)
{
	return (c<='Z' && c>='A')? c-'A'+'a': c;
}

int LCS()
{
	for(int i=0; i<=l1; i++) dp[i][0]=0;
	for(int j=0; j<=l2; j++) dp[0][j]=0;
	
	for(int i=1; i<=l1; i++)
		for(int j=1; j<=l2; j++)
			if( a[i-1] == b[j-1] )
				dp[i][j] = dp[i-1][j-1] +1;
			else dp[i][j] = max( dp[i-1][j-1] , max( dp[i-1][j], dp[i][j-1] ) );
			
	return dp[l1][l2];
}

int main()
{
	int nc;
	gets(a);
	sscanf(a,"%d", &nc);
	while(nc--)
	{
		gets(a);
		l1 = strlen(a);
		int k=0;
		
		//for(int i=0; a[i]!='\0'; i++)
			//a[i] = iquals(a[i]);
		
		for(int i=l1-1; i>=0; i--)
			b[k++]=a[i];
		b[l1]='\0';
		l2 = strlen(b);
		//puts(a);
		//puts(b);
		printf("%d\n", LCS());
	}
	return 0;
}
