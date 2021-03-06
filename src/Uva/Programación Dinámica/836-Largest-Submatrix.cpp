//836 - Largest Submatrix
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int M,N;
char dp[102][102];
int dp1[102][102];

void solve()
{
	M--;
	for(int i=1; i<M; i++)
		for(int j=0; j<N; j++)
		{
			dp1[i][j] = 0;
			dp1[i][j] += dp1[i-1][j] + dp[i][j]-'0';
		}
	
	int suma, maxi=0;
	for(int sup = 1; sup < M; sup++)
		for(int inf = sup; inf < M; inf ++)
		{
			for(int i=0; i<N; i++)
			{
				suma=0;
				for(int j=i; j<N; j++)
				{
					suma += dp1[inf][j] - dp1[sup-1][j];
					if(suma == (inf-sup+1)*(j-i+1) )
						maxi = max(suma,maxi);
					else break;
				}
			}
		}
	printf("%d\n", maxi);
}

int main()
{
	int n;
	scanf("%d\n", &n);
	while(n--)
	{
		M = 1;
		while(gets(dp[M]), dp[M++][0]!='\0' && !feof(stdin));
		N = strlen(dp[1]);
		if(N) solve();
		if(n) puts("");
	}

	return 0;
}
