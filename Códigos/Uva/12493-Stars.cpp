//12493 - Stars

#include <stdio.h>
#define MAX 47000
#include <bitset>
#include <vector>
using namespace std;

bitset<MAX> criba;
vector<int> primos;
vector<int> fact;

void sieve()
{
	criba.set();
	criba.reset(0); criba.reset(1);
	
	for(int i=2; i<MAX; i++)
		if(criba[i])
		{
			primos.push_back(i);
			for(int j=i<<1; j<MAX; j+=i)
				criba.reset(j);
		}
}

int solve(int n)
{
	fact.clear();
	int num = n;
	for(int i=0; i<primos.size() && primos[i]*primos[i]<=num; i++)
		if(num%primos[i]==0){
			fact.push_back(primos[i]);
			while( num%primos[i]==0 ) 
				num/=primos[i];
		}
	if(num>1)
		fact.push_back(num);
	
	long long int a=1, b=1;
	/*
		puts("---");
	for(int i=0; i<fact.size(); i++)
		printf("%d ", fact[i]);
	puts("\n---");
	*/
	for(int i=0; i<fact.size(); i++){
		a *= (long long int) fact[i]-1;
		b *= (long long int) fact[i];
	}
	return n*a/b;
}


int main()
{
	sieve();
	int num;
	
	while(scanf("%d", &num)!=EOF)
		printf("%d\n",solve(num)/2);
	
	
	return 0;
}
