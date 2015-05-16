//369 - Combinations
#include <stdio.h>
#include <vector>
#include <bitset>
#include <map>
#define MAXPRIME 10009

using namespace std;

bitset < MAXPRIME > criba;
vector < int > primos;
map<int,int> mapa;

void fullcriba(){
	int i, j;
	criba.set();
	criba.reset(0);
	criba.reset(1);
	for (i=2;i<MAXPRIME;i++){
		if (criba.test(i)){
			primos.push_back(i);
			for (j=2*i;j<MAXPRIME;j+=i)
				criba.reset(j);
		}
	}
}

void factores(int n)
{
	for(int i=0; primos[i]<=n; i++)
	{
		int res=n;
		while(res)
		{
			mapa[primos[i]]-=res/primos[i];
			res/=primos[i];
		}
	}
}

long long int solve(int n, int m)
{
	mapa.clear();
	for(int i=0; primos[i]<=n; i++)
	{
		int res=n;
		while(res)
		{
			mapa[primos[i]]+=res/primos[i];
			res/=primos[i];
		}
	}
	factores(n-m);
	factores(m);
	map<int, int>:: iterator it;
	long long int sol=1;
	for(it=mapa.begin(); it!=mapa.end(); it++)
		for(int j=0; j<(it->second); j++)
			sol*=(it->first);
	return sol;	
}

int main()
{
	int n,m;
	fullcriba();
	while(scanf("%d %d", &n, &m),n,m)
	{
		printf("%d things taken %d at a time is %lld exactly.\n",n,m,solve(n,m));
	}
	return 0;
}
