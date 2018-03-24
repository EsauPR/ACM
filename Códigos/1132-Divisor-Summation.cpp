//1132 - Divisor Summation
#include <stdio.h>
#include <bitset>
#include <vector>
#define MAX 47000
#include <math.h>
using namespace std;

bitset<MAX> criba;
vector<int> primos;


void sieve()
{
	criba.set();
	criba.reset(0);
	criba.reset(1);
	for(int i=2; i<MAX; i++)
		if(criba[i]){
			primos.push_back(i);
			for(int j=i<<1; j<MAX; j+=i)
				criba.reset(j);
		}
}

int sigma(int n)
{
	int sol = 1;
	for(int i=0; i<primos.size() && primos[i]*primos[i] <= n ; i++)
	{
		if(n%primos[i] == 0)
		{
			int ex = 1;
			while(n%primos[i]==0){
				ex++; n/=primos[i];
			}
			sol *= ( pow( primos[i], ex ) - 1) / ( primos[i] - 1 );
		}
	}
	if(n>1)
		sol *= ( pow( n, 2 ) - 1) / ( n - 1 );

	return sol;
}

int main()
{
	sieve();
	int nc,num;
	scanf("%d", &nc);

	while(nc--){
		scanf("%d", &num);
		printf("%d\n",sigma(num)-num);
	}

	return 0;
}

