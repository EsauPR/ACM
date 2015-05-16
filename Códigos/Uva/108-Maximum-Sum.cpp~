//108 - Maximum Sum
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[105][105];

int main()
{
	int n;
	
	while(scanf("%d", &n)!=EOF)
	{
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				scanf("%d", &a[i][j]);
		
			
		for(int j=1; j<=n; j++)
			for(int i=1; i<=n; i++)
				a[i][j] += a[i-1][j];

				
		int sum=0;
		int maximo = a[1][1];
		
		for(int sup=1; sup<=n ; sup++)
			for(int inf=sup; inf<=n ;inf++)
			{
				sum = 0;
				for(int i=1; i<=n; i++)
				{
					sum += a[inf][i] - a[sup-1][i];
					maximo = max(maximo,sum);
					sum = max(sum,0);
				}
			}	 
		printf("%d\n", maximo);
	}
	return 0;
}

