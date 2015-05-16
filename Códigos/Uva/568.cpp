//568 - Just the Facts
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

int lastDig(int n, int mod)
{
	for(int i=0; primos[i]<=n; i++)
	{
		int res=n;
		while(res)
		{
			mapa[primos[i]]+=res/primos[i];
			res/=primos[i];
		}
	}
	mapa[2]-=mapa[5];
	mapa[5]=0;
	int solve=1;
	for(int i=0; primos[i]<=n; i++)
		if(mapa[primos[i]])
		{
			for(int j=0; j<mapa[primos[i]]; j++)
				solve= (solve*primos[i])%mod;
		}
	return solve;
}

int main()
{
	int n;
	fullcriba();
	while(scanf("%d", &n)!=EOF)
	{
		mapa.clear();	
		printf("%5d -> %d\n", n,lastDig(n,10));
	}
	return 0;
}
