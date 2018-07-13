//10827 - Maximum sum on a torus
#include <stdio.h>
#include <algorithm>
using namespace std;

int a[200][200];

int lis(int TAM)
{		
	
	int maxi = a[1][1];
	int suma;
	
	for(int i=1; i<=2*TAM; i++)
		for(int j=1; j<=2*TAM; j++)
			a[j][i] += a[j-1][i];
	
	for(int sup = 1; sup<=TAM ;  sup++)
		for(int inf = sup; inf < sup+TAM; inf++ )
			for(int m=1; m<=TAM; m++)
			{
				suma = 0;
				for(int i=m; i<m+TAM; i++)
				{
					suma += a[inf][i] - a[sup-1][i];
					maxi = max(maxi,suma);
					suma = max(0,suma);
				}
			}
			
	return maxi;
}

int main()
{
	int nc, tam;
	
	scanf("%d", &nc);
	
	while(nc--)
	{
		scanf("%d", &tam);
		for(int i=1; i<=tam; i++)
			for(int j=1; j<=tam; j++)
				scanf("%d", &a[i][j]);

		for(int i=1; i<=tam; i++)
			for(int j=tam+1; j<=2*tam; j++)
				a[i][j] = a[i][j-tam];
				
		for(int i=tam+1; i<=2*tam; i++)
			for(int j=1; j<=2*tam; j++)
				a[i][j] = a[i-tam][j];

		printf("%d\n", lis(tam));
		
	}
	return 0;
}
