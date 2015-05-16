#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int vec[100];

int gcd(int a, int b){
	return (a%b==0)? b:gcd(b,a%b);
}

int main()
{
	int a, b,n;
	long long int tpar,par;
	while(scanf("%d", &n),n)
	{
		par=0;
		tpar = (long long int)((n-1)*(n))/2;
		//printf("TPAR == %lld\n", tpar);
		for(int i=0; i<n; i++)
		{	
			scanf("%d", &a);
			vec[i]=a;
		}
		for(int i=0; i<n-1; i++)
			for(int j=i+1; j<n; j++)
				if(__gcd(vec[i], vec[j]) == 1)
				{
						par++;
	//					printf("GCD %d %d\n", vec[i], vec[j]);
				}
	//	printf("PAR == %lld\n", par);
		tpar*=6;
		if(par==0)
			puts("No estimate for this data set.");
		else
		{
			double sol = (double) tpar/par;
			printf("%.6lf\n", sqrt( sol  ) );
		}
	}
	return  0;
}
