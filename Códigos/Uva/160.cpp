//160 - Factors and Factorials

#include <stdio.h>
#include <vector>
#include <bitset>
#define MAX 200
using namespace std;

vector<int> primos;
bitset< MAX > criba;
vector<int> sol;

void fullcriba()
{
	int i,j;
	criba.set();
	criba.reset(0);
	criba.reset(1);
	for(i=2; i<MAX; i++)
		if(criba[i])
		{
			primos.push_back(i);
			for(j=i<<1; j<MAX; j+=i)
				criba.reset(j);
		}
}

void solve(int n)
{
	sol.clear();
	int tmp, cont;
	for(int i=0; primos[i]<=n; i++)
	{
		tmp=n;
		cont=0;
		while(tmp)
		{
			cont += tmp/primos[i];
			tmp /= primos[i];
		}
		sol.push_back(cont);
	}
}

int main()
{

	int n;
	fullcriba();
	while(scanf("%d", &n),n)
	{
		solve(n);
		printf("%3d! =", n);
		for(int i=0; i<sol.size(); i++)
		{
			if( i!=0 && i%15 == 0) printf("\n      ");
			printf("%3d", sol[i]);
		}
		puts("");
	}
	
	return 0;
}
