// 10755 - Garbage Heap
#include <stdio.h>
#include <algorithm>
using namespace std;

long long int a[100][100][100];

long long int max(long long int a, long long int b) {
	return (a>b)? a : b;
}

int main()
{
	int ncases, A,B,C;
	
	scanf("%d", &ncases);

	while(ncases--)
	{
		scanf("%d %d %d", &A, &B, &C);


		for (int i=1; i<=A; i++)
			for (int j=1; j<=B; j++)
				for (int k=1; k<=C ; k++){
					scanf("%lld", &a[i][j][k]);
					a[i][j][k] += a[i-1][j][k] + a[i][j][k-1] - a[i-1][j][k-1];
				}
				
		long long int sum=0;
		long long int maximo = a[1][1][1];
		
		for (int sup=1; sup<=A ; sup++)
			for (int inf=sup; inf<=A ;inf++)
				for (int deepsup=1; deepsup <=C; deepsup++ )
					for (int deepinf = deepsup; deepinf <=C; deepinf++)
					{
						sum = 0;
						for (int i=1; i<=B; i++)
						{
							sum += a[inf][i][deepinf] - a[inf][i][deepsup-1] - a[sup-1][i][deepinf] + a[sup-1][i][deepsup-1];
							maximo = max(maximo,sum);
							sum = max(sum,0);
						}
					}
		
		printf("%lld\n", maximo);
		
		if (ncases)
		{
			puts("");
		}
		
	}
	return 0;
}

