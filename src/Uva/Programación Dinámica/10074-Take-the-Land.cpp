//10074 - Take the Land
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int M,N;
int dp[102][102];

void solve()
{
	M++;
	for(int i=1; i<M; i++)
		for(int j=0; j<N; j++)
			dp[i][j] += dp[i-1][j];
	
	int suma, maxi=0;
	for(int sup = 1; sup < M; sup++)
		for(int inf = sup; inf < M; inf ++)
		{
			for(int i=0; i<N; i++)
			{
				suma=0;
				for(int j=i; j<N; j++)
				{
					suma += dp[inf][j] - dp[sup-1][j];
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
	while(scanf("%d %d", &M,&N), M && N)
	{
		for(int i=1; i<=M; i++)
			for(int j=0; j<N; j++)
			{
				scanf("%d", &dp[i][j]);
				dp[i][j] = (dp[i][j] == 1)? 0:1;
			}
		solve();
	}

	return 0;
}
